#include <QCoreApplication>
#include <QDebug>
#include "bot_environment.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    srand(time(NULL));

   bot_environment P(80);
   P.show_Generation();
   P.time_to_sex();
   P.show_Generation();
   P.time_to_sex();
   P.show_Generation();

    return a.exec();
}
