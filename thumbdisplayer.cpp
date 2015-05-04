#include "thumbdisplayer.h"

ThumbDisplayer::ThumbDisplayer(QString name, int i,QWidget *parent) :
    QWidget(parent)
{
    state=0;
    path=name;
    index=i;
    isActive=false;
    layout = new QGridLayout(this);

    if(isActive){
        setPalette(QPalette(QColor(Qt::blue)));
        setAutoFillBackground(true);
    }else{
        setPalette(QPalette(QColor(Qt::gray)));
        setAutoFillBackground(true);
    }

    indexL = new QLabel(QString::number(index));
    QSizePolicy spInfo(QSizePolicy::Preferred, QSizePolicy::Preferred);
    spInfo.setVerticalStretch(1);
    indexL->setSizePolicy(spInfo);
    indexL->setAlignment(Qt::AlignHCenter);

    layout->addWidget(indexL,1,1);

    image = new QLabel("test");
    img = QImage(path);
    pix = pix.fromImage(img.scaled(90,90,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    image->setPixmap(pix);
    QSizePolicy spInfo2(QSizePolicy::Preferred, QSizePolicy::Preferred);
    spInfo2.setVerticalStretch(3);
    image->setSizePolicy(spInfo2);

    layout->addWidget(image,0,1);

}

void ThumbDisplayer::setActive(bool ac){
    isActive=ac;
    if(isActive){
        displayBackground();
    }else{
        setPalette(QPalette(QColor(Qt::gray)));
        setAutoFillBackground(true);
    }
}

void ThumbDisplayer::displayBackground(){
    setPalette(QPalette(QColor(Qt::blue)));
    setAutoFillBackground(true);

}

void ThumbDisplayer::mousePressEvent(QMouseEvent *e){
    state=1;
    emit pressed(index);
}

void ThumbDisplayer::mouseReleaseEvent(QMouseEvent *e){
    state=0;
    emit release(index);
    emit clicked(index);
}

