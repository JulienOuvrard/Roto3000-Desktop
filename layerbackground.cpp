#include "layerbackground.h"

LayerBackground::LayerBackground(QWidget *parent) :
    QWidget(parent)
{
    setFixedHeight(450);
    setFixedWidth(850);
    background_color=Qt::white;
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, background_color);
    setAutoFillBackground(true);
    setPalette(Pal);
}

void LayerBackground::setBackgroundColor(QColor color){
    background_color=color;
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, background_color);
    setAutoFillBackground(true);
    setPalette(Pal);
}
