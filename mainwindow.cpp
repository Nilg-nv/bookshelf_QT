#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Первичные настройки и инициализация
    ui->groupBox_shelfs->setEnabled(false);
    ui->groupBox_books->setEnabled(false);
    ui->pushButton_delshelf->setEnabled(false);
    shelfID=0;
    bshelfID=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_addbshelf_clicked()
{
    BookShelf bshelf;
    bookShelfs.push_back(bshelf);
    ui->listWidget_bshelfs->addItem(QString::number(bookShelfs.size()));
}

void MainWindow::on_pushButton_delbshelf_clicked() //Кнопка удалить
{

}

void MainWindow::on_listWidget_bshelfs_itemClicked(QListWidgetItem *item)
{
    //Получить ID шкафа
    shelfID=item->text().toInt();
    //Сброс списка
    ui->listWidget_shelfs->clear();
    //Активация блока для полок
    ui->groupBox_shelfs->setEnabled(true);
    //Активация кнопки удаления шкафа
    ui->pushButton_delbshelf->setEnabled(true);
    //Получить количество полок
    int shelfNum = bookShelfs[shelfID - 1].getShelfN();
    if(shelfNum>0){
        //Добавить полки в списки
        for (int i=0;i<shelfNum;i++){
            ui->listWidget_shelfs->addItem(QString::number(i+1));
        }
    }
}

void MainWindow::on_pushButton_addshelf_clicked()
{
    bookShelfs[shelfID-1].addShelf();
    //Получить количество полок
    int shelfNum = bookShelfs[shelfID - 1].getShelfN();
    //Добавить в список
    ui->listWidget_shelfs->addItem(QString::number(shelfNum));
}
