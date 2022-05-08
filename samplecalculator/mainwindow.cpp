#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    a.clear();
    b.clear();
    //绑定按键与处理函数
    connect(ui->pushButton_0,&QPushButton::clicked,[=](){ btn_logic(0);});
    connect(ui->pushButton_one,&QPushButton::clicked,[=](){ btn_logic(1);});
    connect(ui->pushButton_two,&QPushButton::clicked,[=](){ btn_logic(2);});
    connect(ui->pushButton_three,&QPushButton::clicked,[=](){ btn_logic(3);});
    connect(ui->pushButton_four,&QPushButton::clicked,[=](){ btn_logic(4);});
    connect(ui->pushButton_5,&QPushButton::clicked,[=](){ btn_logic(5);});
    connect(ui->pushButton_6,&QPushButton::clicked,[=](){ btn_logic(6);});
    connect(ui->pushButton_7,&QPushButton::clicked,[=](){ btn_logic(7);});
    connect(ui->pushButton_8,&QPushButton::clicked,[=](){ btn_logic(8);});
    connect(ui->pushButton_9,&QPushButton::clicked,[=](){ btn_logic(9);});


    //绑定运算符与处理函数
    connect(ui->pushButton_plus,&QPushButton::clicked,[=](){ btn_logic(0,"+");});
    connect(ui->pushButton_jian,&QPushButton::clicked,[=](){ btn_logic(0,"-");});
    connect(ui->pushButton_chen,&QPushButton::clicked,[=](){ btn_logic(0,"*");});
    connect(ui->pushButton_chu,&QPushButton::clicked,[=](){ btn_logic(0,"/");});
    connect(ui->pushButton_equel,&QPushButton::clicked,[=](){ btn_logic(0,"=");});

    //清空
    connect(ui->pushButton_clean,&QPushButton::clicked,[=](){
        a.clear();
        b.clear();
        ui->lineEdit->setText(a);//情况文本栏
    });

    //t退格按键响应
    connect(ui->pushButton_delete,&QPushButton::clicked,[=](){
        a.chop(1);
        ui->lineEdit->setText(a);//情况文本栏
    });


}

void MainWindow::btn_logic(int x,QString i)  //按键处理函数,参数1按键值且参数二为空，参数2 输入 " "为数字2为运算符
{
    if(i==" ")
    {
        a +=QString::number(x);
    }else if(x == 0)
    {//如果为运算符，则将lineedit内容存到b[0]中,运算符存储到b[1]中
        if(i != "=")
        {
            b.insert(0,a);
            a.clear();
            b.insert(1,i);
        }
        else
        {
            b.insert(2,a);
            den_logic();
        }


        }

    //对lineedit中内容进行显示
        ui->lineEdit->setText(a);
}


void MainWindow::den_logic()
{
    a.clear();
    if(b.at(1)=="+")
    {
        a += QString::number( QString(b.at(0)).toInt()+ QString(b.at(2)).toInt());


    }
    else if(b.at(1)=="-")
    {
        a += QString::number( QString(b.at(0)).toInt()- QString(b.at(2)).toInt());

    }
    else if(b.at(1)=="*")
    {
        a += QString::number( QString(b.at(0)).toInt()* QString(b.at(2)).toInt());

    }
    else if(b.at(1)=="/")
    {
        a += QString::number( QString(b.at(0)).toInt()/ QString(b.at(2)).toInt());

    }
    ui->lineEdit->setText(a);



}







MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_exit_clicked()
{
    close();
}
