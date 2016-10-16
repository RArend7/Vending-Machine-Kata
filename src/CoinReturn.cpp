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
    unsigned int number_of_coins_in_return = coin_tray.size();
    for (unsigned int i = 0; i < number_of_coins_in_return; i++)
    {
        cout << coin_tray.top() << endl;
        coin_tray.pop();
    }
}
