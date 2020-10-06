#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <vector>
#include "BShelf.h"
#include "PrintBook.h"
#include "Shelf.h"
#include <QMainWindow>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_addbshelf_clicked();

    void on_pushButton_delbshelf_clicked();

    void on_listWidget_bshelfs_itemClicked(QListWidgetItem *item);

    void on_pushButton_addshelf_clicked();

    void on_listWidget_shelfs_itemClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
    vector<BookShelf> bookShelfs;
    int bshelfID;
    int shelfID;
};
#endif // MAINWINDOW_H
