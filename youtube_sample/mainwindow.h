#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>

#include <QFileDialog>
#include "video.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionopen_triggered();

    void on_pushButtonPlay_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    QMediaPlayer *player;
    //QMediaPlayer *player1;
    Video *video;
    //Video *video2;
    QList<Video*> video_list;
    QList<QMediaPlayer*> player_list;
protected:
    bool eventFilter(QObject* obj, QEvent* event);
};
#endif // MAINWINDOW_H
