#include "todo1.h"

#include <QDebug>

Todo1::Todo1()
{

}

ExitCode Todo1::handle(const QStringList & options)
{
    qDebug() << "command todo1 was called";
    qDebug() << "Options: " << options;

    return ExitCode::Ok;
}