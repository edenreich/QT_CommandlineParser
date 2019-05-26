#ifndef TODO2_H
#define TODO2_H

#include "command.h"
#include <QStringList>

class Todo2 : public Command
{
public:
    Todo2();
    ~Todo2() = default;

    ExitCode handle(const QStringList & options) override;
};

#endif // TODO2_H
