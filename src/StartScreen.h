//
// Created by allan on 10/06/2023.
//

#ifndef CPP_QT_TPMINIPROJET_STARTSCREEN_H
#define CPP_QT_TPMINIPROJET_STARTSCREEN_H
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QPushButton>
#include <QGraphicsScene>
#include "ScoreBoard.h"

class StartScreen : public QWidget {
Q_OBJECT
public:
    StartScreen();
private:
    QVBoxLayout *layout = new QVBoxLayout();
    QLabel *title = new QLabel("SPACESHIPS");
    QLineEdit *usernameInput=  new QLineEdit("Player");
    QLabel *title2 = new QLabel("Best players :");
    ScoreBoard *scores = new ScoreBoard(":/assets/data/scores.csv");
    QPushButton* play = new QPushButton("Play Game!");
private slots:
    void verifyUsernameForStart();
signals:
    void start(QString playerName);
};


#endif //CPP_QT_TPMINIPROJET_STARTSCREEN_H
