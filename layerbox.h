#ifndef LAYERBOX_H
#define LAYERBOX_H

#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QSlider>
#include <QSpinBox>
#include <QPushButton>
#include <QGroupBox>
#include <QColorDialog>

class LayerBox : public QWidget
{
    Q_OBJECT
public:
    explicit LayerBox(QWidget *parent = 0);

    QPushButton *new_layer_btn;
    QLabel *layer_label;
    QSpinBox *layer_spin;
    QLabel *layer_color_label;
    QPushButton *layer_color_btn;
    QLabel *layer_sub_label;
    QSlider *layer_sub_slide;

    QGroupBox *layer_group;
    QVBoxLayout *firstLayout;
    QHBoxLayout *layer_layout;
    QHBoxLayout *layer_color_layout;
    QVBoxLayout *layer_sub_layout;

signals:
    void layer_color_changed(QColor);
    void layer_reset();
public slots:
    void chooseLayerColor();
    void res_layer();
};

#endif // LAYERBOX_H
