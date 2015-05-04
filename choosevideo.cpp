#include "choosevideo.h"
#include "mainwindow.h"
#include "welcome.h"
#include "project.h"

ChooseVideo::ChooseVideo(QWidget *parent) :
    QWidget(parent)
{
    setFixedHeight(300);
    setFixedWidth(400);

    mainLayout = new QVBoxLayout(this);
    browse_layout=new QHBoxLayout;
    path_vid= new QLineEdit();
    choose= new QPushButton("Browse");
    browse_layout->addWidget(path_vid);
    browse_layout->addWidget(choose);
    mainLayout->addLayout(browse_layout);
    f_6= new QRadioButton("6 fps");
    f_6->setChecked(true);
    f_8= new QRadioButton("8 fps");
    f_12= new QRadioButton("12 fps");
    f_24= new QRadioButton("24 fps");
    mainLayout->addWidget(f_6);
    mainLayout->addWidget(f_8);
    mainLayout->addWidget(f_12);
    mainLayout->addWidget(f_24);
    buttonLayout = new QHBoxLayout;
    ret=new QPushButton("Return");
    ok=new QPushButton("Ok");
    buttonLayout->addWidget(ret);
    buttonLayout->addWidget(ok);
    mainLayout->addLayout(buttonLayout);

    QObject::connect(ret,SIGNAL(clicked()),this,SLOT(retour()));
    QObject::connect(ok,SIGNAL(clicked()),this,SLOT(suivant()));
    QObject::connect(choose,SIGNAL(clicked()),this,SLOT(browse()));

    freq=6;
    path="";

}


void ChooseVideo::browse(){
    QString fichier = QFileDialog::getOpenFileName(this, "Open a file", QString(), "Videos (*.avi *mp4 *.3pg *.wmv)");
    path_vid->setText(fichier);
}

void ChooseVideo::retour(){
    Welcome *w= new Welcome();
    w->show();
    this->close();
}

void ChooseVideo::suivant(){
    path=path_vid->text();
    bool valid=false;
    if(f_6->isChecked())
    {
        freq = 6;
        valid=true;
    }
    else if(f_8->isChecked())
    {
        freq = 8;
        valid=true;
    }
    else if(f_12->isChecked())
    {
        freq = 12;
        valid=true;
    }
    else if(f_24->isChecked())
    {
        freq = 24;
        valid=true;
    }
    if(valid && (path!="")){
        Project *p= new Project(QString("Untitled1"),path,freq);
        MainWindow *mainWin= new MainWindow(p);
        mainWin->show();
        this->close();
    }
}
