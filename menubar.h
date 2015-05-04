#ifndef MENUBAR_H
#define MENUBAR_H

#include <QWidget>
#include <QMenuBar>

class MenuBar : public QWidget
{
    Q_OBJECT

public:
    explicit MenuBar(QWidget *parent = 0);
    QMenuBar* getMenu();

    QMenuBar *barre_menu;

    QMenu *project;
    QMenu *video;
    QMenu *preview;
    QMenu *exportP;

    QAction *newP;
    QAction *openP;
    QAction *saveP;
    QAction *quit;
    QAction *videoP;
    QAction *settingsV;
    QAction *previewP;
    QAction *previewN;
    QAction *exportV;
    QAction *exportI;
    QAction *exportB;

signals:

public slots:

};

#endif // MENUBAR_H
