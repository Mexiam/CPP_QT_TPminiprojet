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
#include <QString>
#include <QMovie>
#include "Ennemy.h"
class MyScene : public QGraphicsScene {
    Q_OBJECT
private:
    QGraphicsPixmapItem* item = new  QGraphicsPixmapItem(QPixmap(":/assets/img/BG.png"));
    QGraphicsRectItem* qgri = new QGraphicsRectItem(10, 100, 300, 200);
    QGraphicsTextItem* qgti = new QGraphicsTextItem("CIR2 Rennes");
    QGraphicsPixmapItem* mainSpaceShip = new  QGraphicsPixmapItem(QPixmap(":/assets/img/4_Green.png"));
    QGraphicsView* view = new QGraphicsView(this);
    QGraphicsTextItem *counter = new QGraphicsTextItem("Score : " + QString::number(score));
    QVector<Ennemy*> listeEnnemy;
    QMovie* movie = new QMovie("explosion.gif");
    QWidget* deathWidjet;
    QWidget* startWidjet;
    QPushButton* restart = new QPushButton("Restart");
    QPushButton* play = new QPushButton("Play Game!");
    QPushButton* home = new QPushButton("Home");
    QHBoxLayout* buttonLayout = new QHBoxLayout;
    QVBoxLayout* layout = new QVBoxLayout;
    QVBoxLayout* layoutStart = new QVBoxLayout;
    QGraphicsPixmapItem* explosion = new QGraphicsPixmapItem(QPixmap::fromImage(movie->currentImage()));
    QTimer* timer = new QTimer(this);

    int count = 7;
    int score = 0;

public:
    MyScene(QObject* parent = nullptr);
    virtual ~MyScene();
    void keyPressEvent(QKeyEvent* event);
    void createEnemy();
    void death();
    QString getRandomSpaceship();

public slots:
    void restartGame();
    void update();
    void startGame();

};


#endif //CPP_QT_TPMINIPROJET_MYSCENE_H
