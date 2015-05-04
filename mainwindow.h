#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "menubar.h"
#include "toolbox.h"
#include "layerbox.h"
#include "previewbox.h"
#include "previewzone.h"
#include "drawzone.h"
#include "navigationbox.h"
#include "editionbox.h"
#include "project.h"
#include "layerbackground.h"
#include "imagedisplayer.h"
#include <QLayout>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(Project *p, QWidget *parent = 0);

    QGridLayout *wait_layout;
    QLabel *waitingText;

    MenuBar *menu;
    QWidget *window;
    QSpacerItem *space;
    ToolBox *toolB;
    LayerBox *layerB;
    PreviewBox *previewB;
    EditionBox *edit;
    DrawZone *drawZ;
    NavigationBox *nav;
    PreviewZone *previewZ;
    LayerBackground *lback;

    QWidget *horizontalLineWidget;

    QVBoxLayout *mainLayout;
    QHBoxLayout *secondLayout;
    QVBoxLayout *leftLayout;
    QVBoxLayout *rightLayout;
    QGridLayout *workZone;

    Project *pro;
    ImageDisplayer *imgDisplay;
signals:

public slots:
    void displayProject();
};

#endif // MAINWINDOW_H
