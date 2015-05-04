#ifndef CHOOSEVIDEO_H
#define CHOOSEVIDEO_H

#include <QWidget>
#include <QLineEdit>
#include <QMessageBox>
#include <QFileDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QRadioButton>
#include <QLayout>
#include "videoediting.h"
class ChooseVideo : public QWidget
{
    Q_OBJECT
public:
    explicit ChooseVideo(QWidget *parent = 0);

    QLineEdit *path_vid;
    QPushButton *choose;
    QRadioButton *f_6;
    QRadioButton *f_8;
    QRadioButton *f_12;
    QRadioButton *f_24;
    QPushButton *ret;
    QPushButton *ok;

    QVBoxLayout *mainLayout;
    QHBoxLayout *browse_layout;
    QHBoxLayout *buttonLayout;

    QString path;
    int freq;


signals:

public slots:
    void browse();
    void retour();
    void suivant();
};

#endif // CHOOSEVIDEO_H
