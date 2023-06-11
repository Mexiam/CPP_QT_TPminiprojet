//
// Created by allan on 10/06/2023.
//

#include "StartScreen.h"

StartScreen::StartScreen() : QWidget() {
    usernameInput->setPlaceholderText("Username");
    usernameInput->setMaxLength(20);
    usernameInput->setReadOnly(false);

    layout->addWidget(title);
    layout->addWidget(usernameInput);
    layout->addWidget(title2);
    layout->addWidget(scores);
    layout->addWidget(play);

    layout->setAlignment(Qt::AlignCenter);

    play->setStyleSheet("background-color: black; color: white; font-size: 16px;");

    QFont font("Tahoma ", 12, QFont::Bold);
    title->setFont(font);

    connect(play, SIGNAL(pressed()), this, SLOT(verifyUsernameForStart()));

    this->setLayout(layout);
}

void StartScreen::verifyUsernameForStart() {
    QString playerName = usernameInput->text();
    if(playerName.length() > 0){
        emit start(playerName);
    }
}