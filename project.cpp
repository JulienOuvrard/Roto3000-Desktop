#include "project.h"
#include <QDir>
Project::Project(QString nom, QString video, int framerate, QObject *parent) :
    QObject(parent)
{
    name=nom;
    video_path=video;
    freq=framerate;

    vidEditor = new VideoEditing(video_path,freq);
    proj_path = QDir::homePath()+QString("/Documents/R3000/")+name;
    QDir projectDir(proj_path);
    projectDir.mkpath(proj_path);
    vidEditor->buildFrame(proj_path,true);

    images_path=proj_path+"/images";
    layers_path=proj_path+"/layers";
    QObject::connect(vidEditor,SIGNAL(firstImageReady()),this,SLOT(projectReady()));
}

QString Project::getLayers_path() const
{
    return layers_path;
}

void Project::setLayers_path(const QString &value)
{
    layers_path = value;
}

QString Project::getImages_path() const
{
    return images_path;
}

void Project::setImages_path(const QString &value)
{
    images_path = value;
}


QString Project::getName() const
{
    return name;
}

void Project::setName(const QString &value)
{
    name = value;
}

QString Project::getProj_path() const
{
    return proj_path;
}

void Project::setProj_path(const QString &value)
{
    proj_path = value;
}

QString Project::getVideo_path() const
{
    return video_path;
}

void Project::setVideo_path(const QString &value)
{
    video_path = value;
}

void Project::projectReady(){
    emit projectIsReady();
}
