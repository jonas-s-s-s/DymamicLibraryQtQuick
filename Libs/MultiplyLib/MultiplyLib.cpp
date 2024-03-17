#include "MultiplyLib.h"
#include "qevent.h"
#include <QFile>
#include <QDirIterator>

#if defined(__linux__) || defined(__APPLE__)
extern "C"
{
MultiplyLib *allocator()
{
    return new MultiplyLib();
}

void deleter(MultiplyLib *ptr)
{
    delete ptr;
}
}
#endif

#ifdef WIN32
extern "C"
{
__declspec (dllexport) MultiplyLib *allocator() {
    return new MultiplyLib();
}

__declspec (dllexport) void deleter(MultiplyLib *ptr) {
    delete ptr;
}
}
#endif

std::string MultiplyLib::propertyName() {
    return "multiplyLib";
}

void MultiplyLib::performComputation(int num)
{
    _data = num*2;
    emit dataUpdated(_data);
}

QByteArray MultiplyLib::getQML() {
    QFile file(":/MultiplyLib/resources/panel.qml");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return QByteArray();
    return file.readAll();
}


