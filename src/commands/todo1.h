#ifndef TODO1_H
#define TODO1_H

#include "../interfaces/command.h"
#include <QStringList>

class Todo1 : public Command
{
public:
    Todo1();
    ~Todo1() = default;

    ExitCode handle(const QStringList & options) override;
};

#endif // TODO1_H
