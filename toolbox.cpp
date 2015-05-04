#include "toolbox.h"

ToolBox::ToolBox(QWidget *parent) :
    QWidget(parent)
{
    tool_group=new QGroupBox(tr("Tool Box"),this);
    tool_group->setStyleSheet(QString("QGroupBox{border:2px solid gray;border-radius:5px;margin-top: 1ex;} QGroupBox::title{subcontrol-origin: margin;subcontrol-position:top center;padding:0 3px;}"));
    firstLayout=new QVBoxLayout;

    //pencil
    pen_layout=new QHBoxLayout;
    pen_label=new QLabel(tr("Pencil"));
    pen_ch = new QCheckBox();
    pen_ch->setChecked(true);
    pen_layout->addWidget(pen_label);
    pen_layout->addWidget(pen_ch);
    firstLayout->addLayout(pen_layout);

    //pencil size
    size_layout=new QHBoxLayout;
    size_label=new QLabel(tr("Size (px)"));
    size_spin = new QSpinBox();
    size_spin->setMaximum(20);
    size_spin->setMinimum(1);
    size_spin->setValue(1);
    size_layout->addWidget(size_label);
    size_layout->addWidget(size_spin);
    firstLayout->addLayout(size_layout);

    //pencil color
    color_layout=new QHBoxLayout;
    color_label=new QLabel(tr("Color"));
    pen_color_btn=new QPushButton();
    pen_color_btn->setStyleSheet(QString("background-color: black"));
    color_layout->addWidget(color_label);
    color_layout->addWidget(pen_color_btn);
    firstLayout->addLayout(color_layout);

    //eraser
    eraser_layout=new QHBoxLayout;
    eraser_label=new QLabel(tr("Eraser"));
    eraser_ch = new QCheckBox();
    eraser_layout->addWidget(eraser_label);
    eraser_layout->addWidget(eraser_ch);
    firstLayout->addLayout(eraser_layout);

    //eraser size
    eraser_size_layout=new QHBoxLayout;
    eraser_size_label=new QLabel(tr("Size (px)"));
    eraser_size_spin = new QSpinBox();
    eraser_size_spin->setMaximum(20);
    eraser_size_spin->setMinimum(1);
    eraser_size_spin->setValue(1);
    eraser_size_layout->addWidget(eraser_size_label);
    eraser_size_layout->addWidget(eraser_size_spin);
    firstLayout->addLayout(eraser_size_layout);

    //background
    bkg_layout=new QHBoxLayout;
    bkg_label=new QLabel(tr("Display background image"));
    bkg_ch = new QCheckBox();
    bkg_ch->setChecked(true);
    bkg_layout->addWidget(bkg_label);
    bkg_layout->addWidget(bkg_ch);
    firstLayout->addLayout(bkg_layout);

    tool_group->setLayout(firstLayout);

    QObject::connect(pen_color_btn,SIGNAL(clicked()),this,SLOT(choosePenColor()));
    QObject::connect(size_spin,SIGNAL(valueChanged(int)),this,SLOT(choosePenSize(int)));
    pen_color= QColor(Qt::black);

    QObject::connect(eraser_size_spin,SIGNAL(valueChanged(int)),this,SLOT(chooseEraserSize(int)));
    QObject::connect(pen_ch,SIGNAL(toggled(bool)),this,SLOT(pen_selection(bool)));
    QObject::connect(eraser_ch,SIGNAL(toggled(bool)),this,SLOT(eraser_selection(bool)));
    QObject::connect(bkg_ch,SIGNAL(toggled(bool)),this,SLOT(display_background(bool)));
}


QColor ToolBox::getPenColor(){
    return pen_color;
}


void ToolBox::choosePenColor(){
    pen_color = QColorDialog::getColor(Qt::white, this);
    QString qss = QString("background-color: %1").arg(pen_color.name());
    pen_color_btn->setStyleSheet(qss);
    emit color_changed(pen_color);
}

void ToolBox::choosePenSize(int pen_size){
    emit size_changed(pen_size);
}

void ToolBox::chooseEraserSize(int er_size){
    emit eraser_size_changed(er_size);
}

void ToolBox::pen_selection(bool p){
    emit pen_select(p);
}

void ToolBox::eraser_selection(bool e){
    emit eraser_select(e);
}

void ToolBox::display_background(bool d){
    emit background_displayed(d);
}
