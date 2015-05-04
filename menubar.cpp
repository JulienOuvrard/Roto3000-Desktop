#include "menubar.h"

MenuBar::MenuBar(QWidget *parent) :
    QWidget(parent)
{
    //barre de menu
    barre_menu = new QMenuBar(parent);
    barre_menu->setVisible(true);
    barre_menu->setNativeMenuBar(false);

    //menu projet
    project = new QMenu("Project");
    barre_menu->addMenu(project);

    newP = new QAction(this);
    newP->setText(QString::fromUtf8("New Project"));
    newP->setShortcut(QKeySequence("CTRL+N"));
    project->addAction(newP);

    openP = new QAction(this);
    openP->setText(QString::fromUtf8("Open Project"));
    openP->setShortcut(QKeySequence("CTRL+O"));
    project->addAction(openP);

    saveP = new QAction(this);
    saveP->setText(QString::fromUtf8("Save Project"));
    saveP->setShortcut(QKeySequence("CTRL+S"));
    project->addAction(saveP);

    project->addSeparator();

    quit = new QAction(this);
    quit->setText(QString::fromUtf8("Quit"));
    quit->setShortcut(QKeySequence("CTRL+Q"));
    project->addAction(quit);

    //menu video
    video = new QMenu("Video");
    barre_menu->addMenu(video);

    videoP = new QAction(this);
    videoP->setText(QString::fromUtf8("Choose your video"));
    videoP->setShortcut(QKeySequence("CTRL+M"));
    video->addAction(videoP);

    settingsV = new QAction(this);
    settingsV->setText(QString::fromUtf8("Change your settings"));
    settingsV->setShortcut(QKeySequence("CTRL+H"));
    video->addAction(settingsV);

    //menu preview
    preview = new QMenu("Preview");
    barre_menu->addMenu(preview);

    previewP = new QAction(this);
    previewP->setText(QString::fromUtf8("Preview all animation"));
    previewP->setShortcut(QKeySequence("CTRL+P"));
    preview->addAction(previewP);

    previewN = new QAction(this);
    previewN->setText(QString::fromUtf8("Preview n last pictures"));
    previewN->setShortcut(QKeySequence("CTRL+L"));
    preview->addAction(previewN);

    //menu export
    exportP = new QMenu("Export");
    barre_menu->addMenu(exportP);

    exportV = new QAction(this);
    exportV->setText(QString::fromUtf8("Export video"));
    exportV->setShortcut(QKeySequence("CTRL+E"));
    exportP->addAction(exportV);

    exportI = new QAction(this);
    exportI->setText(QString::fromUtf8("Export images"));
    exportI->setShortcut(QKeySequence("CTRL+I"));
    exportP->addAction(exportI);

    exportB = new QAction(this);
    exportB->setText(QString::fromUtf8("Export both(images+video)"));
    exportB->setShortcut(QKeySequence("CTRL+B"));
    exportP->addAction(exportB);

}

QMenuBar *MenuBar::getMenu(){
    return barre_menu;
}
