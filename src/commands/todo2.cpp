#include "todo2.h"

#include <QDebug>

Todo2::Todo2()
{

}

int Todo2::handle(const QStringList & options)
{
    qDebug() << "command todo2 was called";
    qDebug() << "Options: " << options;

    return 0;
}