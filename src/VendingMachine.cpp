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

    inserted_coins_value = 0;
}

VendingMachine::~VendingMachine()
{
    //dtor
}

void VendingMachine::insert_coin(string coin)
{
    int coin_value = coinHopper.insert_coin(coin);
    if (coin_value > 0)
    {
        accept_coin(coin, coin_value);
    }
    else
    {
        reject_coin(coin);
    }
}

void VendingMachine::accept_coin(string coin, unsigned int value)
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
    make_change(inserted_coins_value - machineInventory.get_item_price(item));
    inserted_coins_value = 0;
    while (!inserted_coins.empty())
        inserted_coins.pop();
}

void VendingMachine::display_item_price(string item)
{
    string display_string = "PRICE ";
    unsigned int item_price = machineInventory.get_item_price(item);
    char buffer [5];
    sprintf(buffer, "%.2f", (float)item_price/100);
    string price_string(buffer);
    display_string += price_string;
    displayModule.update_display(display_string);
}

void VendingMachine::make_change(unsigned int difference)
{
    string coin_to_return;
    unsigned int value_of_coin;
    while (difference > 0)
    {
        if (difference >= 25)
        {
            coin_to_return = "Quarter";
            value_of_coin = 25;
        }
        else if (difference >= 10)
        {
            coin_to_return = "Dime";
            value_of_coin = 10;
        }
        else if (difference >= 5)
        {
            coin_to_return = "Nickel";
            value_of_coin = 5;
        }

        coinContainer.withdraw(coin_to_return);
        coinReturn.deposit(coin_to_return);
        difference -= value_of_coin;
    }
}

string VendingMachine::check_display()
{
    return displayModule.current_display_value();
}
