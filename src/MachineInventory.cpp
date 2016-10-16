#include "MachineInventory.h"

MachineInventory::MachineInventory()
{
    //ctor
    inventory["cola"] = 100;
    inventory["chips"] = 50;
    inventory["candy"] = 65;
}

MachineInventory::~MachineInventory()
{
    //dtor
}

bool MachineInventory::select_item(string item, unsigned int money_inserted)
{
    if (inventory[item] <= money_inserted)
        return true;
    else
        return false;
}

unsigned int MachineInventory::get_item_price(string item)
{
    return inventory[item];
}
