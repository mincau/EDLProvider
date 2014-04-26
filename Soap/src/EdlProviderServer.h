#ifndef SOAP_SRC_EDLPROVIDERSERVER_H
#define SOAP_SRC_EDLPROVIDERSERVER_H

#include "EdlPluginManager.h"
#include "EDLProviderEdlProviderBindingService.h"

namespace edlprovider
{
namespace soap
{

class EdlProviderServer : public EdlProviderBindingService
{
public:
    explicit EdlProviderServer(const QString& host);

    int run(int port) override final;

private:
    EdlProviderBindingService* copy() override final;

    int getInstalledEdls(edlprovider__ArrayOfstring* edlprovider__installedEdlsResponse) override final;

    int getEdl(edlprovider__EdlCreateRequestType* edlprovider__getEdlRequest,
               edlprovider__EdlCreateResponseType* edlprovider__getEdlResponse) override final;

    int getEdlDouble(edlprovider__EdlCreateRequestDoubleType* edlprovider__getEdlDoubleRequest,
                     edlprovider__EdlCreateResponseType* edlprovider__getEdlResponse) override final;

    QSharedPointer<plugins::interfaces::EdlPluginManager> pluginManager_;

    QString hostName_;
};

}
}

#endif // SOAP_SRC_EDLPROVIDERSERVER_H
