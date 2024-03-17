#include "DivideLib.h"

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

std::string DivideLib::getQML() {
    // Could be loaded from filesystem instead
    return "import QtQuick \n Text {property var divideLib \n Component.onCompleted: {divideLib.dataUpdated.connect(function(data) {resultDisplay.text = data})} id: resultDisplay\n text: \"No input data.\" }";
}


