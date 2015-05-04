#ifndef DRAWZONE_H
#define DRAWZONE_H

#include <QWidget>
#include <QPen>

class DrawZone : public QWidget
{
    Q_OBJECT
public:
    explicit DrawZone(QString path, QWidget *parent = 0);

    bool draw;
    bool erase;
    bool save;

    QPoint pos;
    QPen pen;
    QPen eraser;

    QImage *prev;
    QImage *next;
    QImage *image;

    QString imgPath;
    QImage  img;


    void saveImage();
    void saveImage(QString path);
    void loadImage(QString path);
    void activeSave(bool active);

    void setSize(int weight , int height);
    QColor getPenColor();
    int getPenWidth();

    void paintEvent(QPaintEvent *e);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

signals:

public slots:
    void setPenColor(QColor);
    void setPenWidth(int);
    void setEraser(bool);
    void setPen(bool);
    void setEraserWidth(int);
    void resetImage();
    void undo();
    void redo();
    void saveImage(int);
    void loadImage(int);
};

#endif // DRAWZONE_H
