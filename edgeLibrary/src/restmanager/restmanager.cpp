#include "restmanager.hpp"
#include <functional>

using namespace EDGE_CONNECTOR_LIBRARY;

/**
 * @brief Construct a new RESTManager::RESTManager object this is a manager for making REST Connections * 
 * @param parent i
 */
RESTManager::RESTManager(QObject *parent) : QObject(parent) {
    mNetworkAccessManager = new QNetworkAccessManager(parent);
}

void RESTManager::setEndPoint(QString &aEndpoint) {
    mEndpoint = aEndpoint;
}

/**
 * @brief Returns a Network reply object for posting data to a particular route
 * This is to be used internally to library so currently its ok to return network
 * reply This will be used by the system to print error message and cache the 
 * data. Intention is to build the service such that user doesnt have to bother
 * about errors in data being sent. Though if a successfull connection is not made
 * then the user will get a notification.
 * TODO : To update this doc and to test this function
 * @param aRoute route to which the data is posted
 * @param aDataToPost Data to be posted to the endpoint
 */
void RESTManager::postDataToRoute(QString& aRoute,
    QByteArray& aDataToPost,
    std::function<void(QNetworkReply*)> successHandler,
    std::function<void(QNetworkReply*)> errorHandler) {
    try
    {
        QUrl url = QUrl(mEndpoint + aRoute);

        QNetworkRequest request(url);
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

        QNetworkReply *reply = mNetworkAccessManager->post(request, aDataToPost);

        connect(reply, &QNetworkReply::finished, [=](){
            if(reply->error() == QNetworkReply::NoError)
            {
                QString contents = QString::fromUtf8(reply->readAll());
                qInfo() << contents;
            }
            else
            {
                QString err = reply->errorString();
                qInfo() << err;
            }
            reply->deleteLater();
        });
    }
    catch(const std::exception& e)
    {
        qWarning() << e.what();
    }
}