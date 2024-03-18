#include "DivideLib.h"
#include <QFile>

#ifdef WIN32
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT
#endif

extern "C"
{
    DLLEXPORT DivideLib *allocator() {
        return new DivideLib();
    }

    DLLEXPORT void deleter(DivideLib *ptr) {
        delete ptr;
    }
}


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


