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

namespace EDGE_CONNECTOR_LIBRARY {
    class RESTManager: public QObject {
            Q_OBJECT;
            QNetworkAccessManager *mNetworkAccessManager;
            QString mEndpoint;
        public:
            RESTManager(QObject *parent = nullptr);
            void setEndPoint(QString &aEndpoint);
            void postDataToRoute(QString& aRoute, QByteArray& aDataToPost);
            virtual ~RESTManager();
    };
}

#endif