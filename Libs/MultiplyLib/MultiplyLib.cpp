#include "MultiplyLib.h"
#include "qevent.h"
#include <QFile>
#include <QDirIterator>

#ifdef WIN32
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT
#endif

extern "C"
{
    DLLEXPORT MultiplyLib *allocator() {
        return new MultiplyLib();
    }

    DLLEXPORT void deleter(MultiplyLib *ptr) {
        delete ptr;
    }
}

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


