#include "VendingMachine.h"
#include <stdio.h>
#include <iostream>
using namespace std;

VendingMachine::VendingMachine()
{
    displayModule = DisplayModule();
    machineInventory = MachineInventory();
    machineInventory.load_inventory("inventory.txt");

    inserted_coins_value = 0;
    total_quarters = 5;
    total_dimes = 5;
    total_nickels = 5;
    exact_change_required = false;
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
    if (coin_value > 0 && inserted_coins_value < machineInventory.highest_item_value)
        accept_coin(coin, coin_value);
    else
        reject_coin(coin);
}

void VendingMachine::accept_coin(string coin, unsigned int value)
{
    if (coin == "Quarter")
        total_quarters += 1;
    else if (coin == "Dime")
        total_dimes += 1;
    else if (coin == "Nickel")
        total_nickels += 1;
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
    if (machineInventory.get_item_quantity(item) > 0)
    {
        if (exact_change_required == true && inserted_coins_value == machineInventory.get_item_price(item))
        {
            machineInventory.select_item(item, inserted_coins_value);
            dispense_item(item);
        }
        else if (exact_change_required == false)
        {
            if (machineInventory.select_item(item, inserted_coins_value))
                dispense_item(item);
            else
                display_item_price(item);
        }
    }
    else
    {
        displayModule.update_display("SOLD OUT");
    }
}

void VendingMachine::dispense_item(string item)
{
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
        if (difference >= get_value_of_coin("Quarter") && total_quarters > 0)
        {
            coin_to_return = "Quarter";
            value_of_coin = get_value_of_coin("Quarter");
            total_quarters -= 1;
        }
        else if (difference >= get_value_of_coin("Dime") && total_dimes > 0)
        {
            coin_to_return = "Dime";
            value_of_coin = get_value_of_coin("Dime");
            total_dimes -= 1;
        }
        else if (difference >= get_value_of_coin("Nickel") && total_nickels > 0)
        {
            coin_to_return = "Nickel";
            value_of_coin = get_value_of_coin("Nickel");
            total_nickels -= 1;
        }

        returned_coins.push(coin_to_return);
        difference -= value_of_coin;
    }
    calculate_if_exact_change_needed();

    if (exact_change_required == true)
    {
        displayModule.update_display("EXACT CHANGE ONLY");
        displayModule.update_display("THANK YOU");
    }
    else
    {
        displayModule.update_display("INSERT COIN");
        displayModule.update_display("THANK YOU");
    }

}

void VendingMachine::return_coins()
{
    cout << "Depositing coins into the coin return: " << endl;
    while (!inserted_coins.empty())
    {
        string coin = inserted_coins.top();
        cout << coin << endl;
        inserted_coins.pop();
        returned_coins.push(coin);
    }
    inserted_coins_value = 0;
    displayModule.update_display("INSERT COIN");
}

string VendingMachine::check_display()
{
    return displayModule.current_display_value();
}

void VendingMachine::calculate_if_exact_change_needed()
{
    unsigned int value_delta = get_value_of_coin("Quarter") - get_value_of_coin("Nickel");
    if (total_nickels * get_value_of_coin("Nickel") < value_delta)
    {
        exact_change_required = true;
    }
}
