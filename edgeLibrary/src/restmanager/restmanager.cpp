#include "restmanager.hpp"

using namespace EDGE_CONNECTOR_LIBRARY;

/**
 * @brief Construct a new RESTManager::RESTManager object this is a manager for making REST Connections * 
 * @param parent i
 */
RESTManager::RESTManager(QObject *parent) : QObject(parent) {
    mNetworkAccessManager = new QNetworkAccessManager(parent);
}

RESTManager::~RESTManager() {}