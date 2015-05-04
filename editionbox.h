#ifndef EDITIONBOX_H
#define EDITIONBOX_H

#include <QWidget>
#include <QLayout>
#include <QPushButton>

class EditionBox : public QWidget
{
    Q_OBJECT
public:
    explicit EditionBox(QWidget *parent = 0);

    QHBoxLayout *edition_layout;
    QPushButton *undo_btn;
    QPushButton *redo_btn;
signals:
    void click_undo();
    void click_redo();
public slots:
    void undo_clicked();
    void redo_clicked();

};

#endif // EDITIONBOX_H
