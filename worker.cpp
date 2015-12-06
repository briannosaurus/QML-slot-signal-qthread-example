#include "QDebug"
#include "worker.h"
#include "QProcess"
#include "QFileInfo"
#include "QIODevice"

// --- CONSTRUCTOR ---
Worker::Worker() {
    // constructor arguments to internal variables here.
}

// --- DECONSTRUCTOR ---
Worker::~Worker() {
    // free resources
}

// --- PROCESS ---
// Start processing data.
void Worker::process() {
    // allocate resources using new here
    qDebug("Hello World!");

    //QString paths = item2;
    //QProcess proc;
    QProcess *proc = new QProcess( this );
    QString command = "cmd.exe";
    QStringList arguments =
    QStringList() << "/c" << "ping -n 20 localhost" ;
    proc->start(command, arguments);
    if(proc->waitForStarted()){
        qDebug() << "Process Starting";
    }
    proc->waitForFinished(-1);
        qDebug() << "Process finished";
    // xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
        //QFileInfo cmdFile( "C:\\Windows\\system32\\cmd.exe");
        //QProcess *process = new QProcess( this );
        //process->execute(cmdFile.absoluteFilePath() + " /c ping \"localhost\"  ");
        //process->waitForFinished() ;
        //qDebug() << process->readAllStandardOutput();
        //process->waitForFinished();
    //Signal thread finished
    emit finished();
}
