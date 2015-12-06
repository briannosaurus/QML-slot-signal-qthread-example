#include "QDebug"
#include "QProcess"
#include "QFileInfo"
#include "systemcommand.h"

void systemcommand::run()
{
     qDebug() << "THREAD: hello from worker thread " << thread()->currentThreadId();
     QFileInfo cmdFile( "C:\\Windows\\system32\\cmd.exe");
     QProcess *process = new QProcess( this );
     process->execute(cmdFile.absoluteFilePath() + " /c ping \"localhost\"  ");
     //process->waitForFinished() ;
     qDebug() << process->readAllStandardOutput();
}
