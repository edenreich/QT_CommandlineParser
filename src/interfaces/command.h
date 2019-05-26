#ifndef COMMAND_H
#define COMMAND_H

#include "../types/exit_code.h"
#include <QStringList>

class Command
{

public:
    Command() = default;
    virtual ~Command() = default;

    virtual ExitCode handle(const QStringList & options) = 0;
};

#endif // COMMAND_H