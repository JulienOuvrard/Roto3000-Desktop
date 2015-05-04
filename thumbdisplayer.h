#ifndef THUMBDISPLAYER_H
#define THUMBDISPLAYER_H

#include <QWidget>
#include <QLabel>
#include <QLayout>
class ThumbDisplayer : public QWidget
{
    Q_OBJECT
public:
    explicit ThumbDisplayer(QString name, int i, QWidget *parent = 0);

    QString path;
    int index;
    QLabel *image;

    QGridLayout *layout;

    QLabel *indexL;
    QImage img;
    QPixmap pix;

    bool isActive;

    void displayBackground();
    bool state;
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent*);


signals:
    void clicked(int);
    void release(int);
    void pressed(int);
public slots:
    void setActive(bool ac);

};

#endif // THUMBDISPLAYER_H
