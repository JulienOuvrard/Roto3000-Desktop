#include "layerbox.h"
LayerBox::LayerBox(QWidget *parent) :
    QWidget(parent)
{
    layer_group=new QGroupBox(tr("Layer Box"),this);
    layer_group->setStyleSheet(QString("QGroupBox{border:2px solid gray;border-radius:5px;margin-top: 1ex;} QGroupBox::title{subcontrol-origin: margin;subcontrol-position:top center;padding:0 3px;}"));
    firstLayout=new QVBoxLayout;

    //new layer button
    new_layer_btn=new QPushButton(tr("New Layer"));
    firstLayout->addWidget(new_layer_btn);

    //number of layers
    layer_layout=new QHBoxLayout;
    layer_label=new QLabel(tr("Number of visible layers"));
    layer_spin = new QSpinBox();
    layer_spin->setMaximum(4);
    layer_spin->setMinimum(1);
    layer_spin->setValue(1);
    layer_layout->addWidget(layer_label);
    layer_layout->addWidget(layer_spin);
    firstLayout->addLayout(layer_layout);

    //layer color
    layer_color_layout=new QHBoxLayout;
    layer_color_label=new QLabel(tr("Layer color"));
    layer_color_btn=new QPushButton();
    layer_color_btn->setStyleSheet(QString("background-color: white"));
    layer_color_layout->addWidget(layer_color_label);
    layer_color_layout->addWidget(layer_color_btn);
    firstLayout->addLayout(layer_color_layout);

    //subfrequency
    layer_sub_layout=new QVBoxLayout;
    layer_sub_label=new QLabel(tr("Subfrequency of layers"));
    layer_sub_slide = new QSlider();
    layer_sub_slide->setMaximum(3);
    layer_sub_slide->setMinimum(1);
    layer_sub_slide->setOrientation(Qt::Horizontal);
    layer_sub_layout->addWidget(layer_sub_label);
    layer_sub_layout->addWidget(layer_sub_slide);
    firstLayout->addLayout(layer_sub_layout);

    layer_group->setLayout(firstLayout);
    QObject::connect(layer_color_btn,SIGNAL(clicked()),this,SLOT(chooseLayerColor()));
    QObject::connect(new_layer_btn,SIGNAL(clicked()),this,SLOT(res_layer()));
}

void LayerBox::chooseLayerColor(){
    QColor couleur = QColorDialog::getColor(Qt::white, this);
    QString qss = QString("background-color: %1").arg(couleur.name());
    layer_color_btn->setStyleSheet(qss);
    emit layer_color_changed(couleur);
}

void LayerBox::res_layer(){
    emit layer_reset();
}
