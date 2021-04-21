#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mytcpsocket.h"
#include <QDataStream>
#include <QMainWindow>
#include <QStandardItemModel>
QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow() Q_DECL_OVERRIDE;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_refresh_clicked();

    void getFileList(QStringList list);
    void getFileHeader(QString fileName, quint64 fileCount);
    void getFileData(quint64 fileID, QByteArray fileData);

    void on_pushButton_receiveReq_clicked();

private:
    Ui::MainWindow* ui;
    MyTcpSocket* socket;
    //QStandardItemModel* itemModel;
};
#endif // MAINWINDOW_H
