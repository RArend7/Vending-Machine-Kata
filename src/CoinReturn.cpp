#include "CoinReturn.h"

#include <iostream>

CoinReturn::CoinReturn()
{
    //ctor
}

CoinReturn::~CoinReturn()
{
    //dtor
}

void CoinReturn::deposit(string coin)
{
    coin_tray.push(coin);
}

void CoinReturn::collect_coins()
{
    cout << "Collected coins from the coin return:" << endl;
    while (!coin_tray.empty())
    {
        cout << coin_tray.top() << endl;
        coin_tray.pop();
    }
}
