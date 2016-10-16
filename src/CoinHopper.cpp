#include "CoinHopper.h"

CoinHopper::CoinHopper()
{
    //ctor
}

CoinHopper::~CoinHopper()
{
    //dtor
}

float CoinHopper::insert_coin(string coin)
{
    if (coin == "Quarter")
        return 0.25f;
    else if (coin == "Dime")
        return 0.10f;
    else if (coin == "Nickel")
        return 0.05f;
    else
        return 0.00f;
}
