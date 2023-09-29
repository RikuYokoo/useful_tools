#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&QMainWindow::update));
    timer->start(500);
    */

    playlist = new QMediaPlaylist;
    player = new QMediaPlayer;
    //player1 = new QMediaPlayer;
    video = new Video;
    video->installEventFilter(this);
    //connect(ui->pushButton, &QPushButton::clicked, this, &QMainWindow::test_aiueo());
    //connect(ui->pushButton, &QPushButton::clicked, [=](){qDebug() << "aiueo" ;});
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::test_aiueo);
    connect(ui->playlist_add_Button, &QPushButton::clicked, this, &MainWindow::addPlaylist);
    //connect(playlist, QOverload<QMediaPlayer::Error>::of(&QMediaPlayer::error), [=](QMediaPlayer::Error error){ qDebug() << "erro = " << error;});
    //connect(playlist, QOverload<QMediaPlayer::Error>::of(&QMediaPlayer::error), [=](QMediaPlayer::Error error){ qDebug() << "erro = " << error;});
    //video2 = new Video;
    //player->setVideoOutput(video);
    //player1->setVideoOutput(video2);

    //qDebug() << video_list.size();
    //player_list << new QMediaPlayer << new QMediaPlayer << new QMediaPlayer << new QMediaPlayer << new QMediaPlayer << new QMediaPlayer;
    //video_list << new Video << new Video << new Video << new Video << new Video;
    //video_list.append(new Video);
    //qDebug() << video_list.size();

    //player_list.at(0)->setVideoOutput(video_list.at(0));
    //player_list.at(1)->setVideoOutput(video_list.at(1));
    /*
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
    */
    connect(player, &QMediaPlayer::positionChanged, this, &MainWindow::updateTime);
    player->setVideoOutput(video);
    player->setNotifyInterval(100);
    //connect(player, &QMediaPlayer::positionChanged, this, &MainWindow::updateTime)

}

MainWindow::~MainWindow()
{
  std::cout << "destracta "<< std::endl;
    delete ui;
}


void MainWindow::on_actionopen_triggered()
{
    playlist->addMedia(QUrl::fromLocalFile(QFileDialog::getOpenFileName()));
    qDebug() << playlist->mediaCount();
    qDebug() << "error = " << playlist->error();
    qDebug() << "error = " << playlist->errorString();
    playlist->addMedia(QUrl::fromLocalFile(QFileDialog::getOpenFileName()));
    qDebug() << playlist->mediaCount();
    qDebug() << "error = " << playlist->error();
    qDebug() << "error = " << playlist->errorString();
    playlist->addMedia(QUrl::fromLocalFile(QFileDialog::getOpenFileName()));
    qDebug() << playlist->mediaCount();
    qDebug() << "error = " << playlist->error();
    qDebug() << "error = " << playlist->errorString();
    //playlist->setCurrentIndex(2);
    player->setPlaylist(playlist);
    playlist->setCurrentIndex(0);
    player->pause();
  /*
  for(int i=0;i<player_list.size();i++){
    player_list.at(i)->setMedia(QUrl::fromLocalFile(QFileDialog::getOpenFileName()));
    player_list.at(i)->pause();
  }
  */
    //player->setMedia(QUrl::fromLocalFile("file:://output.mp4"));
}
void MainWindow::on_actionFull_Screen_triggered()
{
  bool tf = playlist->addMedia(QUrl::fromLocalFile(QFileDialog::getOpenFileName()));
  qDebug() <<  tf << "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" ;
}


void MainWindow::on_pushButtonPlay_clicked(bool checked)
{
    qDebug() << checked;
    if(checked){

        //player_list.at(0)->play();
        //ui->pushButtonPlay->setText("||");
      /*
        for(int i=0;i<player_list.size();i++){
          player_list.at(i)->play();
        }
        */
      player->play();
        ui->pushButtonPlay->setText("||");
        qDebug() << player->errorString();
    }else{
      /*
        for(int i=0;i<player_list.size();i++){
          player_list.at(i)->pause();
        }
        */
      player->pause();
        ui->pushButtonPlay->setText("|>");
        qDebug() << player->errorString();
    }
    //delete video_list[0];

}

bool MainWindow::eventFilter(QObject* obj, QEvent* event)
{
  if(event->type() == QEvent::Close){
    //video_list.removeOne(obj);
  }
  //qDebug() << video_list.size();
  qDebug() << "playlist currentindex = " << playlist->currentIndex();

  return true;
}

void MainWindow::test_aiueo()
{
  qDebug() << "aiuieuijekri" ;
}

void MainWindow::on_timeprogress_bar_sliderMoved(int position)
{
    qDebug() << "position = " << position;
    player->setPosition(position*player->duration()/1000);
}

void MainWindow::updateTime(qint64 t)
{
    qDebug() << player->position()<< ", " << t;
    ui->label_Now->setText(QTime(0,0).addMSecs(t).toString("hh:mm:ss:zz"));
    ui->label_Total->setText(QTime(0,0).addMSecs(player->duration()).toString("hh:mm:ss:zz"));
    if(player->duration()){
        ui->timeprogress_bar->setValue(1000*t/player->duration());
    }
}

void MainWindow::addPlaylist()
{
  QUrl file = QUrl::fromLocalFile(QFileDialog::getOpenFileName());
  qDebug() << file.isEmpty();
  qDebug() << file.url();
  qDebug() << file.toString();

  bool tf = playlist->addMedia(file);
  qDebug() <<  tf << "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" ;
  //qDebug() << "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb";
  qDebug() << playlist->mediaCount();
  

  /*
  for(int i=0;i<playlist->mediaCount();i++)
  {
    qDebug() << QString(playlist->media(i));
  }
  */
}
