#ifndef COINHOPPER_H
#define COINHOPPER_H

#include <string>

using namespace std;

class CoinHopper
{
    public:
        CoinHopper();
        virtual ~CoinHopper();

        unsigned int insert_coin(string coin);

    protected:

    private:
};

#endif // COINHOPPER_H
