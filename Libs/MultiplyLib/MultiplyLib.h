#pragma once

#include "ExampleApi.h"
#include "qqmlintegration.h"

class MultiplyLib: public ExampleApi {
    Q_OBJECT
    QML_ELEMENT

public:
     MultiplyLib() = default;
    ~MultiplyLib() = default;

    std::string propertyName() override;

    void performComputation(int num) override;

    QByteArray getQML() override;

signals:
    void dataUpdated(int data);

private:
    int _data = 404;

};
