#include "editionbox.h"

EditionBox::EditionBox(QWidget *parent) :
    QWidget(parent)
{
    edition_layout=new QHBoxLayout(this);
    edition_layout->setMargin(0);
    edition_layout->setSpacing(0);
    edition_layout->setContentsMargins(0,0,0,0);
    undo_btn=new QPushButton();
    redo_btn=new QPushButton();
    edition_layout->addWidget(redo_btn);
    edition_layout->addWidget(undo_btn);

    QPixmap undopix=QPixmap::fromImage((QImage(":/image/edit/edit_undo").scaled(35,35,Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    QPixmap redopix=QPixmap::fromImage((QImage(":/image/edit/edit_redo").scaled(35,35,Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));

    undo_btn->setIcon(QIcon(undopix));
    undo_btn->setFlat(true);
    undo_btn->setShortcut(QKeySequence("CTRL+Z"));
    undo_btn->setIconSize(undopix.size());
    redo_btn->setIcon(QIcon(redopix));
    redo_btn->setFlat(true);
    redo_btn->setShortcut(QKeySequence("CTRL+Y"));
    redo_btn->setIconSize(redopix.size());

    QObject::connect(undo_btn,SIGNAL(clicked()),this,SLOT(undo_clicked()));
    QObject::connect(redo_btn,SIGNAL(clicked()),this,SLOT(redo_clicked()));
}

void EditionBox::undo_clicked(){
    emit click_undo();
}

void EditionBox::redo_clicked(){
    emit click_redo();
}
