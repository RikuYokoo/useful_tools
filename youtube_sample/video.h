#ifndef VIDEO_H
#define VIDEO_H

#include <QVideoWidget>

class Video : public QVideoWidget
{
public:
    Video();
    ~Video();
    static int my_target_;
private:
    bool check_Quit;
protected:
    void closeEvent(QCloseEvent* event);
};


#endif // VIDEO_H
