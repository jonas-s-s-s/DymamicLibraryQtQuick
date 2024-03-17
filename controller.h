#pragma once

#include <QObject>
#include <QQmlEngine>
#include <QQuickItem>
#include <QQmlContext>

#include "LibLoader.h"
#include "ExampleApi.h"

class Controller : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON

public:
    std::unique_ptr<LibLoader<ExampleApi>> dll_loader;
    std::shared_ptr<ExampleApi> lib_object;

    explicit Controller(QObject *parent = nullptr);

public slots:
    void showLibraryQml(int index);
    void clickUpdate(int number);
signals:
    void qmlLoaded(QQuickItem* item);

};

