#ifndef WELCOME_H
#define WELCOME_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
class Welcome : public QWidget
{
    Q_OBJECT
public:
    explicit Welcome(QWidget *parent = 0);

    QPushButton *new_proj_btn;
    QPushButton *open_proj_btn;
    QLabel *title;
    QLabel *title_img;
    QVBoxLayout *firstlayout;
    QVBoxLayout *title_layout;
    QHBoxLayout *btn_layout;

signals:

public slots:
    void new_proj();
    void load_proj();
};

#endif // WELCOME_H
