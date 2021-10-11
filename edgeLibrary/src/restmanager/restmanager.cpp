#include "restmanager.hpp"

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

void RESTManager::postDataToRoute(QString& aRoute, QByteArray& aDataToPost) {
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

RESTManager::~RESTManager() {}