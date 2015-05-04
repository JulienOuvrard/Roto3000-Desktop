#ifndef NAVIGATIONBOX_H
#define NAVIGATIONBOX_H

#include <QWidget>
#include <QPushButton>
#include <QSlider>
#include <QLayout>

class NavigationBox : public QWidget
{
    Q_OBJECT
public:
    explicit NavigationBox(uint n, QWidget *parent = 0);
    uint number;
    QHBoxLayout *navigationLayout;
    QSlider *navigation_slide;
    QPushButton *navigation_prev_btn;
    QPushButton *navigation_suiv_btn;
signals:
    void nextClicked();
    void prevclicked();
    void goTo(int);
    void save(int);
    void load(int);
public slots:
    void clickNext();
    void clickPrev();
    void navTo(int);
};

#endif // NAVIGATIONBOX_H
