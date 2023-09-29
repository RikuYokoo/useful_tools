#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QMediaPlaylist>

#include <QFileDialog>
#include "video.h"

#include <QTime>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //void test_aiueo();
private slots:
    void on_actionopen_triggered();
    void on_actionFull_Screen_triggered();

    void on_pushButtonPlay_clicked(bool checked);
    void test_aiueo();

    void on_timeprogress_bar_sliderMoved(int position);
    void updateTime(qint64 t);
    void addPlaylist();

private:
    Ui::MainWindow *ui;
    QMediaPlayer *player;
    //QMediaPlayer *player1;
    Video *video;
    QMediaPlaylist *playlist;
    //Video *video2;
    QList<Video*> video_list;
    QList<QMediaPlayer*> player_list;
    QTimer *timer;

    //void test_aiueo();
protected:
    bool eventFilter(QObject* obj, QEvent* event);
};
#endif // MAINWINDOW_H
