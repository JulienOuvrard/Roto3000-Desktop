#ifndef TOOLBOX_H
#define TOOLBOX_H

#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QCheckBox>
#include <QSpinBox>
#include <QPushButton>
#include <QGroupBox>
#include <QColorDialog>

class ToolBox : public QWidget
{
    Q_OBJECT
public:
    explicit ToolBox(QWidget *parent = 0);

    QLabel *pen_label;
    QCheckBox *pen_ch;
    QLabel *size_label;
    QSpinBox *size_spin;
    QLabel *color_label;
    QPushButton *pen_color_btn;
    QLabel *eraser_label;
    QCheckBox *eraser_ch;
    QLabel *eraser_size_label;
    QSpinBox *eraser_size_spin;
    QLabel *bkg_label;
    QCheckBox *bkg_ch;

    QGroupBox *tool_group;
    QVBoxLayout *firstLayout;
    QHBoxLayout *pen_layout;
    QHBoxLayout *size_layout;
    QHBoxLayout *color_layout;
    QHBoxLayout *eraser_layout;
    QHBoxLayout *eraser_size_layout;
    QHBoxLayout *bkg_layout;

    QColor pen_color;
    QColor getPenColor();
signals:
    void pen_select(bool);
    void eraser_select(bool);
    void color_changed(QColor);
    void size_changed(int);
    void eraser_size_changed(int);
    void background_displayed(bool);
public slots:
    void choosePenColor();
    void choosePenSize(int);
    void chooseEraserSize(int);
    void pen_selection(bool);
    void eraser_selection(bool);
    void display_background(bool);
};

#endif // TOOLBOX_H
