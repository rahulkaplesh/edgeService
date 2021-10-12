/*************************************************************************************
 * Starting the gtest for QT , we need a QEventLoop to terminate the application
 * correctly.
 ************************************************************************************/ 
#include "gtest/gtest.h"
#include "QtCore/QCoreApplication"
#include "QtCore/QThread"

static void ExecuteGTest()
{ 
    {
        //perform checks to validate that Qt Eventloop is actually running
        const QThread* pCurrent = QThread::currentThread();
        ASSERT_TRUE(nullptr != pCurrent) << "This is no QThread";
        const auto* pEventLoop = pCurrent->eventDispatcher();
        ASSERT_TRUE(nullptr != pEventLoop) << "Eventloop is not running";
    }
    const int iRes = RUN_ALL_TESTS();
    //terminate the Qt Eventloop and return GTest Result
    QCoreApplication::exit(iRes);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    QCoreApplication app(argc, argv);

    std::unique_ptr<QThread> pGTest(QThread::create(ExecuteGTest));
        pGTest->start();

    const int iGTestRes = app.exec();
    bool bIsRunning = pGTest->isRunning();
    if (bIsRunning)
    {
        //GTest thread is still running =>should not been happening....requesting exit
        //Request exit with error code
        pGTest->exit(-1);
        pGTest->wait();
    }
    return iGTestRes;
}