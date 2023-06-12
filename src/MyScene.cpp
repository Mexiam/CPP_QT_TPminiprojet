#include <iostream>
#include "MyScene.h"

MyScene::MyScene(QObject* parent) : QGraphicsScene(parent) {
    this->addItem(item);
    this->addItem(qgri);
    this->addItem(qgti);
    this->addItem(mainSpaceShip);
    this->addItem(counter);
    this->addItem(explosion);
    this->addItem(shield);
    qDeleteAll(listeEnnemy);
    listeEnnemy.clear();
    createEnemy();

    qreal scaleRatio = 0.15;
    this->mainSpaceShip->setScale(scaleRatio);

    this->view->setWindowTitle("SpaceShip view");
    this->view->resize(600, 800);
    this->view->centerOn(300, 1500);
    this->view->show();

    this->addWidget(starterPage);

    starterPage->resize(200, 300);
    starterPage->move(200, 1400);
    starterPage->show();

    connect(starterPage, SIGNAL(start(QString)), this, SLOT(startGame(QString)));

    // Timers connection done only once at init to prevent multiple call to update functions
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    connect(timerEnnemy, SIGNAL(timeout()), this, SLOT(updateEnnemy()));
    //connect(timerMissile, SIGNAL(timeout()), this, SLOT(updateMissile()));
    shield->setPos(7000, 7000);

    couldown = QTime::currentTime();


    //SON INCOMPATIBLE AVEC LA WSL
//    soundBG->setAudioOutput(soundOutput);
//    soundBG->setSource(QUrl("qrc:/assets/music/musicBG.mp3"));
//    soundOutput->setVolume(0.2);
//    soundBG->setLoops(QMediaPlayer::Infinite);
//    soundBG->play();
}

void MyScene::update() {
    QPointF posSpaceship = mainSpaceShip->pos(); //récupération de la position de l’objet qgti
    mainSpaceShip->setPos(posSpaceship.rx(), posSpaceship.ry()-5); //incrémentation de la coordonnée y
    QPointF posScore = counter->pos();

    counter->setPos(posScore.rx(), posScore.ry() - 5);


    this->score = score +7;

    counter->setPlainText("Score : " + QString::number(score));

    QList<QGraphicsItem*> collidingItems = mainSpaceShip->collidingItems();
    foreach(QGraphicsItem* item, collidingItems){
        if(dynamic_cast<Ennemy*>(item)) {
            QPointF pos = mainSpaceShip->pos();
            explosion->setPos(pos.rx(),pos.ry());
            movie->start();
            death();
            timer->stop();

        }
    }

    QList<QGraphicsItem*> collidingShield = shield->collidingItems();
            foreach(QGraphicsItem* item, collidingShield){
            Ennemy* ennemy = dynamic_cast<Ennemy*>(item);
            if(dynamic_cast<Ennemy*>(item)) {
                qreal scaleRatio = 0;
                this->shield->setScale(scaleRatio);
                ennemy->setPos(10000, 10000); // c'est moche
            }
        }

    this->view->centerOn(posSpaceship.rx()+30, posSpaceship.ry()-200);

    QPointF itemPos = mainSpaceShip->pos();
    if(itemPos.y()<=200){
        newLevel();
    }
    if(powerups>=2){
        shield->setPos(posSpaceship.rx()-200, posSpaceship.ry()-250);
    }

}


void MyScene::updateEnnemy() {

    for(int i=0; i<=listeEnnemy.size()-1; i = i+2){
        QPointF pos = listeEnnemy[i]->pos();
        QPointF posSpaceship = mainSpaceShip->pos();
        if(pos.rx()>posSpaceship.rx()){
            listeEnnemy[i]->setPos(pos.rx()-1, pos.ry()+2);
        } else{
            listeEnnemy[i]->setPos(pos.rx()+1, pos.ry()+2);
        }
                if(listeEnnemy[i]->collidesWithItem(mainSpaceShip)) {
                    timerEnnemy->stop();
                }
    }
    for(int i=1; i<=listeEnnemy.size()-2; i = i+2){
        QPointF pos = listeEnnemy[i]->pos();
        int randomX = QRandomGenerator::global()->bounded(-5, 5);
        int randomY = QRandomGenerator::global()->bounded(-5, 5);
        listeEnnemy[i]->setPos(pos.rx() + randomX, pos.ry() + randomY);
        if(listeEnnemy[i]->collidesWithItem(mainSpaceShip)) {
            timerEnnemy->stop();
        }
    }

}





MyScene::~MyScene() {

}

void MyScene::keyPressEvent(QKeyEvent* event){
    if(event->key() == Qt::Key_D) { // appui sur la touche D du clavier
        QPointF pos = mainSpaceShip->pos();
        if(pos.rx()<590) {
            mainSpaceShip->setPos(pos.rx() + 3, pos.ry());

            QPointF posScore = counter->pos();
            counter->setPos(posScore.rx() + 3, posScore.ry());
        }
    }
    if(event->key() == Qt::Key_Q) { // appui sur la touche Q du clavier
        QPointF pos = mainSpaceShip->pos();
        if(pos.rx()>200) {
            mainSpaceShip->setPos(pos.rx() - 3, pos.ry());

            QPointF posScore = counter->pos();
            counter->setPos(posScore.rx() - 3, posScore.ry());
        }
    }

    if(event->key() == Qt::Key_S) { // appui sur la touche S du clavier
        if(QTime::currentTime() > couldown && powerups >= 1) {
            this->couldown = QTime::currentTime().addSecs(2);
            QPointF pos = mainSpaceShip->pos();

            Missile *newMissile = new Missile(pos.rx() + 10, pos.ry() - 30);
            this->addItem(newMissile);
        }
    }
    QGraphicsScene::keyPressEvent(event);
}


void MyScene::createEnemy() {
    for(int i = 0; i<=count; i++){
        int randomX = QRandomGenerator::global()->bounded(100, 600);
        int randomY = QRandomGenerator::global()->bounded(500, 3500);

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
            spaceshipEnnemy = ":/assets/img/3_Red.png";
            break;
        case 2:
            spaceshipEnnemy = ":/assets/img/5_Red.png";
            break;
        case 3:
            spaceshipEnnemy = ":/assets/img/6_Red.png";
            break;
        case 4:
            spaceshipEnnemy = ":/assets/img/9_Red.png";
            break;
        case 5:
            spaceshipEnnemy = ":/assets/img/10_Red.png";
            break;
        default:
            spaceshipEnnemy = ":/assets/img/3_Red.png";
            break;
    };
    return spaceshipEnnemy;
}

void MyScene::death() {
    powerups = 0;
    count = 15;
    qDeleteAll(listeEnnemy);
    listeEnnemy.clear();
    QList<QObject *> children = deathWidget->children();

    foreach (QObject *child, children) {
        child->deleteLater();
    }


    QLabel* deathMessage = new QLabel("Game Over!");
    QLabel* previousScore = new QLabel("Your score is: ");
    QLabel* scoreLabel = new QLabel(QString::number(score));

    QVBoxLayout* layout = new QVBoxLayout;

    layout->addWidget(deathMessage);
    layout->addWidget(previousScore);
    layout->addWidget(scoreLabel);

    QHBoxLayout* buttonLayout = new QHBoxLayout();
    QPushButton* restart = new QPushButton("Restart");
    QPushButton* home = new QPushButton("Home");

    buttonLayout->addWidget(restart);
    buttonLayout->addWidget(home);

    connect(restart, SIGNAL(pressed()), this, SLOT(restartGame()));
    connect(home, SIGNAL(pressed()), this, SLOT(showHome()));

    this->addWidget(deathWidget);

    layout->addLayout(buttonLayout);

    restart->setStyleSheet("background-color: black; color: white; font-size: 16px;");
    home->setStyleSheet("background-color: black; color: white; font-size: 16px;");
    layout->setAlignment(Qt::AlignCenter);

    deathWidget->resize(400, 500);
    QPointF pos = mainSpaceShip->pos();
    deathWidget->move(pos.rx()-175, pos.ry()-400);
    QFont font("Tahoma ", 12, QFont::Bold);
    deathMessage->setFont(font);
    previousScore->setFont(font);
    scoreLabel->setFont(font);

    deathWidget->setLayout(layout);
    deathWidget->show();

    QFile file("scores.csv");
    if (!file.exists()) {
        qDebug() << "Fichier CSV inexistant.";
    }
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        qDebug() << "Fichier CSV des scores inaccessible.";
        qDebug() << file.errorString();
        qDebug() << file.error();
    } else {
        QDate currentDate = QDate::currentDate();
        int day = currentDate.day();
        int month = currentDate.month();
        int year = currentDate.year();
        QStringList dateStringsList;
        dateStringsList << QString::number(day) << QString::number(month) << QString::number(year);
        QTextStream scoresFile(&file);
        QStringList newScore;
        newScore << *playerName << QString::number(score) << dateStringsList.join("/");
        scoresFile << newScore.join(";") << "\n"; // Ecrit dans le fichier
        file.close();
    }
    starterPage->scores->readCSV("scores.csv");
}

void MyScene::startGame(QString name) {
    count = 15;
    powerups = 0;
    *playerName = name;
    starterPage->hide();
    playGame();
}

void MyScene::restartGame() {
    powerups = 0;
    deathWidget->hide();
    QList<QObject *> children = deathWidget->children();
    foreach (QObject *child, children) {
        child->deleteLater();
    }
    playGame();
}

void MyScene::playGame(int startScore) {
    qDebug() << startScore;
    qDebug() << *playerName;
    score = startScore;
    this->counter->setDefaultTextColor(QColor(Qt::white));
    this->mainSpaceShip->setPos(500, 3900);
    this->counter->setPos(625, 3700);
    timer->start(30);
    timerEnnemy->start(30);

    qDeleteAll(listeEnnemy);
    listeEnnemy.clear();
    createEnemy();
}

void MyScene::showHome(){
    deathWidget->hide();
    QList<QObject*> children = deathWidget->children();

    foreach (QObject *child, children) {
        child->deleteLater();
    }

    starterPage->show();
    QPointF pos = mainSpaceShip->pos();
    starterPage->move(pos.rx()-175, pos.ry()-400);
}

void MyScene::newLevel(){
    powerups += 1;
    if(powerups>=2){
        qreal scaleRatio = 1;
        this->shield->setScale(scaleRatio);
    }
    timer->stop();
    timerEnnemy->stop();
    QPointF itemPos = mainSpaceShip->pos();
    this->mainSpaceShip->setPos(itemPos.x(), 3900);
    QPointF posScore = counter->pos();
    this->counter->setPos(posScore.rx(), 3700);
    count = count + 10;
    qDebug() << count;
    playGame(score);
}