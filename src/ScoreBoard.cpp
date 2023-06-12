//
// Created by allan on 11/06/2023.
//

#include "ScoreBoard.h"

ScoreBoard::ScoreBoard(const QString &name, QWidget *parent)  : QTableWidget(parent){
    readCSV(name);
}

void ScoreBoard::readCSV(const QString &name) {
    QFile file(name);
    if (!file.exists()) {
        qDebug() << "Fichier CSV inexistant.";
    }
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Fichier CSV des scores inaccessible.";
        qDebug() << file.errorString();
        qDebug() << file.error();
    } else {
        QTextStream in(&file);
        QVector<QStringList> scoreList;
        while (!in.atEnd()) {
            QString line = in.readLine(); //On lit une ligne
            QStringList fields = line.split(";"); //On sépare les valeurs par ";"
            scoreList.append(fields); //On ajoute les valeurs au tableau
        }
        file.close();

        std::sort(scoreList.begin(), scoreList.end(), [](const QList<QString>& a, const QList<QString>& b)->bool{
            return a.at(1).toInt() > b.at(1).toInt();
        });

        int numRows = scoreList.size(); // Nombre de lignes
        int numCols = scoreList[0].size(); // Nombre de colonnes (suppose que toutes les lignes ont la même taille)

        this->setRowCount(numRows);
        this->setColumnCount(numCols);

        for (int row = 0; row < numRows; ++row) {
            QStringList rowValues = scoreList[row];
            for (int col = 0; col < numCols; ++col) {
                QString value = rowValues[col];
                QTableWidgetItem *item = new QTableWidgetItem(value);
                this->setItem(row, col, item);
            }
        }

        QStringList columnNames;
        columnNames << "Username" << "Score" << "Date";
        this->setHorizontalHeaderLabels(columnNames);

        this->resizeColumnsToContents();
    }
}