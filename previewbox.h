#ifndef PREVIEWBOX_H
#define PREVIEWBOX_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLayout>
#include <QGroupBox>

class PreviewBox : public QWidget
{
    Q_OBJECT
public:
    explicit PreviewBox(QWidget *parent = 0);

    QPushButton *preview_button;

    QGroupBox *preview_group;
    QVBoxLayout *firstLayout;

signals:

public slots:

};

#endif // PREVIEWBOX_H
