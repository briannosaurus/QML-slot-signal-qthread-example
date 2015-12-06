#ifndef SYSTEMCOMMAND_H
#define SYSTEMCOMMAND_H

#endif // SYSTEMCOMMAND_H
#include "QThread"

class systemcommand : public QThread
{
    Q_OBJECT
private:
    void run();
};
