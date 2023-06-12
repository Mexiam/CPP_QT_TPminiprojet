//
// Created by CHAUVEAU Maxime on 11/06/2023.
//

#include "Missile.h"

Missile::Missile(int x, int y) {
    this->setPixmap(QPixmap(":/assets/img/missile.png").transformed(QTransform().rotate(-45)));
    this->setPos(x, y);
    qreal scaleRatio = 0.09;

    this->setScale(scaleRatio);
    this->timerMissile->start(30);
    connect(timerMissile, SIGNAL(timeout()), this, SLOT(updateMissile()));


}

void Missile::updateMissile() {
    QPointF position = this->pos();

    if(position.ry()<0){
        delete this;
    }
    else{
        this->setPos(position.rx(), position.ry() - 10);
    }

    QList<QGraphicsItem*> collidingItems = this->collidingItems();
    foreach(QGraphicsItem* item, collidingItems){
        Ennemy* ennemy = dynamic_cast<Ennemy*>(item);
        if(dynamic_cast<Ennemy*>(item)) {
            ennemy->setPos(1000000, 1000000); // Pas top ça
            delete this;

        }
    }
}