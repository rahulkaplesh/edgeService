#include "gtest/gtest.h"
#include "restmanager.hpp"

#include "QtCore/QCoreApplication"
#include "QtCore/QJsonDocument"
#include "QtCore/QThread"
#include "QtCore/QCoreApplication"

using namespace EDGE_CONNECTOR_LIBRARY;

TEST(RestManagerTest, APP_USAGE) {
    QCoreApplication app;
    RESTManager manager(app);
    QString endPoint = "http://127.0.0.1:5200";
    manager.setEndPoint(endPoint);
    QJsonObject dataToPost;
    dataToPost.insert("data", "Hello World!!");
    QJsonDocument doc(dataToPost);
    QString route = "/data";
    QByteArray data = doc.toJson();
    manager.postDataToRoute(route, data);
    
}