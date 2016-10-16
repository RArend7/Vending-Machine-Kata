#include "VendingMachine.h"
using namespace std;

VendingMachine::VendingMachine()
{
    coinHopper = CoinHopper();
    coinContainer = CoinContainer();
    coinReturn = CoinReturn();
    displayModule = DisplayModule();
}

VendingMachine::~VendingMachine()
{
    //dtor
}

void VendingMachine::insert_coin(string coin)
{
    float coin_value = coinHopper.insert_coin(coin);
    if (coin_value > 0.0f)
    {
        accept_coin(coin, coin_value);
    }
    else
    {
        reject_coin(coin);
    }
}

void VendingMachine::accept_coin(string coin, float value)
{
    coinContainer.deposit(coin);
    inserted_coins.push(coin);
    inserted_coins_value += value;
    displayModule.update_display(inserted_coins_value);
}

void VendingMachine::reject_coin(string coin)
{
    coinReturn.deposit(coin);
}

void VendingMachine::collect_returned_coins()
{
    coinReturn.collect_coins();
}

string VendingMachine::check_display()
{
    return displayModule.current_display_value();
}
