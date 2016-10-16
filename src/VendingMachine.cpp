#include "VendingMachine.h"
#include <stdio.h>
using namespace std;

VendingMachine::VendingMachine()
{
    coinHopper = CoinHopper();
    coinContainer = CoinContainer();
    coinReturn = CoinReturn();
    displayModule = DisplayModule();
    machineInventory = MachineInventory();

    inserted_coins_value = 0.00f;
}

VendingMachine::~VendingMachine()
{
    //dtor
}

void VendingMachine::insert_coin(string coin)
{
    float coin_value = coinHopper.insert_coin(coin);
    if (coin_value > 0.00f)
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

void VendingMachine::select_item(string item)
{
    if (machineInventory.select_item(item, inserted_coins_value))
        dispense_item(item);
    else
        display_item_price(item);
}

void VendingMachine::dispense_item(string item)
{
    displayModule.update_display("THANK YOU");
    inserted_coins_value = 0.00f;
    while (!inserted_coins.empty())
        inserted_coins.pop();
}

void VendingMachine::display_item_price(string item)
{
    string display_string = "PRICE ";
    float item_price = machineInventory.get_item_price(item);
    char buffer [5];
    sprintf(buffer, "%.2f", item_price);
    string price_string(buffer);
    display_string += price_string;
    displayModule.update_display(display_string);
}

string VendingMachine::check_display()
{
    return displayModule.current_display_value();
}
