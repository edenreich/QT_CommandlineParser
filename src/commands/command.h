#ifndef COMMAND_H
#define COMMAND_H

#include <QStringList>

class Command
{

public:
    Command() = default;
    virtual ~Command() = default;

    virtual int handle(const QStringList & options) = 0;
};

#endif // COMMAND_H