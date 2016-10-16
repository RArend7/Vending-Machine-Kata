#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H

#include <string>
#include <stack>
#include "CoinHopper.h"
#include "CoinContainer.h"
#include "CoinReturn.h"
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
        void collect_returned_coins();
        void select_item(string item);

    protected:

    private:
        CoinContainer coinContainer;
        CoinReturn coinReturn;
        DisplayModule displayModule;
        MachineInventory machineInventory;

        unsigned int get_value_of_coin(string coin);

        stack <string> inserted_coins;
        unsigned int inserted_coins_value;

        void accept_coin(string coin, unsigned int value);
        void reject_coin(string coin);

        void dispense_item(string item);
        void display_item_price(string item);

        void make_change(unsigned int difference);
};

#endif // VENDINGMACHINE_H
