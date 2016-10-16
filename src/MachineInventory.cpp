#include "MachineInventory.h"

MachineInventory::MachineInventory()
{
    //ctor
    inventory["cola"] = 1.00f;
    inventory["chips"] = 0.50;
    inventory["candy"] = 0.65f;
}

MachineInventory::~MachineInventory()
{
    //dtor
}

bool MachineInventory::select_item(string item, float money_inserted)
{
    if (inventory[item] <= money_inserted)
        return true;
    else
        return false;
}

float MachineInventory::get_item_price(string item)
{
    return inventory[item];
}
