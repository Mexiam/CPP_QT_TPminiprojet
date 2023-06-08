//
// Created by CHAUVEAU Maxime on 25/05/2023.
//
#include <QImage>
#include <QApplication>
#include <QGraphicsView>
#include <QScrollBar>
#include <QGraphicsView>
#include <QVBoxLayout>
#include <QWidget>
#ifndef CPP_QT_TPMINIPROJET_ENNEMY_H
#define CPP_QT_TPMINIPROJET_ENNEMY_H
#include <iostream>
#include <QString>
#include <QGraphicsPathItem>
#include <QRandomGenerator>
class Ennemy : public QGraphicsPixmapItem{
private:
    QGraphicsPixmapItem* item;
public:
    Ennemy(QString url, int x, int y);
};


#endif //CPP_QT_TPMINIPROJET_ENNEMY_H
