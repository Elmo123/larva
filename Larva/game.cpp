#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <iostream>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QMessageBox>



Game::Game(QWidget *){
    // create the scene
    scene = new QGraphicsScene();
    scene->clear();
    scene->setSceneRect(0,0,400,400); // set screen size
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(400,400);

    // creates larva object
    createLarva();

    // Draws starting menu
    drawPanel(0,0,150,768,Qt::darkCyan,1);
    drawMenu(0,0,150,1);
    show();

    timer_ = new QTimer();
    connect(timer_, SIGNAL(timeout()),this, SLOT(timerA()));
    timer_->start(25);

}

void Game::drawPanel(int x, int y, int width, int height, QColor color, double opacity)
{
    panel_ = new QGraphicsRectItem(x,y,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel_->setBrush(brush);
    panel_->setOpacity(opacity);
    scene->addItem(panel_);


}

void Game::drawMenu(int x, int y, int width, double opacity){
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);

    if (option_ == 0){
        // option1
        QGraphicsRectItem* item_1 = new QGraphicsRectItem(x,y,width,30);
        brush.setColor(Qt::white);
        item_1->setBrush(brush);
        item_1->setOpacity(opacity);
        scene->addItem(item_1);
        // option2
        QGraphicsRectItem* item_2 = new QGraphicsRectItem(x,y+30,width,30);
        brush.setColor(Qt::darkCyan);
        item_2->setBrush(brush);
        item_2->setOpacity(opacity);
        scene->addItem(item_2);
        // option3
        QGraphicsRectItem* item_3 = new QGraphicsRectItem(x,y+60,width,30);
        brush.setColor(Qt::darkCyan);
        item_3->setBrush(brush);
        item_3->setOpacity(opacity);
        scene->addItem(item_3);
        // option4
        QGraphicsRectItem* item_4 = new QGraphicsRectItem(x,y+90,width,30);
        brush.setColor(Qt::darkCyan);
        item_4->setBrush(brush);
        item_4->setOpacity(opacity);
        scene->addItem(item_4);
    }
    else if (option_ == 1){
        // option1
        QGraphicsRectItem* item_1 = new QGraphicsRectItem(x,y,width,30);
        brush.setColor(Qt::darkCyan);
        item_1->setBrush(brush);
        item_1->setOpacity(opacity);
        scene->addItem(item_1);
        // option2
        QGraphicsRectItem* item_2 = new QGraphicsRectItem(x,y+30,width,30);
        brush.setColor(Qt::white);
        item_2->setBrush(brush);
        item_2->setOpacity(opacity);
        scene->addItem(item_2);
        // option3
        QGraphicsRectItem* item_3 = new QGraphicsRectItem(x,y+60,width,30);
        brush.setColor(Qt::darkCyan);
        item_3->setBrush(brush);
        item_3->setOpacity(opacity);
        scene->addItem(item_3);
        // option4
        QGraphicsRectItem* item_4 = new QGraphicsRectItem(x,y+90,width,30);
        brush.setColor(Qt::darkCyan);
        item_4->setBrush(brush);
        item_4->setOpacity(opacity);
        scene->addItem(item_4);
    }
    else if (option_ == 2){
        // option1
        QGraphicsRectItem* item_1 = new QGraphicsRectItem(x,y,width,30);
        brush.setColor(Qt::darkCyan);
        item_1->setBrush(brush);
        item_1->setOpacity(opacity);
        scene->addItem(item_1);
        // option2
        QGraphicsRectItem* item_2 = new QGraphicsRectItem(x,y+30,width,30);
        brush.setColor(Qt::darkCyan);
        item_2->setBrush(brush);
        item_2->setOpacity(opacity);
        scene->addItem(item_2);
        // option3
        QGraphicsRectItem* item_3 = new QGraphicsRectItem(x,y+60,width,30);
        brush.setColor(Qt::white);
        item_3->setBrush(brush);
        item_3->setOpacity(opacity);
        scene->addItem(item_3);
        // option4
        QGraphicsRectItem* item_4 = new QGraphicsRectItem(x,y+90,width,30);
        brush.setColor(Qt::darkCyan);
        item_4->setBrush(brush);
        item_4->setOpacity(opacity);
        scene->addItem(item_4);
    }
    else if (option_ == 3){
        // option1
        QGraphicsRectItem* item_1 = new QGraphicsRectItem(x,y,width,30);
        brush.setColor(Qt::darkCyan);
        item_1->setBrush(brush);
        item_1->setOpacity(opacity);
        scene->addItem(item_1);
        // option2
        QGraphicsRectItem* item_2 = new QGraphicsRectItem(x,y+30,width,30);
        brush.setColor(Qt::darkCyan);
        item_2->setBrush(brush);
        item_2->setOpacity(opacity);
        scene->addItem(item_2);
        // option3
        QGraphicsRectItem* item_3 = new QGraphicsRectItem(x,y+60,width,30);
        brush.setColor(Qt::darkCyan);
        item_3->setBrush(brush);
        item_3->setOpacity(opacity);
        scene->addItem(item_3);
        // option4
        QGraphicsRectItem* item_4 = new QGraphicsRectItem(x,y+90,width,30);
        brush.setColor(Qt::white);
        item_4->setBrush(brush);
        item_4->setOpacity(opacity);
        scene->addItem(item_4);
    }
    else {
        // option1
        QGraphicsRectItem* item_1 = new QGraphicsRectItem(x,y,width,30);
        brush.setColor(Qt::darkCyan);
        item_1->setBrush(brush);
        item_1->setOpacity(opacity);
        scene->addItem(item_1);
        // option2
        QGraphicsRectItem* item_2 = new QGraphicsRectItem(x,y+30,width,30);
        brush.setColor(Qt::darkCyan);
        item_2->setBrush(brush);
        item_2->setOpacity(opacity);
        scene->addItem(item_2);
        // option3
        QGraphicsRectItem* item_3 = new QGraphicsRectItem(x,y+60,width,30);
        brush.setColor(Qt::darkCyan);
        item_3->setBrush(brush);
        item_3->setOpacity(opacity);
        scene->addItem(item_3);
        // option4
        QGraphicsRectItem* item_4 = new QGraphicsRectItem(x,y+90,width,30);
        brush.setColor(Qt::darkCyan);
        item_4->setBrush(brush);
        item_4->setOpacity(opacity);
        scene->addItem(item_4);
    }
    QGraphicsTextItem* option1 = new QGraphicsTextItem("New Game");
    option1->setPos(x,y);
    scene->addItem(option1);

    // for difficulty
    if (difficult_ == 0){
        QGraphicsTextItem* option2 = new QGraphicsTextItem("Difficulty: Easy");
        option2->setPos(x,y+30);
        scene->addItem(option2);
    }
    else if (difficult_ == 1){
        QGraphicsTextItem* option2 = new QGraphicsTextItem("Difficulty: Medium");
        option2->setPos(x,y+30);
        scene->addItem(option2);
    }
    else if (difficult_ == 2){
        QGraphicsTextItem* option2 = new QGraphicsTextItem("Difficulty: Hard");
        option2->setPos(x,y+30);
        scene->addItem(option2);
    }
    else if (difficult_ == 3){
        QGraphicsTextItem* option2 = new QGraphicsTextItem("Difficulty: Lunatic");
        option2->setPos(x,y+30);
        scene->addItem(option2);
    }

    QGraphicsTextItem* option3 = new QGraphicsTextItem("Highscore");
    option3->setPos(x,y+60);
    scene->addItem(option3);

    QGraphicsTextItem* option4 = new QGraphicsTextItem("Quit Game");
    option4->setPos(x,y+90);
    scene->addItem(option4);

}

void Game::options()
{
    option_ = 1;
}

void Game::gameOver(int score_)
{
    scene->clear();
    option_ = -299;
    createLarva();
    drawPanel(0,0,150,768,Qt::darkCyan,1);
    QGraphicsTextItem* over = new QGraphicsTextItem("Game Over!");
    over->setPos(0,60);
    scene->addItem(over);

    QGraphicsTextItem* score = new QGraphicsTextItem("Score: " + QString::number(score_));
    score->setPos(0,80);
    scene->addItem(score);

    highscore_ = getHighScore();
    if (highscore_ < score_){
        writeHighScore(score_);
        highscore_ = getHighScore();
    }
    QGraphicsTextItem* txt = new QGraphicsTextItem("Highscore: " + QString::number(highscore_));
    txt->setPos(0,120);
    scene->addItem(txt);

}

void Game::createLarva()
{
    // configure players character
    larva = new Larva();
    larva->setRect(0,0,10,10);
    larva->setBrush(* new QBrush(Qt::red));
    larva->setPos(200,200);
    larva->setFlag(QGraphicsItem::ItemIsFocusable);
    larva->setFocus();

    scene->addItem(larva);
}

int Game::getHighScore()
{
    //reading text file
    QFile file("C:/Users/Elmeri/Documents/QT/matopeli/HighScore.txt");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }
    QTextStream in(&file);
    QString line = in.readLine();
    file.close();


    int highsc = line.toInt();
    return highsc;
}



void Game::writeHighScore(int score)
{
    QFile file("C:/Users/Elmeri/Documents/QT/matopeli/HighScore.txt");
    if(!file.open(QIODevice::WriteOnly)) {
        QMessageBox::information(0,"error",file.errorString());
    }
    QString dd = QString::number(score);



    QTextStream out(&file);
    out << dd << endl;

}

void Game::difficulty(int x, int y, int width, double opacity)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);

    // option2 rewrite
    QGraphicsRectItem* item_2 = new QGraphicsRectItem(x,y+30,width,30);
    brush.setColor(Qt::white);
    item_2->setBrush(brush);
    item_2->setOpacity(opacity);
    scene->addItem(item_2);

    if (difficult_ == 0){
        QGraphicsTextItem* option2 = new QGraphicsTextItem("Difficulty: Easy");
        option2->setPos(x,y+30);
        scene->addItem(option2);
        speedo_ = 18;
    }
    else if (difficult_ == 1){
        QGraphicsTextItem* option2 = new QGraphicsTextItem("Difficulty: Medium");
        option2->setPos(x,y+30);
        scene->addItem(option2);
        speedo_ = 15;
    }
    else if (difficult_ == 2){
        QGraphicsTextItem* option2 = new QGraphicsTextItem("Difficulty: Hard");
        option2->setPos(x,y+30);
        scene->addItem(option2);
        speedo_ = 10;
    }
    else if (difficult_ == 3){
        QGraphicsTextItem* option2 = new QGraphicsTextItem("Difficulty: Lunatic");
        option2->setPos(x,y+30);
        scene->addItem(option2);
        speedo_ = 5;
    }
}

Game::~Game()
{   }

void Game::timerA()
{

    if (enter_ == true){
        timer_->stop();
        scene->clear();
        createLarva();

        // create the score
        score = new Score();
        scene->addItem(score);
        // create the health
        health = new Health();
        health->setPos(health->x(),health->y()+20);
        scene->addItem(health);
        larva->points_spawn();

        show();
    }
}
