#include "controller.h"
#include <QQmlComponent>
#include <QQuickItem>
#include <QQmlProperty>
#include <iostream>

#ifdef WIN32
static const std::string libExtension = ".dll";
#endif
#ifdef __linux__
static const std::string libExtension = ".so";
#endif

Controller::Controller(QObject *parent)
    : QObject{parent}
{}

void Controller::showLibraryQml(int index)
{
    std::string libName;
    if(index == 0) {
        libName = "libMultiplyLib";
    } else {
        libName = "libDivideLib";
    }

    dll_loader = std::make_unique<LibLoader<ExampleApi>>(libName + std::string(libExtension));
    dll_loader->openLib();
    lib_object = dll_loader->getInstance();

    std::string QML = lib_object->getQML();

    QQmlEngine *engine = qmlEngine(this);
    QQmlComponent component(engine);
    component.setData(QML.c_str(), QUrl());

    QQuickItem *item = qobject_cast<QQuickItem*>(component.createWithInitialProperties(QVariantMap{{lib_object->propertyName().c_str(), QVariant::fromValue(lib_object.get())}}));

    emit qmlLoaded(item);
}

void Controller::clickUpdate(int num)
{
    if(!lib_object)
        return;

    lib_object->performComputation(num);
}
