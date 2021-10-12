#include "gtest/gtest.h"
#include "restmanager.hpp"

#include "QtCore/QJsonDocument"

using namespace EDGE_CONNECTOR_LIBRARY;

TEST(REST_MANAGER, INITIALISATION) {
    RESTManager manager;
    QString endPoint = "http://127.0.0.1:5200";
    manager.setEndPoint(endPoint);
    QJsonObject dataToPost;
    dataToPost.insert("data", "Hello World!!");
    QJsonDocument doc(dataToPost);
    QString route = "/data";
    QByteArray data = doc.toJson();
    manager.postDataToRoute(route, data);
}