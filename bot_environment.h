#ifndef BOT_ENVIRONMENT_H
#define BOT_ENVIRONMENT_H
#include "bit_bot.h"
#include <QMultiMap>

class bot_environment
{
   QMultiMap<unsigned, bit_bot*> population;
   unsigned generation;
   unsigned target;
public:
   unsigned maxlimit_of_population;

    bot_environment(unsigned);
    void show_Generation() const;
//private:


    void time_to_kill();
    void time_to_sex();
    void time_to_mutation();
};

#endif // BOT_ENVIRONMENT_H
