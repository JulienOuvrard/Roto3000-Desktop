#include "welcome.h"
#include "choosevideo.h"
#include "chooseproject.h"
#include <QGraphicsOpacityEffect>
Welcome::Welcome(QWidget *parent) :
    QWidget(parent)
{
    setFixedHeight(300);
    setFixedWidth(400);

    QPalette palette;
    QGraphicsOpacityEffect *effect=new QGraphicsOpacityEffect();
    effect->setOpacity(0.3);
    effect->setOpacityMask(QImage(":/image/welcome/welcome_fond").scaled(400,300,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    palette.setBrush(this->backgroundRole(), effect->opacityMask());
    this->setPalette(palette);

    firstlayout= new QVBoxLayout(this);

    title_layout= new QVBoxLayout;
    title=new QLabel("WELCOME TO");
    title->setAlignment(Qt::AlignCenter);
    title_img=new QLabel("ROTO 3000");

    title_img->setAlignment(Qt::AlignCenter);
    title_layout->addWidget(title);
    title_layout->addWidget(title_img);

    btn_layout = new QHBoxLayout;
    new_proj_btn = new QPushButton("New Project");
    open_proj_btn = new QPushButton("Open Project");
    btn_layout->addWidget(new_proj_btn);
    btn_layout->addWidget(open_proj_btn);

    firstlayout->addLayout(title_layout);
    firstlayout->addLayout(btn_layout);

    QObject::connect(new_proj_btn,SIGNAL(clicked()),this,SLOT(new_proj()));
    QObject::connect(open_proj_btn,SIGNAL(clicked()),this,SLOT(load_proj()));

}

void Welcome::new_proj(){
    ChooseVideo *vid=new ChooseVideo();
    vid->show();
    this->close();
}

void Welcome::load_proj(){
    ChooseProject *pro=new ChooseProject();
    pro->show();
    this->close();
}
