#include "videoediting.h"
#include <QFile>
#include <QDir>
#include <QPainter>
VideoEditing::VideoEditing(QString vid, int fps, QWidget *parent) :
    QWidget(parent)
{
    index = 1;
    framerate = fps;
    video = vid;
    process = new QProcess();
}

void VideoEditing::buildFrame(QString folder, bool newP)
{
    layerFolder = QString(folder+"/layers");
    imgFolder = QString(folder+"/images");
    currentImg = QString(imgFolder + "/image1.jpg");
    currentLayer = QString(layerFolder + "/layer1.png");

    isNewProject = newP;
    if(isNewProject)
    {
        //creation du dossier images
        process1 = new QProcess();
        command1 = "mkdir " +folder +"/images";
        process1->start(command1);

        //creation du dossier layers
        process2 = new QProcess();
        command2 = "mkdir " +folder +"/layers";
        process2->start(command2);
    }

    //creation des images
    command = "avconv -i "+video+" -vsync 1 -r "+QString::number(framerate)+" -an -y " + imgFolder +"/image%d.jpg";
    process->start(command);
    connect(process,SIGNAL(finished(int)),this,SLOT(imgReady()));

}


QString VideoEditing::getImgFolder()
{
    return imgFolder;
}

QString VideoEditing::getLayerFolder()
{
    return layerFolder;
}

QString VideoEditing::getCurrentImg()
{
    return currentImg;
}
QString VideoEditing::getCurrentLayer()
{
    return currentLayer;
}


QString VideoEditing::goToNextImg()
{
    index += 1;
    currentImg = QString(imgFolder + "/image" + QString::number(index) +".jpg");
    currentLayer = QString(layerFolder + "/layer" + QString::number(index) +".png");
    return currentImg;
}

int VideoEditing::frameNumber()
{
    int res =0;
    QFile *img = new QFile(imgFolder + "/image" + QString::number(res+1) +".jpg");
    while((img->exists()))
    {
        res++;
        img = new QFile(imgFolder + "/image" + QString::number(res+1) +".jpg");
    }
    return res;
}

void VideoEditing::imgReady()
{
    //creation de tous les layers
    if(isNewProject)
    {
        QImage *image = new QImage(850,450,QImage::Format_ARGB32_Premultiplied);
        for(int i =1; i<=frameNumber();i++)
        {
            image->save(layerFolder+ "/layer" + QString::number(i)+ ".png");
        }
     }
     emit firstImageReady();
}

void VideoEditing::createVideo(QString path, int fps)
{
    //creation d un dossier d'image temporairedes
    QDir dir(layerFolder + "/LayerTemp");
    dir.mkpath(layerFolder + "/LayerTemp");

    for(int i=1;i<=frameNumber();i++)
    {
        QImage image1 =QImage(850,450,QImage::Format_ARGB32_Premultiplied);
        image1.fill(Qt::white);

        QImage image2 = QImage(layerFolder + "/layer" + QString::number(i) +".png");
        QPixmap pix = pix.fromImage(image2);
        QPainter painter(&image1);
        painter.drawPixmap(0,0,pix);
        painter.end();

        image1.save(layerFolder + "/LayerTemp/dessin" + QString::number(i) + ".png");
    }


    exportProcess = new QProcess();
    QString command = "avconv -f image2 -framerate "+ QString::number(fps)+" -i " + layerFolder+ "/LayerTemp/layer%d.png -vcodec mpeg4 -r " +QString::number(fps)+" " +path + ".mp4";

    exportProcess->start(command);
    connect(exportProcess,SIGNAL(finished(int)),this,SLOT(videoReady()));

}

void VideoEditing::videoReady()
{
    emit videoIsReady();
}
