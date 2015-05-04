#ifndef PREVIEWZONE_H
#define PREVIEWZONE_H

#include <QWidget>
#include <QLayout>
#include <QPushButton>
#include <QVector>
#include "thumbdisplayer.h"
class PreviewZone : public QWidget
{
    Q_OBJECT
public:
    explicit PreviewZone(QString lFolder, QWidget *parent = 0);
    QString layerFolder;
    QHBoxLayout *layout;
    QHBoxLayout *thumb_layout;
    QPushButton *prev_btn;
    QPushButton *suiv_btn;

    QVector<ThumbDisplayer*> thumbs;
    int index;

    void createLayout();
signals:

public slots:
    void change(int current);
};

#endif // PREVIEWZONE_H
