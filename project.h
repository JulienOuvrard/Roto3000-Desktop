#ifndef PROJECT_H
#define PROJECT_H

#include <QObject>
#include "videoediting.h"
class Project : public QObject
{
    Q_OBJECT
public:
    explicit Project(QString nom, QString video, int framerate,QObject *parent = 0);

    QString video_path;
    QString proj_path;
    QString images_path;
    QString layers_path;
    QString name;
    int freq;

    VideoEditing *vidEditor;

    QString getVideo_path() const;
    void setVideo_path(const QString &value);

    QString getProj_path() const;
    void setProj_path(const QString &value);

    QString getName() const;
    void setName(const QString &value);

    QString getImages_path() const;
    void setImages_path(const QString &value);

    QString getLayers_path() const;
    void setLayers_path(const QString &value);

signals:
    void projectIsReady();
public slots:
    void projectReady();
};

#endif // PROJECT_H
