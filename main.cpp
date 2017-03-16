#include "mainwindow.h"
#include <QApplication>
#include "logindlg.h"
#include "QTextCodec"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());

    MainWindow w;
    loginDlg login;
    if (login.exec() == QDialog::Accepted) {
        w.show();
        return a.exec();
    }
    else {
        return 0;
    }


}
