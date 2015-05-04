#include "mainwindow.h"

MainWindow::MainWindow(Project *p, QWidget *parent) :
    QMainWindow(parent)
{
    setFixedHeight(770);
    setFixedWidth(1140);

    wait_layout=new QGridLayout(this);
    waitingText=new QLabel("Analysing the video ... Please wait");
    waitingText->setAlignment(Qt::AlignVCenter);
    wait_layout->addWidget(waitingText,0,0);

    pro=p;
    QObject::connect(pro,SIGNAL(projectIsReady()),this,SLOT(displayProject()));
}

void MainWindow::displayProject(){

    setWindowTitle(pro->getName()+QString(" - Roto3000"));

    menu=new MenuBar(this);
    setMenuBar(menu->getMenu());

    window=new QWidget();
    setCentralWidget(window);

    mainLayout= new QVBoxLayout(this);
    window->setLayout(mainLayout);

    secondLayout=new QHBoxLayout(this);
    mainLayout->addLayout(secondLayout);

    //coté gauche
    leftLayout= new QVBoxLayout(this);
    leftLayout->setSpacing(0);
    leftLayout->setMargin(0);
    leftLayout->setContentsMargins(0,0,0,0);

    space =new QSpacerItem(250,40);
    leftLayout->addSpacerItem(space);

    toolB=new ToolBox(this);
    leftLayout->addWidget(toolB,4);

    layerB=new LayerBox(this);
    leftLayout->addWidget(layerB,4);

    previewB=new PreviewBox(this);
    leftLayout->addWidget(previewB,2);

    secondLayout->addLayout(leftLayout);

    //coté droit
    rightLayout=new QVBoxLayout(this);

    edit = new EditionBox(this);
    rightLayout->addWidget(edit);

    workZone=new QGridLayout;
    workZone->setSpacing(0);
    workZone->setMargin(0);
    workZone->setContentsMargins(0,0,0,0);

    lback=new LayerBackground(this);

    imgDisplay=new ImageDisplayer(pro->getImages_path(),this);

    drawZ=new DrawZone(pro->getLayers_path(),this);
    drawZ->activeSave(true);
    drawZ->setStyleSheet("background:transparent");
    drawZ->setAttribute(Qt::WA_TranslucentBackground);
    drawZ->setWindowFlags(Qt::FramelessWindowHint);

    workZone->addWidget(lback,0,0,0,0,Qt::AlignCenter);
    workZone->addWidget(imgDisplay,0,0,0,0,Qt::AlignCenter);
    workZone->addWidget(drawZ,0,0,0,0,Qt::AlignCenter);

    rightLayout->addLayout(workZone);

    nav=new NavigationBox(imgDisplay->getNumberOfImage(),this);
    rightLayout->addWidget(nav);

    secondLayout->addLayout(rightLayout);

    //bas
    horizontalLineWidget = new QWidget;
    horizontalLineWidget->setFixedHeight(2);
    horizontalLineWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    horizontalLineWidget->setStyleSheet(QString("background-color: #c0c0c0;"));
    mainLayout->addWidget(horizontalLineWidget);

    previewZ=new PreviewZone(pro->getLayers_path(),this);
    mainLayout->addWidget(previewZ);

    show();

    QObject::connect(toolB,SIGNAL(color_changed(QColor)),drawZ,SLOT(setPenColor(QColor)));
    QObject::connect(toolB,SIGNAL(size_changed(int)),drawZ,SLOT(setPenWidth(int)));
    QObject::connect(toolB,SIGNAL(eraser_size_changed(int)),drawZ,SLOT(setEraserWidth(int)));
    QObject::connect(toolB,SIGNAL(pen_select(bool)),drawZ,SLOT(setPen(bool)));
    QObject::connect(toolB,SIGNAL(eraser_select(bool)),drawZ,SLOT(setEraser(bool)));
    QObject::connect(toolB,SIGNAL(background_displayed(bool)),imgDisplay,SLOT(displayBackground(bool)));

    QObject::connect(layerB,SIGNAL(layer_color_changed(QColor)),lback,SLOT(setBackgroundColor(QColor)));
    QObject::connect(layerB,SIGNAL(layer_reset()),drawZ,SLOT(resetImage()));

    QObject::connect(edit,SIGNAL(click_undo()),drawZ,SLOT(undo()));
    QObject::connect(edit,SIGNAL(click_redo()),drawZ,SLOT(redo()));

    QObject::connect(nav,SIGNAL(nextClicked()),imgDisplay,SLOT(goToNext()));
    QObject::connect(nav,SIGNAL(save(int)),drawZ,SLOT(saveImage(int)));
    QObject::connect(nav,SIGNAL(prevclicked()),imgDisplay,SLOT(goToPrev()));
    QObject::connect(nav,SIGNAL(load(int)),drawZ,SLOT(loadImage(int)));
    QObject::connect(nav,SIGNAL(goTo(int)),imgDisplay,SLOT(goToImage(int)));
}
