#ifndef DATAPKG_H
#define DATAPKG_H
#include <QDataStream>
#include <QDebug>
#include <QObject>
#include <QVector>
class DataPkg {
public:
    DataPkg();
    qint64 ID;
    QVector<QVariant> data;
    friend QDataStream& operator<<(QDataStream& output, const DataPkg& data); //序列化
    friend QDataStream& operator>>(QDataStream& input, DataPkg& data); //反序列化
};

#endif // DATAPKG_H
