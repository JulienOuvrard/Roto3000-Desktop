#ifndef VIDEOEDITING_H
#define VIDEOEDITING_H

#include <QWidget>
#include <QProcess>

class VideoEditing : public QWidget
{
    Q_OBJECT
public:
    explicit VideoEditing(QString vid, int fps, QWidget *parent = 0);

    int index;
    int framerate;
    bool isNewProject;
    QString video;
    QProcess* process;
    QProcess* process1;
    QProcess* process2;

    QProcess *exportProcess;
    QString command;
    QString command1;
    QString command2;

    QString imgFolder;
    QString layerFolder;
    QString currentImg;
    QString currentLayer;

    void buildFrame(QString folder, bool newP);
    QString getImgFolder();
    QString getLayerFolder();
    QString getCurrentImg();
    QString getCurrentLayer();
    QString goToNextImg();
    int frameNumber();

    void createVideo(QString path, int fps);

signals:
    void firstImageReady();
    void videoIsReady();
public slots:
    void imgReady();
    void videoReady();
};

#endif // VIDEOEDITING_H
