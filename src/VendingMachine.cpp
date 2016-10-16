#include "VendingMachine.h"
#include <stdio.h>
#include <iostream>
using namespace std;

VendingMachine::VendingMachine()
{
    coinContainer = CoinContainer();
    displayModule = DisplayModule();
    machineInventory = MachineInventory();

    inserted_coins_value = 0;
}

VendingMachine::~VendingMachine()
{
    //dtor
}

unsigned int VendingMachine::get_value_of_coin(string coin)
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

void VendingMachine::insert_coin(string coin)
{
    unsigned int coin_value = get_value_of_coin(coin);
    if (coin_value > 0)
        accept_coin(coin, coin_value);
    else
        reject_coin(coin);
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
    returned_coins.push(coin);
}

unsigned int VendingMachine::collect_returned_coins()
{
    cout << "Collected coins from the coin return:" << endl;
    unsigned int total_value = 0;
    while (!returned_coins.empty())
    {
        cout << returned_coins.top() << endl;
        total_value += get_value_of_coin(returned_coins.top());
        returned_coins.pop();
    }
    return total_value;
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
        if (difference >= get_value_of_coin("Quarter"))
        {
            coin_to_return = "Quarter";
            value_of_coin = get_value_of_coin("Quarter");
        }
        else if (difference >= get_value_of_coin("Dime"))
        {
            coin_to_return = "Dime";
            value_of_coin = get_value_of_coin("Dime");
        }
        else if (difference >= get_value_of_coin("Nickel"))
        {
            coin_to_return = "Nickel";
            value_of_coin = get_value_of_coin("Nickel");
        }

        coinContainer.withdraw(coin_to_return);
        returned_coins.push(coin_to_return);
        difference -= value_of_coin;
    }
}

string VendingMachine::check_display()
{
    return displayModule.current_display_value();
}
