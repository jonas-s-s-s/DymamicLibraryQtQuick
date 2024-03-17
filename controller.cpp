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

        dll_loader = std::make_unique<LibLoader<ExampleApi>>(libName + std::string(libExtension));
        dll_loader->openLib();
        lib_object = dll_loader->getInstance();

        std::string QML = lib_object->getQML();

        QQmlEngine *engine = qmlEngine(this);
        QQmlComponent component(engine);
        component.setData(QML.c_str(), QUrl());

        QQuickItem *item = qobject_cast<QQuickItem*>(component.createWithInitialProperties(QVariantMap{{lib_object->propertyName().c_str(), QVariant::fromValue(lib_object.get())}}));

        emit qmlLoaded(item);

    } else {
        libName = "libDivideLib";

        dll_loader2 = std::make_unique<LibLoader<ExampleApi>>(libName + std::string(libExtension));
        dll_loader2->openLib();
        lib_object2 = dll_loader2->getInstance();

        std::string QML = lib_object2->getQML();

        QQmlEngine *engine = qmlEngine(this);
        QQmlComponent component(engine);
        component.setData(QML.c_str(), QUrl());

        QQuickItem *item = qobject_cast<QQuickItem*>(component.createWithInitialProperties(QVariantMap{{lib_object2->propertyName().c_str(), QVariant::fromValue(lib_object2.get())}}));

        emit qmlLoaded(item);
    }


}

void Controller::clickUpdate(int num)
{
    if(lib_object)
        lib_object->performComputation(num);

    if(lib_object2)
        lib_object2->performComputation(num);


}
