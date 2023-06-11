//
// Created by CHAUVEAU Maxime on 11/06/2023.
//

#ifndef CPP_QT_TPMINIPROJET_MISSILE_H
#define CPP_QT_TPMINIPROJET_MISSILE_H
#include <QImage>
#include <QApplication>
#include <QGraphicsView>
#include <QScrollBar>
#include <QGraphicsView>
#include <QVBoxLayout>
#include <QWidget>
#include <iostream>
#include <QString>
#include <QGraphicsPathItem>
#include <QRandomGenerator>

class Missile {
private:
    QGraphicsPixmapItem* item;
public:
    Missile(int x, int y);

};


#endif //CPP_QT_TPMINIPROJET_MISSILE_H
