#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H

#include <string>
#include <stack>
#include "DisplayModule.h"
#include "MachineInventory.h"
using namespace std;

class VendingMachine
{
    public:
        VendingMachine();
        virtual ~VendingMachine();
        void insert_coin(string coin);
        string check_display();
        unsigned int collect_returned_coins();
        void select_item(string item);
        void return_coins();

    protected:

    private:
        DisplayModule displayModule;
        MachineInventory machineInventory;

        unsigned int get_value_of_coin(string coin);

        stack <string> inserted_coins;
        stack <string> returned_coins;
        unsigned int inserted_coins_value;

        unsigned int total_quarters;
        unsigned int total_dimes;
        unsigned int total_nickels;

        void accept_coin(string coin, unsigned int value);
        void reject_coin(string coin);

        void dispense_item(string item);
        void display_item_price(string item);

        void make_change(unsigned int difference);

        bool exact_change_required;
        void calculate_if_exact_change_needed();
};

#endif // VENDINGMACHINE_H
