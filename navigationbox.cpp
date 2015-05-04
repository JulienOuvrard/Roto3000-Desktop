#include "navigationbox.h"
#include "QShortcut"

NavigationBox::NavigationBox(uint n,QWidget *parent) :
    QWidget(parent)
{
    number=n;
    navigationLayout=new QHBoxLayout(this);
    navigation_slide=new QSlider(Qt::Horizontal);
    navigation_prev_btn=new QPushButton();
    navigation_suiv_btn=new QPushButton();

    navigation_slide->setMinimum(1);
    navigation_slide->setMaximum(number);
    navigationLayout->addWidget(navigation_prev_btn);
    navigationLayout->addWidget(navigation_slide);
    navigationLayout->addWidget(navigation_suiv_btn);

    QPixmap prevpix=QPixmap::fromImage((QImage(":/image/navigation/nav_prev").scaled(35,35,Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    QPixmap nextpix=QPixmap::fromImage((QImage(":/image/navigation/nav_next").scaled(35,35,Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));

    navigation_prev_btn->setIcon(QIcon(prevpix));
    navigation_prev_btn->setFlat(true);
    navigation_prev_btn->setIconSize(prevpix.size());
    navigation_suiv_btn->setIcon(QIcon(nextpix));
    navigation_suiv_btn->setFlat(true);
    navigation_suiv_btn->setIconSize(nextpix.size());

    QObject::connect(navigation_prev_btn,SIGNAL(clicked()),this,SLOT(clickPrev()));
    QObject::connect(navigation_suiv_btn,SIGNAL(clicked()),this,SLOT(clickNext()));
    QObject::connect(navigation_slide,SIGNAL(valueChanged(int)),this,SLOT(navTo(int)));
}

void NavigationBox::clickNext(){
    emit nextClicked();
    int x= navigation_slide->sliderPosition()+1;
    navigation_slide->setSliderPosition(x);
    emit save(x-1);
}

void NavigationBox::clickPrev(){
    emit prevclicked();
    int x= navigation_slide->sliderPosition()-1;
    navigation_slide->setSliderPosition(x);
    emit load(x);
}

void NavigationBox::navTo(int i){
    emit goTo(i);
}
