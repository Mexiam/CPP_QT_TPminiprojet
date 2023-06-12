//
// Created by CHAUVEAU Maxime on 11/06/2023.
//

#ifndef CPP_QT_TPMINIPROJET_MISSILE_H
#define CPP_QT_TPMINIPROJET_MISSILE_H
#include <QImage>
#include <QApplication>
#include <QGraphicsView>
#include <QScrollBar>
#include <QGraphicsPixmapItem>
#include "MyScene.h"
#include <QGraphicsView>
#include <QVBoxLayout>
#include <QWidget>
#include <iostream>
#include <QString>
#include <QTimer>
#include <QGraphicsPathItem>
#include <QTransform>
#include <QDate>
#include <QRandomGenerator>
#include "Ennemy.h"

class Missile : public QObject , public QGraphicsPixmapItem{
    Q_OBJECT
private:
    QTimer* timerMissile = new QTimer();

public:
    Missile(int x, int y);

public slots:
    void updateMissile();

};


#endif //CPP_QT_TPMINIPROJET_MISSILE_H
