#include "CoinHopper.h"

CoinHopper::CoinHopper()
{
    //ctor
}

CoinHopper::~CoinHopper()
{
    //dtor
}

unsigned int CoinHopper::insert_coin(string coin)
{
    if (coin == "Quarter")
        return 25;
    else if (coin == "Dime")
        return 10;
    else if (coin == "Nickel")
        return 5;
    else
        return 0;
}
