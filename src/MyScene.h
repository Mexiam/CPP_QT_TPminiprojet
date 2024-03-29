#ifndef CPP_QT_TPMINIPROJET_MYSCENE_H
#define CPP_QT_TPMINIPROJET_MYSCENE_H
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QObject>
#include <QTimer>
#include <QKeyEvent>
#include <QImage>
#include <QApplication>
#include <QGraphicsView>
#include <QRandomGenerator>
#include <QLabel>
#include <QScrollBar>
#include <QThread>
#include <QPushButton>
#include <QGraphicsView>
#include <QVBoxLayout>
#include <QWidget>
#include <QLayout>
#include <QVector>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QString>
#include <QMovie>
#include <QFile>
#include <QTextStream>
#include "Ennemy.h"
#include "Missile.h"
#include "StartScreen.h"
class MyScene : public QGraphicsScene {
    Q_OBJECT
private:
    QGraphicsPixmapItem* item = new  QGraphicsPixmapItem(QPixmap(":/assets/img/BG.png"));
    QGraphicsRectItem* qgri = new QGraphicsRectItem(10, 100, 300, 200);
    QGraphicsTextItem* qgti = new QGraphicsTextItem("CIR2 Rennes");
    QGraphicsPixmapItem* mainSpaceShip = new  QGraphicsPixmapItem(QPixmap(":/assets/img/4_Green.png"));
    QGraphicsView* view = new QGraphicsView(this);
    QGraphicsTextItem *counter = new QGraphicsTextItem("Score : " + QString::number(score));

    QMovie* movie = new QMovie("explosion.gif");
    QGraphicsPixmapItem* explosion = new QGraphicsPixmapItem(QPixmap::fromImage(movie->currentImage()));
    QTimer* timer = new QTimer(this);
    QTimer* timerEnnemy = new QTimer(this);

    StartScreen* starterPage = new StartScreen();
    QWidget* deathWidget = new QWidget();
    QString* playerName = new QString();

    QGraphicsPixmapItem* shield = new  QGraphicsPixmapItem(QPixmap(":/assets/img/shield.png"));

    QMediaPlayer* soundBG = new QMediaPlayer();
    QAudioOutput* soundOutput = new QAudioOutput();

    QTime couldown;
    int powerups = 0;

    int count = 15;
    int score = 0;

    void playGame(int startScore = 0);
    void newLevel();

public:
    QVector<Ennemy*> listeEnnemy;
    MyScene(QObject* parent = nullptr);
    virtual ~MyScene();
    void keyPressEvent(QKeyEvent* event);
    void createEnemy();
    void createMissile();
    void death();
    QString getRandomSpaceship();

public slots:
    void startGame(QString playerName);
    void restartGame();
    void update();
    void updateEnnemy();
    //void updateMissile();
    void showHome();

};


#endif //CPP_QT_TPMINIPROJET_MYSCENE_H
