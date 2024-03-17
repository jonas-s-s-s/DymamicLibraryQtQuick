#include "DivideLib.h"
#include <QFile>

#if defined(__linux__) || defined(__APPLE__)
extern "C"
{
DivideLib *allocator()
{
    return new DivideLib();
}

void deleter(DivideLib *ptr)
{
    delete ptr;
}
}
#endif

#ifdef WIN32
extern "C"
{
__declspec (dllexport) DivideLib *allocator() {
    return new DivideLib();
}

__declspec (dllexport) void deleter(DivideLib *ptr) {
    delete ptr;
}
}
#endif

std::string DivideLib::propertyName() {
    return "divideLib";
}

void DivideLib::performComputation(int num)
{
    if(num == 0)
        return;

    _data = num/2;
    emit dataUpdated(_data);
}

QByteArray DivideLib::getQML() {
    QFile file(":/DivideLib/resources/panel.qml");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return QByteArray();
    return file.readAll();
}


