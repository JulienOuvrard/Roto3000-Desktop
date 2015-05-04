#include "drawzone.h"
#include <QPainter>
#include <QMouseEvent>

DrawZone::DrawZone(QString path,QWidget *parent) :
    QWidget(parent)
{
    setFixedHeight(450);
    setFixedWidth(850);

    draw=false;
    erase=false;

    pen.setColor(Qt::black);
    pen.setStyle(Qt::SolidLine);
    pen.setCapStyle(Qt::RoundCap);

    eraser.setColor(Qt::white);
    eraser.setStyle(Qt::SolidLine);
    eraser.setCapStyle(Qt::RoundCap);

    pos=QPoint(0,0);

    image= new QImage(850,450,QImage::Format_ARGB32_Premultiplied);
    prev= new QImage(850,450,QImage::Format_ARGB32_Premultiplied);
    next= new QImage(850,450,QImage::Format_ARGB32_Premultiplied);

    imgPath = path;
    save=false;
}

void DrawZone::setPenColor(QColor color)
{
    pen.setColor(color);
}

void DrawZone::setPenWidth(int width)
{
    pen.setWidth(width);
}
void DrawZone::setEraserWidth(int width)
{
    eraser.setWidth(width);
}

void DrawZone::setSize(int width , int height)
{
    setFixedSize(width,height);
}

void DrawZone::setEraser(bool isRubber)
{
    erase = isRubber;
}
void DrawZone::setPen(bool isPen)
{
    draw = isPen;
}

int DrawZone::getPenWidth()
{
    return pen.width();
}

QColor DrawZone::getPenColor()
{
    return pen.color();
}

void DrawZone::activeSave(bool active)
{
    save = active;
}

void DrawZone::resetImage()
{
    image= new QImage(850,450,QImage::Format_ARGB32_Premultiplied);
    prev= new QImage(850,450,QImage::Format_ARGB32_Premultiplied);
    next= new QImage(850,450,QImage::Format_ARGB32_Premultiplied);
    update();
}

void DrawZone::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.setPen(pen);
    painter.drawImage(0,0,*image);
}

void DrawZone::mouseMoveEvent(QMouseEvent *event)
{
    if(draw)
    {
        if(erase)
        {
            QPainter painter(image);
            painter.setPen(eraser);
            painter.setCompositionMode( QPainter::CompositionMode_Clear );
            painter.eraseRect(QRectF(event->pos().x()-(eraser.width()/2),event->pos().y()-(eraser.width()/2),eraser.width(),eraser.width()));
            painter.setCompositionMode( QPainter::CompositionMode_SourceOver );
            pos = event->pos();
            update();
        }
        else
        {
            QPainter painter(image);
            painter.setPen(pen);
            painter.drawLine(pos,event->pos());
            pos = event->pos();
            update();
        }
    }
}

void DrawZone::mousePressEvent(QMouseEvent *event)
{
    draw = true;
    prev = new QImage(image->copy());
    pos = event->pos();
    if(!erase)
    {
        QPainter painter(image);
        painter.setPen(pen);
        painter.drawPoint(event->pos());
        update();
    }
}

void DrawZone::mouseReleaseEvent(QMouseEvent *event)
{
   draw = false;
   pos = QPoint(0,0);
}

void DrawZone::undo()
{
    next = new QImage(image->copy());
    image = new QImage(prev->copy());
    if(save){saveImage();}
    update();
}

void DrawZone::redo()
{
    prev = new QImage(image->copy());
    image = new QImage(next->copy());
    if(save){saveImage();}
    update();
}

void DrawZone::saveImage(int i){
    QString p=imgPath+"/layer"+QString::number(i)+".png";
    saveImage(p);
    resetImage();
}

void DrawZone::saveImage()
{
    image->save(imgPath);
}

void DrawZone::saveImage(QString path)
{
    image->save(path);
}

void DrawZone::loadImage(QString path)
{
    if(QFile(path).exists())
    {
        resetImage();
        imgPath = path;
        QImage img(path);
        image = new QImage(img.scaled(850,450,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
        prev = image;
        next = image;
    }
    else
    {
        resetImage();
        imgPath = path;
        image->save(path);
    }
    update();
}

void DrawZone::loadImage(int i){
    saveImage(i+1);
    resetImage();
    QString p=imgPath+"/layer"+QString::number(i)+".png";
    QImage img(p);
    image = new QImage(img.scaled(850,450,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    prev = image;
    next = image;
}
