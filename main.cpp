#include <QCoreApplication>
#include <QDebug>
#include "bot_environment.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    srand(time(NULL));

   bot_environment P(40);
   P.show_Generation();
   for (int i = 0; i < 10; i++)
   {

       P.time_to_sex();
       P.time_to_kill();
       P.show_Generation();
   }

    return a.exec();
}
