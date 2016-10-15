#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H

#include <string>
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

    protected:

    private:
        CoinHopper coinHopper();
        CoinContainer coinContainer();
        CoinReturn coinReturn();
        DisplayModule displayModule();
};

#endif // VENDINGMACHINE_H
