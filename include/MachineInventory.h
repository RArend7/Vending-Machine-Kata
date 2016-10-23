#ifndef MACHINEINVENTORY_H
#define MACHINEINVENTORY_H

#include <map>
#include <string>

using namespace std;

struct item_data
{
    unsigned int price;
    unsigned int quantity;
};

class MachineInventory
{
    public:
        MachineInventory();
        virtual ~MachineInventory();
        void load_inventory(string filename);
        bool select_item(string item, unsigned int money_inserted);
        unsigned int get_item_price(string item);
        unsigned int get_item_quantity(string item);

        unsigned int highest_item_value;

    protected:

    private:
        map<string, item_data> inventory;
};

#endif // MACHINEINVENTORY_H
