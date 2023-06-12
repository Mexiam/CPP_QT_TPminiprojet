//
// Created by allan on 11/06/2023.
//
#include <iostream>

#ifndef CPP_QT_TPMINIPROJET_SCOREBOARD_H
#define CPP_QT_TPMINIPROJET_SCOREBOARD_H

#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QTableWidget>

class ScoreBoard : public QTableWidget {
Q_OBJECT
public:
    ScoreBoard(const QString &name, QWidget *parent = nullptr);
    void readCSV(const QString &name);
};


#endif //CPP_QT_TPMINIPROJET_SCOREBOARD_H
