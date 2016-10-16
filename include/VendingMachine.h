#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H

#include <string>
#include <stack>
#include "CoinHopper.h"
#include "CoinContainer.h"
#include "CoinReturn.h"
#include "DisplayModule.h"
using namespace std;

class VendingMachine
{
    public:
        VendingMachine();
        virtual ~VendingMachine();
        void insert_coin(string coin);
        string check_display();
        void collect_returned_coins();

    protected:

    private:
        CoinHopper coinHopper;
        CoinContainer coinContainer;
        CoinReturn coinReturn;
        DisplayModule displayModule;

        stack <string> inserted_coins;
        float inserted_coins_value;

        void accept_coin(string coin, float value);
        void reject_coin(string coin);
};

#endif // VENDINGMACHINE_H
