#include <iostream>
#include "MyScene.h"

MyScene::MyScene(QObject* parent) : QGraphicsScene(parent) {
    //timer->stop();
    //startGame();
    this->addItem(item);
    this->addItem(qgri);
    this->addItem(qgti);
    this->addItem(mainSpaceShip);
    this->addItem(counter);
    this->addItem(explosion);
    createEnemy();

    //this->addItem(ennemy1);
    //this->ennemy1->setPos(400, 2000);
    qreal scaleRatio = 0.15;
    this->mainSpaceShip->setScale(scaleRatio);
    //this->ennemy1->setScale(scaleRatio);

    this->view->setWindowTitle("SpaceShip view");
    this->view ->resize(600, 800);
    this->view->show();

    this->counter->setDefaultTextColor(QColor(Qt::white));
    this->counter->setPos(625, 3700);


    this->mainSpaceShip->setPos(500, 3900);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(30); //toutes les 30 millisecondes


}

void MyScene::update() {
    QPointF posSpaceship = mainSpaceShip->pos(); //récupération de la position de l’objet qgti
    mainSpaceShip->setPos(posSpaceship.rx(), posSpaceship.ry()-5); //incrémentation de la coordonnée y
    QPointF posScore = counter->pos();

    counter->setPos(posScore.rx(), posScore.ry() - 5);

    this->score = score +7;
    //qDebug()<<score;

    counter->setPlainText("Score : " + QString::number(score));



    QList<QGraphicsItem*> collidingItems = mainSpaceShip->collidingItems();
    foreach(QGraphicsItem* item, collidingItems){
        if(dynamic_cast<Ennemy*>(item)) {
            qDebug() << "Collision !";
            QPointF pos = mainSpaceShip->pos();
            explosion->setPos(pos.rx(),pos.ry());
            movie->start();
            death();
            timer->stop();

        }
    }


    this->view->centerOn(posSpaceship.rx()+30, posSpaceship.ry()-200);

    QPointF itemPos = mainSpaceShip->pos();
    if(itemPos.y()<=200){
        this->mainSpaceShip->setPos(itemPos.x(), 3900);
        QPointF posScore = counter->pos();
        this->counter->setPos(posScore.rx(), 3700);
        //timer->stop();
        qDeleteAll(listeEnnemy);
        listeEnnemy.clear();
        createEnemy();
        count = count+3;
        std::cout<<count;
    }

}


MyScene::~MyScene() {

}

void MyScene::keyPressEvent(QKeyEvent* event){
    if(event->key() == Qt::Key_D) { // appui sur la touche D du clavier
        QPointF pos = mainSpaceShip->pos();
        mainSpaceShip->setPos(pos.rx()+1, pos.ry());

        QPointF posScore = counter->pos();
        counter->setPos(posScore.rx()+1, posScore.ry());
    }
    if(event->key() == Qt::Key_Q) { // appui sur la touche G du clavier
        QPointF pos = mainSpaceShip->pos();
        mainSpaceShip->setPos(pos.rx()-1, pos.ry());

        QPointF posScore = counter->pos();
        counter->setPos(posScore.rx()-1, posScore.ry());
    }
}


void MyScene::createEnemy() {
    for(int i = 0; i<=count; i++){
        int randomX = QRandomGenerator::global()->bounded(100, 600);
        int randomY = QRandomGenerator::global()->bounded(500, 4000);

        QString spaceshipEnnemy= getRandomSpaceship();
        Ennemy* itemEnnemy = new Ennemy(spaceshipEnnemy, randomX, randomY);
        this->addItem(itemEnnemy);
        listeEnnemy.append(itemEnnemy);
    }
}

QString MyScene::getRandomSpaceship() {
    QString spaceshipEnnemy= "";
    int randomSpaceShip = QRandomGenerator::global()->bounded(1,5);
    switch (randomSpaceShip) {
        case 1:
            spaceshipEnnemy = "3_Red.png";
            break;
        case 2:
            spaceshipEnnemy = "5_Red.png";
            break;
        case 3:
            spaceshipEnnemy = "6_Red.png";
            break;
        case 4:
            spaceshipEnnemy = "9_Red.png";
            break;
        case 5:
            spaceshipEnnemy = "10_Red.png";
            break;
        default:
            spaceshipEnnemy = "3_Red.png";
            break;
    };
    return spaceshipEnnemy;
}

void MyScene::death() {
    deathWidjet = new QWidget;
    QLabel* deathMessage = new QLabel("Game Over!");
    QLabel* previousScore = new QLabel("Your score is: ");
    QLabel* scoreLabel = new QLabel(QString::number(score));



    connect(restart, SIGNAL(pressed()), this, SLOT(restartGame()));


    layout->addWidget(deathMessage);
    layout->addWidget(previousScore);
    layout->addWidget(scoreLabel);

    buttonLayout->addWidget(restart);
    buttonLayout->addWidget(home);
    this->addWidget(deathWidjet);

    layout->addLayout(buttonLayout);

    restart->setStyleSheet("background-color: black; color: white; font-size: 16px;");
    home->setStyleSheet("background-color: black; color: white; font-size: 16px;");
    layout->setAlignment(Qt::AlignCenter);

    deathWidjet->resize(400, 500);
    QPointF pos = mainSpaceShip->pos();
    deathWidjet->move(pos.rx()-175, pos.ry()-400);
    QFont font("Tahoma ", 12, QFont::Bold);
    deathMessage->setFont(font);
    previousScore->setFont(font);
    scoreLabel->setFont(font);

    deathWidjet->setLayout(layout);
    deathWidjet->show();
}

void MyScene::restartGame() {
    score = 0;
    this->mainSpaceShip->setPos(500, 3900);
    this->counter->setPos(625, 3700);
    timer->start();
    deathWidjet->hide();
    qDeleteAll(listeEnnemy);
    listeEnnemy.clear();
    createEnemy();
}


void MyScene::startGame() {
    startWidjet = new QWidget;
    QLabel* name = new QLabel("SPACESHIP RUSH");




    buttonLayout->addWidget(play);
    connect(play, SIGNAL(pressed()), this, SLOT(restartGame()));
    this->addWidget(startWidjet);

    layoutStart->addLayout(buttonLayout);
    layoutStart->addWidget(name);

    layoutStart->setAlignment(Qt::AlignCenter);

    startWidjet->resize(400, 500);
    QPointF pos = mainSpaceShip->pos();
    startWidjet->move(pos.rx()-175, pos.ry()-400);
    QFont font("Tahoma ", 12, QFont::Bold);
    name->setFont(font);


    startWidjet->setLayout(layout);
    startWidjet->show();
}