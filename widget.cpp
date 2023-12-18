#include "widget.h"
#include "ui_widget.h"
#include<QColorDialog>
#include"convert.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    colorInRGB = RGB();
    colorInXYZ = XYZ();
    colorInLAB = LAB();

    warningMessage = QString("");

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    QColor color = QColorDialog::getColor(Qt::white, this, "Выберите цвет");
    if (color.isValid()) {
        ui->widget->setStyleSheet("background-color: " + color.name() + ";");

        warningMessage = "";


        colorInRGB.setR(color.red());
        colorInRGB.setG(color.green());

        colorInRGB.setB(color.blue());
        handleRGB();
        changeRGB_Area();

        colorInXYZ = Convert::convertRGB_TO_XYZ(colorInRGB);
        handleXYZ();
        changeXYZ_Area();

        colorInLAB = Convert::convertXYZ_TO_LAB(colorInXYZ);
        handleLAB();
        changeLAB_Area();

         ui->label_14->setText(warningMessage);
        warningMessage = "";
    }
}


void Widget::on_doubleSpinBox_8_valueChanged(double arg1)
{
    colorInRGB.setR(arg1);
    changeRGB_Coordinate();
}

void Widget::changeRGB_Area()
{
    ui->doubleSpinBox_8->blockSignals(true);
    ui->doubleSpinBox_9->blockSignals(true);
    ui->doubleSpinBox_7->blockSignals(true);

    ui->doubleSpinBox_8->setValue(colorInRGB.getR());
    ui->doubleSpinBox_9->setValue(colorInRGB.getG());
    ui->doubleSpinBox_7->setValue(colorInRGB.getB());

    ui->doubleSpinBox_8->blockSignals(false);
    ui->doubleSpinBox_9->blockSignals(false);
    ui->doubleSpinBox_7->blockSignals(false);
}

void Widget::changeXYZ_Area()
{
    ui->doubleSpinBox->blockSignals(true);
    ui->doubleSpinBox_2->blockSignals(true);
    ui->doubleSpinBox_3->blockSignals(true);

    ui->doubleSpinBox->setValue(colorInXYZ.getX());
    ui->doubleSpinBox_2->setValue(colorInXYZ.getY());
    ui->doubleSpinBox_3->setValue(colorInXYZ.getZ());

    ui->doubleSpinBox->blockSignals(false);
    ui->doubleSpinBox_2->blockSignals(false);
    ui->doubleSpinBox_3->blockSignals(false);
}

void Widget::changeLAB_Area()
{
    ui->doubleSpinBox_5->blockSignals(true);
    ui->doubleSpinBox_4->blockSignals(true);
    ui->doubleSpinBox_6->blockSignals(true);

    ui->doubleSpinBox_5->setValue(colorInLAB.getL());
    ui->doubleSpinBox_4->setValue(colorInLAB.getA());
    ui->doubleSpinBox_6->setValue(colorInLAB.getB());

    ui->doubleSpinBox_5->blockSignals(false);
    ui->doubleSpinBox_4->blockSignals(false);
    ui->doubleSpinBox_6->blockSignals(false);
}

void Widget::changeRGB_Coordinate()
{
    colorInXYZ = Convert::convertRGB_TO_XYZ(colorInRGB);
    handleXYZ();

    colorInLAB = Convert::convertXYZ_TO_LAB(colorInXYZ);
    handleLAB();

    ui->label_14->setText(warningMessage);
    warningMessage = "";

    changeXYZ_Area();
    changeLAB_Area();

    QColor color = QColor(colorInRGB.getR(),colorInRGB.getG(),colorInRGB.getB());
    ui->widget->setStyleSheet("background-color: " + color.name() + ";");
}

void Widget::changeXYZ_Coordinate()
{  
    colorInRGB = Convert::convertXYZ_TO_RGB(colorInXYZ);
    handleRGB();

    colorInLAB = Convert::convertXYZ_TO_LAB(colorInXYZ);
    handleLAB();

    ui->label_14->setText(warningMessage);
    warningMessage = "";

    changeRGB_Area();
    changeLAB_Area();

    QColor color = QColor(colorInRGB.getR(),colorInRGB.getG(),colorInRGB.getB());
    ui->widget->setStyleSheet("background-color: " + color.name() + ";");
}

void Widget::changeLAB_Coordinate()
{
    colorInRGB = Convert::convertLAB_TO_RGB(colorInLAB);
    handleRGB();

    colorInXYZ = Convert::convertLAB_TO_XYZ(colorInLAB);
    handleXYZ();

    ui->label_14->setText(warningMessage);
    warningMessage = "";
    changeRGB_Area();
    changeXYZ_Area();

    qDebug()<<colorInRGB.getR();
    qDebug()<<colorInRGB.getG();
    qDebug()<<colorInRGB.getB();
    qDebug()<<Qt::endl;

    QColor color = QColor(colorInRGB.getR(),colorInRGB.getG(),colorInRGB.getB());
    ui->widget->setStyleSheet("background-color: " + color.name() + ";");
}

void Widget::handleRGB()
{
    double r,g,b;
    r = colorInRGB.getR();
    g = colorInRGB.getG();
    b = colorInRGB.getB();

    if(r<0){
        colorInRGB.setR(0);
        warningMessage += ("R вышла за нижнюю границу и ей было присвоено значение 0\n");
    }else if(r>255){
        colorInRGB.setR(255);
        warningMessage += ("R вышла за верхнюю границу и ей было присвоено значение 255\n");
    }

    if(g<0){
        colorInRGB.setG(0);
        warningMessage += ("G вышла за нижнюю границу и ей было присвоено значение 0\n");
    }else if(g>255){
        colorInRGB.setG(255);
        warningMessage += ("G вышла за верхнюю границу и ей было присвоено значение 255\n");
    }

    if(b<0){
        colorInRGB.setB(0);
        warningMessage += ("B вышла за нижнюю границу и ей было присвоено значение 0\n");
    }else if(b>255){
        colorInRGB.setB(255);
        warningMessage += ("B вышла за верхнюю границу и ей было присвоено значение 255\n");
    }

}

void Widget::handleXYZ()
{
    double x,y,z;
    x = colorInXYZ.getX();
    y = colorInXYZ.getY();
    z = colorInXYZ.getZ();

    if(x<0){
        colorInXYZ.setX(0);
        warningMessage += ("X вышла за нижнюю границу и ей было присвоено значение 0\n");
    }else if(x>95.047){
        colorInXYZ.setX(95.047);
        warningMessage += ("X вышла за верхнюю границу и ей было присвоено значение 95.047\n");
    }

    if(y<0){
        colorInXYZ.setY(0);
        warningMessage += ("Y вышла за нижнюю границу и ей было присвоено значение 0\n");
    }else if(y>100){
        colorInXYZ.setY(100);
        warningMessage += ("Y вышла за верхнюю границу и ей было присвоено значение 100\n");
    }

    if(z<0){
        colorInXYZ.setZ(0);
        warningMessage += ("Z вышла за нижнюю границу и ей было присвоено значение 0\n");
    }else if(x>95.047){
        colorInXYZ.setZ(108.883);
        warningMessage += ("Z вышла за верхнюю границу и ей было присвоено значение 108.883\n");
    }
}

void Widget::handleLAB()
{
    double l,a,b;
    l = colorInLAB.getL();
    a = colorInLAB.getA();
    b = colorInLAB.getB();

    if(l<0){
        colorInLAB.setL(0);
        warningMessage += ("L вышла за нижнюю границу и ей было присвоено значение 0\n");
    }else if(l>100){
        colorInLAB.setL(100);
        warningMessage += ("L вышла за верхнюю границу и ей было присвоено значение 100\n");
    }

    if(a<-128){
        colorInLAB.setA(-128);
        warningMessage += ("A вышла за нижнюю границу и ей было присвоено значение -128\n");
    }else if(a>128){
        colorInLAB.setA(128);
        warningMessage += ("A вышла за верхнюю границу и ей было присвоено значение 128\n");
    }

    if(b<-128){
        colorInLAB.setB(-128);
        warningMessage += ("B вышла за нижнюю границу и ей было присвоено значение 0\n");
    }else if(b>128){
        colorInLAB.setL(128);
        warningMessage += ("B вышла за верхнюю границу и ей было присвоено значение 100\n");
    }
}


void Widget::on_doubleSpinBox_9_valueChanged(double arg1)
{
    colorInRGB.setG(arg1);
    changeRGB_Coordinate();
}


void Widget::on_doubleSpinBox_7_valueChanged(double arg1)
{

    colorInRGB.setB(arg1);
    changeRGB_Coordinate();
}



void Widget::on_doubleSpinBox_valueChanged(double arg1)
{
    colorInXYZ.setX(arg1);
    changeXYZ_Coordinate();
}


void Widget::on_doubleSpinBox_2_valueChanged(double arg1)
{
    colorInXYZ.setY(arg1);
    changeXYZ_Coordinate();
}


void Widget::on_doubleSpinBox_3_valueChanged(double arg1)
{
    colorInXYZ.setZ(arg1);
    changeXYZ_Coordinate();
}


void Widget::on_doubleSpinBox_5_valueChanged(double arg1)
{
    colorInLAB.setL(arg1);
    changeLAB_Coordinate();
}


void Widget::on_doubleSpinBox_4_valueChanged(double arg1)
{
    colorInLAB.setA(arg1);
    changeLAB_Coordinate();
}


void Widget::on_doubleSpinBox_6_valueChanged(double arg1)
{
    colorInLAB.setB(arg1);
    changeLAB_Coordinate();
}

