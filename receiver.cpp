#include "receiver.h"
#include <QDebug>
#include "QProcess"
#include "QFileInfo"
#include "systemcommand.h"
#include "QThread"
#include "worker.h"

Receiver::Receiver(QObject *parent) :
    QObject(parent)
{
}

void Receiver::receiveFromQml(int count) {
    qDebug() << "RECIVER: Received in C++ from QML:" << count;
}

void Receiver::runbackgroundcmd() {

    QThread* thread = new QThread;
    Worker* worker = new Worker();
    worker->moveToThread(thread);
    connect(worker, SIGNAL(error(QString)), this, SLOT(errorString(QString)));
    connect(thread, SIGNAL(started()), worker, SLOT(process()));
    connect(worker, SIGNAL(finished()), thread, SLOT(quit()));
    connect(worker, SIGNAL(finished()), worker, SLOT(deleteLater()));
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
}

void Receiver::errorString(QString error) {
    qDebug() << error;
}

void Receiver::readOutput() {

}
