#include "datapkg.h"

QDataStream& operator<<(QDataStream& output, const DataPkg& data) //序列化
{
    output << data.ID << data.data;
    return output;
}
QDataStream& operator>>(QDataStream& input, DataPkg& data) //反序列化
{
    input >> data.ID >> data.data;
    return input;
}

DataPkg::DataPkg()
{
}
