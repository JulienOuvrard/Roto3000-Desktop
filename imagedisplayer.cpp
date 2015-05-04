#include "imagedisplayer.h"

ImageDisplayer::ImageDisplayer(QString imgFolder,QWidget *parent) :
    QWidget(parent)
{
    imageFolder=imgFolder;
    folder=new QDir(imageFolder);
    numberOfImage=folder->count()-2;

    index=1;
    layout=new QGridLayout(this);

    image=new QLabel("PAS D'IMAGE");

    displayAtIndex(0);
    layout->addWidget(image,0,0,0,0,Qt::AlignCenter);
}
void ImageDisplayer::displayAtIndex(int i){

    QString path=imageFolder+"/image"+QString::number(index+i)+".jpg";
    img = QImage(path);
    if(!img.isNull()){
        pix = pix.fromImage(img.scaled(850,450,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
        image->setPixmap(pix);
    }
}

int ImageDisplayer::getNumberOfImage(){
    return numberOfImage;
}

void ImageDisplayer::displayBackground(bool check){
    if(!check){
        image->hide();
    }else{
        image->show();
    }
}

void ImageDisplayer::goToNext(){
    if(index!=numberOfImage){
        index+=1;
    }
    displayAtIndex(index);
}

void ImageDisplayer::goToPrev(){
    if(index!=1){
        index-=1;
    }
    displayAtIndex(index);
}

void ImageDisplayer::goToImage(int i){
    index=0;
    displayAtIndex(i);
    index=i;
}
