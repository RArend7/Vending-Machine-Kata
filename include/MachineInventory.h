#ifndef MACHINEINVENTORY_H
#define MACHINEINVENTORY_H

#include <map>
#include <string>

using namespace std;

class MachineInventory
{
    public:
        MachineInventory();
        virtual ~MachineInventory();
        bool select_item(string item, unsigned int money_inserted);
        unsigned int get_item_price(string item);

    protected:

    private:
        map<string, unsigned int> inventory;
};

#endif // MACHINEINVENTORY_H
