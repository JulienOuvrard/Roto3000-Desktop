#include "previewbox.h"


PreviewBox::PreviewBox(QWidget *parent) :
    QWidget(parent)
{
    preview_group=new QGroupBox(tr("Preview Box"), this);
    preview_group->setStyleSheet(QString("QGroupBox{border:2px solid gray;border-radius:5px;margin-top: 1ex;} QGroupBox::title{subcontrol-origin: margin;subcontrol-position:top center;padding:0 3px;}"));

    firstLayout=new QVBoxLayout;

    //preview button
    preview_button=new QPushButton(tr("Preview"));
    firstLayout->addWidget(preview_button);

    preview_group->setLayout(firstLayout);
}
