#ifndef COINCONTAINER_H
#define COINCONTAINER_H

#include <string>
using namespace std;

class CoinContainer
{
    public:
        CoinContainer();
        virtual ~CoinContainer();
        void deposit(string coin);
        void withdraw(string coin);

    protected:

    private:
};

#endif // COINCONTAINER_H
