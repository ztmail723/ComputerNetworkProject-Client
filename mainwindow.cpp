#include "mainwindow.h"
#include "datapkg.h"
#include "mytcpsocket.h"
#include "pkghandler.h"
#include "pkgsender.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new MyTcpSocket(this);
    //itemModel = new QStandardItemModel(this);
    //ui->fileListView->setModel(itemModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->pushButton->setDisabled(true);
    bool flag = socket->connectStart(ui->lineEdit_Server->text(), quint16(ui->lineEdit_Port->text().toUInt()));
    if (flag)
    {
        ui->pushButton_refresh->setEnabled(true);
        ui->pushButton_receiveReq->setEnabled(true);
        QMessageBox msgBox;
        msgBox.setText("连接成功");
        msgBox.exec();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("连接失败，请重试！");
        msgBox.exec();
        ui->pushButton->setDisabled(false);
    }
}

void MainWindow::on_pushButton_refresh_clicked()
{
    this->socket->sender->send1001(ui->lineEdit_User->text());
}

void MainWindow::getFileList(QStringList list)
{
    ui->filelistWidget->clear();
    for (auto& i : list)
    {
        ui->filelistWidget->addItem(i);
    }
}

void MainWindow::getFileHeader(QString fileName, quint64 fileCount)
{
    ;
}

void MainWindow::getFileData(quint64 fileID, QByteArray fileData)
{
    QMessageBox msgBox;
    msgBox.setText("连接成功");
    msgBox.exec();
}

void MainWindow::on_pushButton_receiveReq_clicked()
{
    auto selected = ui->filelistWidget->selectedItems().at(0);
    socket->sender->send1002(ui->lineEdit_User->text(), selected->text());
}
