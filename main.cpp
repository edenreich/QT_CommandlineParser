#include <QCoreApplication>
#include <QCommandLineParser>
#include <QCommandLineOption>

#include <QDebug>
#include <QString>

#include "commands/command.h"
#include "commands/todo1.h"
#include "commands/todo2.h"

#define COLOR_CRITICAL "\033[41m"
#define COLOR_RESET "\033[0m"

enum CommandType {
    CommandTypeTodo1,
    CommandTypeTodo2
};

Command * createCommand(CommandType command)
{
    Command * instance = nullptr;

    switch(command)
    {
    case CommandType::CommandTypeTodo1:
        instance = new Todo1;
        break;
    case CommandType::CommandTypeTodo2:
        instance = new Todo2;
        break;
    }

    return instance;
}

Command * ParseCommand(QString const commandStr)
{
    if (commandStr == "todo1") {
        return createCommand(CommandType::CommandTypeTodo1);
    } else if (commandStr == "todo2") {
        return createCommand(CommandType::CommandTypeTodo2);
    }

    return nullptr;
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QCommandLineParser parser;

    QCoreApplication::setApplicationName("Todo List Application");
    QCoreApplication::setApplicationVersion("1.0");

    parser.setApplicationDescription("Todo List Application");
    parser.addHelpOption();
    parser.addVersionOption();

    parser.addPositionalArgument("todo1", QCoreApplication::translate("main", "Run todo1."));
    parser.addPositionalArgument("todo2", QCoreApplication::translate("main", "Run todo2."));

    QCommandLineOption verbose(QStringList() << "v" << "verbose", QCoreApplication::translate("main", "Option is: fr") \
                                   ,QCoreApplication::translate("main", "opt"), "1");
    parser.addOption(verbose);
    parser.process(app);

    const QStringList args = parser.positionalArguments();

    const QStringList options = parser.optionNames();
    const QString optionValue = parser.value(verbose);

    if (args.size() != 1) {
        fprintf(stderr, QCoreApplication::translate("main", "%s Error: one command expected, but, %d were given. %s %s").toLatin1().data(), COLOR_CRITICAL, args.size(), COLOR_RESET, "\n");
        parser.showHelp(1);
    }

    Command * command = ParseCommand(args.at(0));


    if (command)
        return command->handle(options);

    fprintf(stderr, QCoreApplication::translate("main", "%s Command not found %s\n").toLatin1().data(), COLOR_CRITICAL, COLOR_RESET, "\n");
    parser.showHelp(1);

    return 0;
}
