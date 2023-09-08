#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    player = new QMediaPlayer;
    video = new Video;
    player->setVideoOutput(video);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionopen_triggered()
{
    //player->setMedia(QUrl::fromLocalFile(QFileDialog::getOpenFileName()));
    player->setMedia(QUrl::fromLocalFile("file:://output.mp4"));
}


void MainWindow::on_pushButtonPlay_clicked(bool checked)
{
    if(checked){
        player->play();
        ui->pushButtonPlay->setText("||");
    }else{
        player->pause();
        ui->pushButtonPlay->setText("|>");
    }

}

