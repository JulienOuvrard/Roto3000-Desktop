#ifndef IMAGEDISPLAYER_H
#define IMAGEDISPLAYER_H

#include <QWidget>
#include <QLabel>
#include <QLayout>
#include <QDir>
class ImageDisplayer : public QWidget
{
    Q_OBJECT
public:
    explicit ImageDisplayer(QString imgFolder, QWidget *parent = 0);

    QString imageFolder;
    QDir *folder;
    uint numberOfImage;
    uint index;
    QLabel *image;

    QGridLayout *layout;

    QImage img;
    QPixmap pix;

   void displayAtIndex(int i);
   int getNumberOfImage();
signals:

public slots:
    void displayBackground(bool check);
    void goToNext();
    void goToPrev();
    void goToImage(int);
};

#endif // IMAGEDISPLAYER_H
