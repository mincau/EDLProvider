#include "EdlProviderService.h"

#include <QDebug>

#include "EDLProviderInfo.h"

#include "PathAppender.h"
#include "easylogging++.h"

using namespace edlprovider::core;

EdlProviderService::EdlProviderService(int argc, char** argv)
    : QtService(argc, argv, edlprovider::info::PROJECT_USER_NAME)
{
}

EdlProviderService::~EdlProviderService()
{
}

bool EdlProviderService::setUp()
{
    QString logConfFile = common::util::PathAppender(application()->applicationDirPath(),
                                                     edlprovider::info::PROJECT_LOG_FILE_CONFIG);

    //Configure logger
    el::Configurations conf(logConfFile.toStdString());
    el::Loggers::reconfigureAllLoggers(conf);

    return true;
}

void EdlProviderService::start()
{
    QString appConfigFile = common::util::PathAppender(application()->applicationDirPath(),
                                                       edlprovider::info::PROJECT_CONFIG_FILE);

    //Start configuration
    configuration_.reset(new Configuration());
    if (!configuration_->load(appConfigFile))
        LOG(FATAL) << "Configuration from [" << appConfigFile << "].";

    soapServer_.reset(new soap::EdlProviderServer(configuration_->getServiceHostName()));

    if(soapServer_->run(configuration_->getServicePort()) != SOAP_OK)
        LOG(ERROR) << "Service could not be started.";
}

void EdlProviderService::stop()
{

}

void EdlProviderService::createApplication(int& argc, char** argv)
{
    QtService::createApplication(argc, argv);
    el::Helpers::setArgs(argc, argv);

    application()->setApplicationName(edlprovider::info::PROJECT_USER_NAME);
    application()->setApplicationVersion(edlprovider::info::EDLPROVIDER_VERSION);
    application()->setObjectName(edlprovider::info::PROJECT_NAME);
}

int EdlProviderService::executeApplication()
{
    if (!setUp())
        return -1;

    return QtService::executeApplication();
}
