//
// Created by CHAUVEAU Maxime on 11/06/2023.
//

#include "Missile.h"

Missile::Missile(int x, int y) {
    this->item->setPixmap(QPixmap("missile.png"));
    this->item->setPos(x, y);
    qreal scaleRatio = 0.15;
    this->item->setScale(scaleRatio);
}