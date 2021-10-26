#include "restmanager.hpp"
#include <functional>

#include <iostream>

using namespace EDGE_CONNECTOR_LIBRARY;

/**
 * @brief Construct a new RESTManager::RESTManager object this is a manager for making REST Connections * 
 * @param parent i
 */
RESTManager::RESTManager(QObject *parent) : QObject(parent) 
{
    mNetworkAccessManager = new QNetworkAccessManager(parent);
}

/**
 * @brief Setting the endpoint for REST Manager
 * @param aEndpoint End point to be registered
 */
void RESTManager::setEndPoint(QString &aEndpoint)
{
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
    std::function<void(QNetworkReply*)> errorHandler) 
{
    try
    {
        QUrl url = QUrl(mEndpoint + aRoute);

        QNetworkRequest request;
        request.setUrl(url);
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

        if (successHandler)
        {
            mSuccessHandler = successHandler;
        }

        reply = mNetworkAccessManager->post(request, aDataToPost);        
        connect(reply, &QNetworkReply::readyRead, this, &RESTManager::replyRecieved);

        std::cout << "Sending Data to : " << url.toString().toStdString() << std::endl;
    }
    catch(const std::exception& e)
    {
        qWarning() << e.what();
    }
}

void RESTManager::replyRecieved()
{
    QNetworkReply* reply = qobject_cast<QNetworkReply*> (QObject::sender());
    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << "Error getting the reply" << reply->errorString();
        return;
    }
    qDebug() << "Response : " << reply->readAll();
    if (mSuccessHandler) {
        mSuccessHandler(reply);
    }
    reply->deleteLater();    
}