//
// Created by CHAUVEAU Maxime on 25/05/2023.
//

#include "Ennemy.h"
Ennemy::Ennemy(QString url, int x, int y) {
    this->setPixmap(QPixmap(url));
    this->setPos(x, y);
    double randomSizeSpaceShip = QRandomGenerator::global()->generateDouble()*(0.60-0.40);
    qreal scaleRatio = randomSizeSpaceShip;
    this->setScale(scaleRatio);
}