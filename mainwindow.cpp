#include "mainwindow.h"
#include "datapkg.h"
#include "mytcpsocket.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new MyTcpSocket(this);
    itemModel = new QStandardItemModel(this);
    ui->fileListView->setModel(itemModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->pushButton->setDisabled(true);
    bool flag = socket->connectStart(ui->lineEdit_Server->text(), quint16(ui->lineEdit_Port->text().toUInt()));
    if (flag) {
        ui->pushButton_refresh->setEnabled(true);
        ui->pushButton_receiveReq->setEnabled(true);
        QMessageBox msgBox;
        msgBox.setText("连接成功");
        msgBox.exec();
    } else {
        QMessageBox msgBox;
        msgBox.setText("连接失败，请重试！");
        msgBox.exec();
        ui->pushButton->setDisabled(false);
    }
}

void MainWindow::on_pushButton_refresh_clicked()
{
    //请求刷新文件
}

void MainWindow::getFileList(QStringList list)
{
    this->itemModel->clear();
    for (auto& i : list) {
        QStandardItem* item = new QStandardItem(i);
        this->itemModel->appendRow(item);
    }
}

void MainWindow::getFileHeader(QString fileName, quint64 fileCount)
{
}

void MainWindow::getFileData(quint64 fileID, QByteArray fileData)
{
    QMessageBox msgBox;
    msgBox.setText("连接成功");
    msgBox.exec();
}
