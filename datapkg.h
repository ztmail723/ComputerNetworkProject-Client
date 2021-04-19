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
    friend QDataStream& operator<<(QDataStream& output, const DataPkg& data) //序列化
    {
        output << data.ID << data.data;
        return output;
    }
    friend QDataStream& operator>>(QDataStream& input, DataPkg& data) //反序列化
    {
        input >> data.ID >> data.data;
        return input;
    }
};
Q_DECLARE_METATYPE(DataPkg)

#endif // DATAPKG_H
