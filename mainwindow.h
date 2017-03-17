#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QLabel>

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
    void on_action_triggered();       //  新建

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

    void on_action_F_triggered();   //  查找

    void on_action_9_triggered();    //版本说明

    void do_cursorChanged();

private:
    /*---------------------------------------------------------------------------*/
    // Variable declaration
    /*---------------------------------------------------------------------------*/

    Ui::MainWindow *ui;

    bool isSaved;
    QString m_curFile;
    QLineEdit *find_textLineEdit;   //声明一个行编辑器,用于输入要查找的内容
    QLabel *first_StatusLabel;
    QLabel *second_StatusLabel;


    /*---------------------------------------------------------------------------*/
    // Private functions
    /*---------------------------------------------------------------------------*/

    void do_file_New();   //  新建文件
    void do_file_Save();    //  保存文件
    void do_file_SaveAs();  //  文件另存为
    bool saveFile(const QString& fileName);     //  这个函数实现将文本文件进行存储
    void do_file_SaveOrNot();   //判断是否有未保存文件
    void do_file_Open();    //打开文件
    bool do_file_Load(const QString& fileName); // 读取文件
    void init_statusBar();  //初始化状态栏


private:
    MainWindow(const MainWindow&);  //  拷贝构造
    MainWindow& operator = (const MainWindow&); // 分配操作

};

#endif // MAINWINDOW_H
