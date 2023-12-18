#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <rgb.h>
#include <xyz.h>
#include <lab.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void on_doubleSpinBox_8_valueChanged(double arg1);

    void on_doubleSpinBox_9_valueChanged(double arg1);

    void on_doubleSpinBox_7_valueChanged(double arg1);

    void on_doubleSpinBox_valueChanged(double arg1);

    void on_doubleSpinBox_5_valueChanged(double arg1);

    void on_doubleSpinBox_2_valueChanged(double arg1);

    void on_doubleSpinBox_3_valueChanged(double arg1);

    void on_doubleSpinBox_4_valueChanged(double arg1);

    void on_doubleSpinBox_6_valueChanged(double arg1);

private:
    Ui::Widget *ui;

    RGB colorInRGB;
    XYZ colorInXYZ;
    LAB colorInLAB;

    QString warningMessage;

    void changeRGB_Area();
    void changeXYZ_Area();
    void changeLAB_Area();

    void changeRGB_Coordinate();
    void changeXYZ_Coordinate();
    void changeLAB_Coordinate();

    void handleRGB();
    void handleXYZ();
    void handleLAB();
};
#endif // WIDGET_H
