#include "bot_environment.h"
#include <QDebug>
#include <QList>


bot_environment::bot_environment(unsigned maxlimit_of_population)
{
    this->maxlimit_of_population = maxlimit_of_population;
    for (unsigned i = 0;i < maxlimit_of_population / 8; i++) {
        bit_bot *bot = new bit_bot(-90.0);
        population.insert(bot->get_value(), bot);
    }
    generation = 1;


}

void bot_environment::show_Generation()const
{
    qDebug() << "Generation:" << generation;
    auto iter = population.begin();

    while (iter != population.end())
    {
        qDebug() << "ID #" << iter.value()->get_id() << iter.value()->get_gender_info()
                 << "value =" << iter.value()->get_value();
        iter++;
    }
}
void bot_environment::time_to_sex()
{
    auto iter = population.begin();



    while (iter != population.end())
    {

        iter++;
    }
}
