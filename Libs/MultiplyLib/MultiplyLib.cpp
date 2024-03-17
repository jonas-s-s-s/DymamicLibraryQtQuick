#include "MultiplyLib.h"

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

std::string MultiplyLib::getQML() {
    // Could be loaded from filesystem instead
    return "import QtQuick \n Text { property var multiplyLib \n Component.onCompleted: {multiplyLib.dataUpdated.connect(function(data) {resultDisplay.text = data})} id: resultDisplay\n text: \"No input data.\" }";
}


