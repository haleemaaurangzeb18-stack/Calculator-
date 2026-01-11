#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    firstNumber = 0;

    this->setStyleSheet(R"(

QMainWindow {
    background-color: #0d47a1;   /* deep blue */
}

/* Display */
QLineEdit {
    background-color: #e3f2fd;   /* very light blue */
    border: 2px solid #1565c0;
    border-radius: 10px;
    padding: 8px;
    font-size: 22px;
    color: #0d47a1;
}

/* All buttons */
QPushButton {
    background-color: #1976d2;   /* primary blue */
    border: none;
    border-radius: 12px;
    font-size: 18px;
    color: white;
}

/* Hover effect */
QPushButton:hover {
    background-color: #1565c0;
}

/* Press effect */
QPushButton:pressed {
    background-color: #0d47a1;
}

/* Operator buttons */
QPushButton#btnAdd,
QPushButton#btnSub,
QPushButton#btnMul,
QPushButton#btnDiv,
QPushButton#btnMod {
    background-color: #1e88e5;
    font-weight: bold;
}

/* Equal button */
QPushButton#btnEqual {
    background-color: #0d47a1;
    font-size: 20px;
    font-weight: bold;
}

/* Clear button (optional) */
QPushButton#btnClear {
    background-color: #42a5f5;
}

)");
}

MainWindow::~MainWindow()
{
    delete ui;
}

// ---- NUMBER BUTTONS ----
void MainWindow::on_btn0_clicked(){ ui->display->setText(ui->display->text() + "0"); }
void MainWindow::on_btn1_clicked(){ ui->display->setText(ui->display->text() + "1"); }
void MainWindow::on_btn2_clicked(){ ui->display->setText(ui->display->text() + "2"); }
void MainWindow::on_btn3_clicked(){ ui->display->setText(ui->display->text() + "3"); }
void MainWindow::on_btn4_clicked(){ ui->display->setText(ui->display->text() + "4"); }
void MainWindow::on_btn5_clicked(){ ui->display->setText(ui->display->text() + "5"); }
void MainWindow::on_btn6_clicked(){ ui->display->setText(ui->display->text() + "6"); }
void MainWindow::on_btn7_clicked(){ ui->display->setText(ui->display->text() + "7"); }
void MainWindow::on_btn8_clicked(){ ui->display->setText(ui->display->text() + "8"); }
void MainWindow::on_btn9_clicked(){ ui->display->setText(ui->display->text() + "9"); }

// ---- OPERATORS ----
void MainWindow::on_btnAdd_clicked()
{
    firstNumber = ui->display->text().toDouble();
    operation = "+";
    ui->display->clear();
}

void MainWindow::on_btnSub_clicked()
{
    firstNumber = ui->display->text().toDouble();
    operation = "-";
    ui->display->clear();
}

void MainWindow::on_btnMul_clicked()
{
    firstNumber = ui->display->text().toDouble();
    operation = "*";
    ui->display->clear();
}

void MainWindow::on_btnDiv_clicked()
{
    firstNumber = ui->display->text().toDouble();
    operation = "/";
    ui->display->clear();
}

void MainWindow::on_btnMod_clicked()
{
    firstNumber = ui->display->text().toDouble();
    operation = "%";
    ui->display->clear();
}

// ---- EQUAL ----
void MainWindow::on_btnEqual_clicked()
{
    double secondNumber = ui->display->text().toDouble();
    double result = 0;

    if (operation == "+")
        result = firstNumber + secondNumber;
    else if (operation == "-")
        result = firstNumber - secondNumber;
    else if (operation == "*")
        result = firstNumber * secondNumber;
    else if (operation == "/")
        result = secondNumber != 0 ? firstNumber / secondNumber : 0;
    else if (operation == "%")
        result = int(firstNumber) % int(secondNumber);

    ui->display->setText(QString::number(result));
}

// ---- CLEAR ----
void MainWindow::on_btnClear_clicked()
{
    ui->display->clear();
    firstNumber = 0;
    operation = "";
}
