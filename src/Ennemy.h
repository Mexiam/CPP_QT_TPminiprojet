//
// Created by CHAUVEAU Maxime on 25/05/2023.
//

#ifndef CPP_QT_TPMINIPROJET_ENNEMY_H
#define CPP_QT_TPMINIPROJET_ENNEMY_H
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
class Ennemy : public QGraphicsPixmapItem{

public:
    Ennemy(QString url, int x, int y);
};


#endif //CPP_QT_TPMINIPROJET_ENNEMY_H
