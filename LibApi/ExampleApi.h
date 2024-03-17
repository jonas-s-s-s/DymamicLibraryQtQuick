#pragma once

#include "qobject.h"
#include <string>

class ExampleApi: public QObject
{

public:
    virtual ~ExampleApi() = default;

    virtual std::string propertyName() = 0;

    virtual void performComputation(int num) = 0;

    virtual QByteArray getQML() = 0;
};
