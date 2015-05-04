#ifndef LAYERBACKGROUND_H
#define LAYERBACKGROUND_H

#include <QWidget>

class LayerBackground : public QWidget
{
    Q_OBJECT
public:
    explicit LayerBackground(QWidget *parent = 0);

    QColor background_color;
signals:

public slots:
    void setBackgroundColor(QColor);
};

#endif // LAYERBACKGROUND_H
