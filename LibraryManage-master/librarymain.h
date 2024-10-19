#ifndef LIBRARYMAIN_H
#define LIBRARYMAIN_H

#include "librarydata.h"
#include <QMainWindow>
#include <QCloseEvent>
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui {
    class LibraryMain;
}
QT_END_NAMESPACE

class LibraryMain : public QMainWindow {
    Q_OBJECT

public:
    LibraryMain(QWidget *parent = nullptr);
    ~LibraryMain();

    virtual void closeEvent(QCloseEvent*);

private slots:

    void on_bookSwitchButton_clicked(); // 当书籍切换按钮被点击时执行的操作，可能是切换到书籍管理界面或显示书籍列表。

    void on_userSwitchButton_clicked();// 当用户切换按钮被点击时执行的操作，可能是切换到用户管理界面或显示用户列表。

    void on_searchButton_clicked();// 当搜索按钮被点击时执行的操作，可能是根据输入的搜索条件进行书籍或用户的搜索。

    void on_borrowButton_clicked();// 当借阅按钮被点击时执行的操作，可能是将选中的书籍标记为已借出或记录借阅信息。

    void on_returnButton_clicked();// 当归还按钮被点击时执行的操作，可能是将选中的书籍标记为已归还或更新借阅信息。

    void on_tableView_clicked(const QModelIndex &index);// 当表格视图中的某个单元格被点击时执行的操作，可能是显示该单元格对应的书籍或用户详细信息。

    void on_editButton_clicked();// 当编辑按钮被点击时执行的操作，可能是允许用户编辑当前选中的书籍或用户的信息。

    void on_tableView_doubleClicked(); // 当表格视图中的某个单元格被双击时执行的操作，可能是打开一个对话框来编辑该单元格对应的书籍或用户信息。

    void on_writeDataAction_triggered();// 当写入数据操作被触发时执行的操作，可能是将当前的数据保存到文件或数据库中。

    void on_addButton_clicked();// 当添加按钮被点击时执行的操作，可能是打开一个对话框来添加新的

    void on_aboutMeAction_triggered();// 当关于我操作被触发时执行的操作，可能是显示关于软件或开发者的信息。

    void on_signOutAction_triggered();// 当注销操作被触发时执行的操作

    void on_importAction_triggered(); // 当导入操作被触发时执行的操作

    void on_exportAction_triggered();// 当导出操作被触发时执行的操作

    void on_readDataAction_triggered();// 当读取数据操作被触发时执行的操作，

    void on_aboutAction_triggered(); // 当关于操作被触发时执行的操作

private:
    Ui::LibraryMain *ui;
    QStandardItemModel* userModel;
    QStandardItemModel* bookModel;

    void initBookTable();// 初始化图书表

    void initUserTable();// 初始化用户表

    void displayBookData();//显示所有书籍数据

    void displayUserData(); // 显示所有用户数据

    void displayBookList(List<Node<BookInfo>*>);// 显示书籍列表

    void displayUserList(List<Node<UserInfo>*>); // 显示用户列表

    void appendSingleBook(Node<BookInfo>*);// 添加一本新书到书籍列表中

    void appendSingleUser(Node<UserInfo>*);// 添加一个新用户到用户列表中

    void displaySingleBook(Node<BookInfo>*);// 显示单本书籍的详细借阅信息

    void displaySingleUser(Node<UserInfo>*); // 显示单个用户的详细信息

    int getSelection(); // 获取用户的选择

    int getSelection(const QModelIndex&);

    void updateButton(int, int);

    void disableButton();
};
#endif // LIBRARYMAIN_H
