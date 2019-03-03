#include "bot_environment.h"
#include <QDebug>
#include <QVector>


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
    qDebug() << "Generation:" << generation << "Population:" << population.size();
    auto iter = population.begin();

    while (iter != population.end())
    {
        qDebug() << "ID #" << iter.value()->get_id() << iter.value()->get_gender_info()
                 << "value =" << iter.value()->get_value() ;
        iter++;
    }
}
void bot_environment::time_to_sex()
{
   generation += 1;

    auto iter = population.begin();

    QVector<bit_bot*> population_vec;

    while (iter != population.end())
    {
        population_vec.push_back(iter.value());
        iter++;
    }
    int size_this_generation = population.size();
    for (int i = 0; i < size_this_generation / 2 ;i++)
    {

            bit_bot* parent1 = population_vec.back();
            population_vec.pop_back();
            bit_bot* parent2 = population_vec[rand() % (population_vec.size() )];

                bit_bot* new_bot = bit_bot::to_multiply(*parent1, *parent2);
                population.insert(new_bot->get_value(), new_bot);


        }

population_vec.clear();

}

void bot_environment::time_to_kill()
{

    auto iter = population.begin();

    while (static_cast<unsigned>(population.size()) > maxlimit_of_population) {
        delete iter.value();
        population.erase(iter);

       iter++;
    }

}

