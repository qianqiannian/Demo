#include "logindlg.h"
#include "ui_logindlg.h"
#include <QtGui>
#include "QMessageBox"

loginDlg::loginDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginDlg)
{
    ui->setupUi(this);
    ui->lineEdit_pwd->setEchoMode(QLineEdit::Password);

}

loginDlg::~loginDlg()
{
    delete ui;
}

void loginDlg::on_loginButton_clicked()
{
    qDebug(ui->lineEdit_pwd->text().toStdString().c_str());
    if (tr("zkw") == ui->lineEdit_user->text().trimmed() || (tr("123") == ui->lineEdit_pwd->text().trimmed())) {
        accept();
    }
    else {
        QMessageBox::warning(this, tr("Warning"), tr( "user name  Or password error" ), QMessageBox::Yes);
        ui->lineEdit_pwd->clear();
        ui->lineEdit_user->clear();
        ui->lineEdit_user->setFocus();
    }
}

void loginDlg::on_exitButton_clicked()
{
    close();
}



























