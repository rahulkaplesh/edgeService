/****************************************************************
 * This is the class responsible for providing Rest Interface for
 * Edge Library. It will be used for making rest connection with
 * the server 
 ****************************************************************/

#ifndef _REST_MANAGER_HPP_
#define _REST_MANAGER_HPP_

#include "QtCore/QObject"
#include "QtNetwork/QNetworkAccessManager"
#include "QtNetwork/QNetworkRequest"
#include "QtNetwork/QNetworkReply"
#include "QtCore/QJsonObject"
#include "QtCore/QEventLoop"

namespace EDGE_CONNECTOR_LIBRARY {
    class RESTManager: public QObject {
            Q_OBJECT;
            QNetworkAccessManager *mNetworkAccessManager;
            QString mEndpoint;
            QNetworkReply *reply;
            std::function<void(QNetworkReply*)> mSuccessHandler;
        public:
            RESTManager(QObject *parent = nullptr);
            void setEndPoint(QString &aEndpoint);
            void postDataToRoute(QString& aRoute,
                QByteArray& aDataToPost,
                std::function<void(QNetworkReply*)> successHandler = std::function<void(QNetworkReply*)>(nullptr),
                std::function<void(QNetworkReply*)> errorHandler = std::function<void(QNetworkReply*)>(nullptr));
        public slots:
            void replyRecieved();
    };
}

#endif