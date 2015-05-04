#include "previewzone.h"
#include <QMessageBox>
#include <QDebug>
PreviewZone::PreviewZone(QString lFolder,QWidget *parent) :
    QWidget(parent)
{
    layerFolder=lFolder;
    index=0;

    layout =new QHBoxLayout(this);
    //prev_btn=new QPushButton(tr("Prev Layer"));
    //suiv_btn=new QPushButton(tr("Next Layer"));

    //prev_btn->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Fixed);
    //suiv_btn->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Fixed);

    thumb_layout = new QHBoxLayout();

    if(layerFolder != "")
    {
        for(int i=0;i<(10);i++)
        {
             thumbs.push_back(new ThumbDisplayer(layerFolder + "/layer" + QString::number(index + i+1) +".png" , (index+1 - ((index)%10)) +i));
             QObject::connect(thumbs[i], SIGNAL(clicked(int)),this, SLOT(change(int)));
             thumb_layout->addWidget(thumbs[i]);
             index += 1;
         }

        thumbs[0]->setActive(true);
    }

    //layout->addWidget(prev_btn);
    layout->addLayout(thumb_layout);
    //layout->addWidget(suiv_btn);
}

void PreviewZone::createLayout(){

}

void PreviewZone::change(int current){

    thumbs[current-1]->setActive(true);
    for(int i=0;i<(10);i++){
        if(i!=(current-1)){
            thumbs[i]->setActive(false);
        }
    }
}
