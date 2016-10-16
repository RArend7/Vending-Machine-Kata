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
        bool select_item(string item, float money_inserted);
        float get_item_price(string item);

    protected:

    private:
        map<string, float> inventory;
};

#endif // MACHINEINVENTORY_H
