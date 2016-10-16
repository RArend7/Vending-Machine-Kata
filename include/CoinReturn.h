#ifndef COINRETURN_H
#define COINRETURN_H

#include <string>
#include <stack>
using namespace std;

class CoinReturn
{
    public:
        CoinReturn();
        virtual ~CoinReturn();
        void deposit(string coin);
        void collect_coins();

    protected:

    private:
        stack <string> coin_tray;
};

#endif // COINRETURN_H
