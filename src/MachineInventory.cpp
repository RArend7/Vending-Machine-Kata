#include "MachineInventory.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;

MachineInventory::MachineInventory()
{
    highest_item_value = 0;
}

MachineInventory::~MachineInventory()
{
    // We'd need to save the existing inventory to the inventory file
    // for the purposes of being able to repeatedly run the assertions, I've not included it here
}

void MachineInventory::load_inventory(string filename)
{
    string line;
    ifstream inventory_file;
    inventory_file.open(filename.c_str());

    //ignore the first line, it just explains the file format
    getline(inventory_file, line);
    while (getline(inventory_file, line))
    {
        string item = "";
        string cost = "";
        string quantity = "";
        unsigned int string_index = 0;

        // 3 pieces of info are stored on each line, parse up to each space/newline
        for (unsigned int i = string_index; line[i] != ' '; i++)
        {
            item += line[i];
            string_index += 1;
        }
        string_index += 1;
        for (unsigned int i = string_index; line[i] != ' '; i++)
        {
            cost += line[i];
            string_index += 1;
        }
        string_index += 1;
        for (unsigned int i = string_index; line[i] != '\0'; i++)
        {
            quantity += line[i];
            string_index += 1;
        }

        item_data temp_data;
        temp_data.price = atoi(cost.c_str());
        temp_data.quantity = atoi(quantity.c_str());
        inventory[item] = temp_data;

        if (temp_data.price > highest_item_value)
            highest_item_value = temp_data.price;
    }


    inventory_file.close();
}

bool MachineInventory::select_item(string item, unsigned int money_inserted)
{
    if (inventory[item].price <= money_inserted)
    {
        inventory[item].quantity -= 1;
        return true;
    }
    else
        return false;
}

unsigned int MachineInventory::get_item_price(string item)
{
    return inventory[item].price;
}

unsigned int MachineInventory::get_item_quantity(string item)
{
    return inventory[item].quantity;
}
