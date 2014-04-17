#ifndef CORE_SRC_EDLPROVIDERSERVICE_H
#define CORE_SRC_EDLPROVIDERSERVICE_H

#include <QtServiceBase>
#include <QCoreApplication>

#include "EdlProviderServer.h"

namespace edlprovider
{
namespace core
{

class EdlProviderService : public QtService<QCoreApplication>
{
public:
    EdlProviderService(int argc, char** argv);

    ~EdlProviderService();

    bool setUp();

protected:
    virtual void start() override final;

    virtual void stop() override final;

    virtual void createApplication(int &argc, char **argv) override final;

    virtual int executeApplication() override final;

private:
    QScopedPointer<soap::EdlProviderServer> soapServer_;
};

}
}

#endif // CORE_SRC_EDLPROVIDERSERVICE_H
