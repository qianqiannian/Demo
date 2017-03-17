#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QMessageBox>
#include <QFileDialog>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    isSaved(false),
    curFile("未命名.txt")
{
    ui->setupUi(this);
    setWindowTitle(curFile);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::do_file_New()
{
    //  新建文件,先要判断正在编辑的文件是否需要保存。然后将新建的文件标志为未保存过状态
    do_file_SaveOrNot();
    isSaved = false;
    curFile = tr("未命名.txt");
    setWindowTitle(curFile);
    ui->textEdit->clear();
    ui->textEdit->setVisible(true);
}

void MainWindow::do_file_Save()
{
    //  对文件进行保存时,先判断其是否已经被保存过,如果没有被保存过,就要先对其进行另存为操作。

    if (isSaved) {  // 如果文件已经被保存过,直接保存文件
        saveFile(curFile);
    }
    else {
        do_file_SaveAs();   // 如果文件是第一次保存,那么调用另存为
    }
}

void MainWindow::do_file_SaveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("另存为"), curFile); // 获得文件名
    if (!fileName.isEmpty()) {
        saveFile(fileName);
    }
}

bool MainWindow::saveFile(const QString &fileName)
{
    //  这个函数实现将文本文件进行存储
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("保存文件"), tr ("无法保存文件 %1: \n %2").arg(fileName).arg(file.errorString()));
        return false;
    }
    QTextStream out(&file);
    out<<ui->textEdit->toPlainText();   //将文本编辑器里的内容以纯文本的形式输出到流对象中
    isSaved = true;
    curFile = QFileInfo(fileName).canonicalFilePath();  //获得文件的标准路径
    setWindowTitle(curFile);
    return true;
}

void MainWindow::do_file_SaveOrNot()
{
    //  这个函数实现弹出一个对话框,询问是否保存正在编辑的文件。
    if (ui->textEdit->document()->isModified()) {
        QMessageBox box;
        box.setWindowTitle(tr("警告"));
        box.setIcon(QMessageBox::Warning);
        box.setText(curFile + tr("尚未保存,是否保存?"));
        box.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        if (box.exec() == QMessageBox::Yes) {
            do_file_Save();
        }
        else {
            ui->textEdit->clear();      // 如果不保存,则将文本框内的内容删除
        }
    }
}

void MainWindow::do_file_Open()
{
    do_file_SaveOrNot();
    QString fileName = QFileDialog::getOpenFileName(this);

    if (!fileName.isEmpty()) {
        do_file_Load(fileName);
    }
    ui->textEdit->setVisible(true);
}

bool MainWindow::do_file_Load(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this,tr("读取文件"),tr("无法读取文件 %1:\n%2.").arg(fileName).arg(file.errorString()));
        return false;
    }

    QTextStream in(&file);
    ui->textEdit->setText(in.readAll());    // 将文件中的所有内容都写到文本编辑器中
    curFile = QFileInfo(fileName).canonicalFilePath();
    setWindowTitle(curFile);
    return true;
}

void MainWindow::on_action_triggered()
{
    do_file_New();
}

void MainWindow::on_action_5_triggered()
{
    do_file_Save();
}

void MainWindow::on_action_4_triggered()
{
    do_file_SaveAs();
}

void MainWindow::on_action_2_triggered()
{
    do_file_Open();
}

void MainWindow::on_action_3_triggered()
{
    do_file_SaveOrNot();
    ui->textEdit->setVisible(false);
}

void MainWindow::on_action_7_triggered()
{
    on_action_3_triggered();    //先执行关闭操作
    qApp->quit();   //再退出系统,qApp 是指向应用程序的全局指针
}

void MainWindow::on_action_Z_triggered()
{
    ui->textEdit->undo();   // 撤销操作
}

void MainWindow::on_action_X_triggered()
{
    ui->textEdit->cut();    // 剪切操作
}

void MainWindow::on_action_C_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_action_V_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::show_findText()
{
    QString findText = find_textLineEdit->text();
    ui->textEdit->find(findText, QTextDocument::FindBackward);
    if (!ui->textEdit->find(findText, QTextDocument::FindBackward)) {
        QMessageBox::warning(this, tr("查找"), tr("找不到 %1").arg(findText));
    }
}

void MainWindow::on_action_F_triggered()
{
    QDialog *findDlg = new QDialog(this);   //新建一个对话框,用于查找操作,this 表明它的父窗口是 MainWindow。
    findDlg->setWindowTitle(tr("查找"));
    find_textLineEdit = new QLineEdit(findDlg); // //将行编辑器加入到新建的查找对话框中
    QPushButton *find_Btn = new QPushButton(tr("查找下一个"), findDlg);

    QVBoxLayout *layout = new QVBoxLayout(findDlg);
    layout->addWidget(find_textLineEdit);
    layout->addWidget(find_Btn);
    findDlg->show();
    connect (find_Btn, SIGNAL(clicked()), this, SLOT(show_findText()));
}

void MainWindow::on_action_9_triggered()
{
    qDebug("版本说明");
    QDialog *findDlg = new QDialog(this);
    findDlg->setWindowTitle(tr("版本说明"));
    QLineEdit *lineEdit = new QLineEdit(findDlg);
    lineEdit->setText("张坤武制作");
    lineEdit->setEnabled(false);
    QVBoxLayout *layout = new QVBoxLayout(findDlg);
    layout->addWidget(lineEdit);
    findDlg->show();
}
