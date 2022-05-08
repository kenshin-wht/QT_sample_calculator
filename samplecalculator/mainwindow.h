#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void btn_logic(int x,QString i = " ");
    void den_logic();

public:
    QString a;     //存储LineEdit显示
    QStringList b;    //定义b用来存储运算符等

private slots:
    void on_pushButton_exit_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
