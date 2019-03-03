#include "bit_bot.h"
#include <ctime>

double bit_bot::mutation = 5.0;
unsigned bit_bot::IDCounter = 0;
bit_bot::bit_bot(double isGoodGen)
{
//srand(time_t(NULL));

    for (int i = 0;i < GENSIZE; i++)
        gens->setBit(i, (rand() + (32767.0 / 200) * isGoodGen) >= 16384);
    gender = static_cast<bool>(rand() % 2);
    id = IDCounter++;

}

bit_bot::bit_bot(bit_bot& p1, bit_bot& p2)
{
    //srand(time_t(NULL));

        int k = rand() % GENSIZE;

        for (int i = 0;i < k;i++)
            gens->setBit(i, p1.gens->testBit(i));

        for (int i = k; i < GENSIZE; i++)
            gens->setBit(i, p2.gens->testBit(i));

        gender = static_cast<bool>(rand() % 2);
        id = IDCounter++;

        mutate();

}

unsigned bit_bot::get_id() {return id;}


unsigned bit_bot::get_value()
{
    unsigned answer = 0;

    for (int i = 0; i < GENSIZE; i++)
        answer += gens->testBit(i);

    return  answer;
}

bool bit_bot::get_gender() {return gender;}

QString bit_bot::get_gender_info()
{
    QString answer = "";

    for (int i = 0; i < GENSIZE; i++)
        answer += QString::number(gens->testBit(i));
    return answer;
}


void bit_bot::mutate()
{
    int number_of_mutations = static_cast<int>(mutation / 100 * GENSIZE);

    for (int i = 0; i < number_of_mutations; i++)
        {
            int possiton_of_mutation = rand() % GENSIZE;
            gens->setBit(possiton_of_mutation, gens->testBit(possiton_of_mutation) == 0 ? 1 : 0);
        }

}

bit_bot* bit_bot::to_multiply(bit_bot & p1, bit_bot & p2)
{
    bit_bot *children = new bit_bot(p1, p2);
    children->mutate();
    return children;
}



