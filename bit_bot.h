#ifndef BIT_BOT_H
#define BIT_BOT_H
#include <QBitArray>
#include <QString>
#define GENSIZE 32

class bit_bot
{
    QBitArray gens[GENSIZE];
    bool gender;
    unsigned id;

    static unsigned IDCounter;
public:
    static double mutation;

    bit_bot(double);
    bit_bot(bit_bot& , bit_bot&);

    unsigned get_id();
    unsigned get_value();
    bool get_gender();
    QString get_gender_info();

    void mutate();
    static bit_bot* to_multiply(bit_bot& , bit_bot&);

    bool operator <(bit_bot& a) {return this->get_value() < a.get_value();}
    bool operator >(bit_bot& a) {return this->get_value() > a.get_value();}

    bool operator == (bit_bot& a) {return this->get_value() == a.get_value();}
    bool operator != (bit_bot& a) {return this->get_value() != a.get_value();}


};

#endif // BIT_BOT_H
