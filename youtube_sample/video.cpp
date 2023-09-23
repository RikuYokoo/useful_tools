#include "video.h"
#include <QDebug>
#include <QMessageBox>
#include <QCloseEvent>
#include <iostream>


int Video::my_target_ = 0;
Video::Video()
{

  check_Quit = true;
  my_target_++;
  QString window_title = "video player :" ;
  window_title += QString::number(my_target_);
    setWindowTitle(window_title);
    showNormal();

}

Video::~Video()
{
  qDebug() << "destract " << my_target_ << ", " << __func__ ;
  std::cout << "destract " << my_target_ << ", " << __func__  << std::endl;;
  my_target_--;
  if(my_target_ < 0){
    qDebug() << "Video if in ";
    my_target_ = 0;
  }

}

void Video::closeEvent(QCloseEvent *event)
{
  if(check_Quit){
    int ret = QMessageBox::question(this, tr("end check"), tr("end?"));
    if(ret == QMessageBox::No){
      event->ignore();
    }
  }
  event->accept();
}
