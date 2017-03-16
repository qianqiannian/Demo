#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_action_triggered();

    void on_action_5_triggered();   //  保存

    void on_action_4_triggered();   //  另存为

    void on_action_2_triggered();   //  打开

    void on_action_3_triggered();   //  关闭

    void on_action_7_triggered();   //  退出

    void on_action_Z_triggered();   //  撤销

    void on_action_X_triggered();   //  剪切

    void on_action_C_triggered();   //  复制

    void on_action_V_triggered();   //  粘贴

    void show_findText();   //在该函数中实现查找字符串的功能

    void on_action_F_triggered();

    void on_action_9_triggered();

private:
    /*---------------------------------------------------------------------------*/
    // Variable declaration
    /*---------------------------------------------------------------------------*/

    Ui::MainWindow *ui;

    bool isSaved;
    QString curFile;
    QLineEdit *find_textLineEdit;   //声明一个行编辑器,用于输入要查找的内容

    /*---------------------------------------------------------------------------*/
    // Private functions
    /*---------------------------------------------------------------------------*/

    void do_file_New();
    void do_file_Save();
    void do_file_SaveAs();
    bool saveFile(const QString& fileName);
    void do_file_SaveOrNot();
    void do_file_Open();
    bool do_file_Load(const QString& fileName); // 读取文件

private:
    MainWindow(const MainWindow&);  //  拷贝构造
    MainWindow& operator = (const MainWindow&); // 分配操作

};

#endif // MAINWINDOW_H
