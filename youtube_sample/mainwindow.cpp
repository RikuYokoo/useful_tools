#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //player = new QMediaPlayer;
    //player1 = new QMediaPlayer;
    //video = new Video;
    //video2 = new Video;
    //player->setVideoOutput(video);
    //player1->setVideoOutput(video2);

    qDebug() << video_list.size();
    player_list << new QMediaPlayer << new QMediaPlayer << new QMediaPlayer << new QMediaPlayer << new QMediaPlayer << new QMediaPlayer;
    video_list << new Video << new Video << new Video << new Video << new Video;
    video_list.append(new Video);
    qDebug() << video_list.size();

    //player_list.at(0)->setVideoOutput(video_list.at(0));
    //player_list.at(1)->setVideoOutput(video_list.at(1));
    for(int i=0;i<video_list.size();i++){
    qDebug() << video_list.size();
      player_list.at(i)->setVideoOutput(video_list.at(i));
      QString obj_name = "player ";
      obj_name += i;
      QString obj_name_video = "video ";
      obj_name_video+=i;
      qDebug() << "object_name = " << obj_name_video;
      player_list.at(i)->setObjectName(obj_name);
      video_list.at(i)->installEventFilter(this);
      video_list.at(i)->setObjectName(obj_name_video);
    }

}

MainWindow::~MainWindow()
{
  std::cout << "destracta "<< std::endl;
    delete ui;
}


void MainWindow::on_actionopen_triggered()
{
  for(int i=0;i<player_list.size();i++){
    player_list.at(i)->setMedia(QUrl::fromLocalFile(QFileDialog::getOpenFileName()));
    player_list.at(i)->pause();
  }
    //player->setMedia(QUrl::fromLocalFile("file:://output.mp4"));
}


void MainWindow::on_pushButtonPlay_clicked(bool checked)
{
    qDebug() << checked;
    if(checked){
        //player_list.at(0)->play();
        //ui->pushButtonPlay->setText("||");
        for(int i=0;i<player_list.size();i++){
          player_list.at(i)->play();
        }
        ui->pushButtonPlay->setText("||");
    }else{
        for(int i=0;i<player_list.size();i++){
          player_list.at(i)->pause();
        }
        ui->pushButtonPlay->setText("|>");
    }
    //delete video_list[0];

}

bool MainWindow::eventFilter(QObject* obj, QEvent* event)
{
  if(event->type() == QEvent::Close){
    //video_list.removeOne(obj);
  }
  qDebug() << video_list.size();

  return true;
}
