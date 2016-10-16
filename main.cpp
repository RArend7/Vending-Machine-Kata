#include <iostream>
#include <string>
#include <cassert>

#include "VendingMachine.h"

using namespace std;

int main()
{
    VendingMachine testVendingMachine;

    cout << "Checking display without coins inserted: " << testVendingMachine.check_display() << endl;
    assert(testVendingMachine.check_display() == "INSERT COIN");

    testVendingMachine.insert_coin("Quarter");
    cout << "Inserted quarter, re-checking display: " << testVendingMachine.check_display() << endl;
    assert(testVendingMachine.check_display() == "0.25");

    testVendingMachine.insert_coin("Dime");
    cout << "Inserted dime, re-checking display: " << testVendingMachine.check_display() << endl;
    assert(testVendingMachine.check_display() == "0.35");

    testVendingMachine.insert_coin("Nickel");
    cout << "Inserted nickel, re-checking display: " << testVendingMachine.check_display() << endl;
    assert(testVendingMachine.check_display() == "0.40");

    testVendingMachine.insert_coin("Penny");
    cout << "Inserted penny, re-checking display: " << testVendingMachine.check_display() << endl;
    assert(testVendingMachine.check_display() == "0.40");

    testVendingMachine.insert_coin("Canadian Quarter");
    cout << "Inserted Canadian quarter, re-checking display: " << testVendingMachine.check_display() << endl;
    assert(testVendingMachine.check_display() == "0.40");

    testVendingMachine.insert_coin("quarter");
    cout << "Inserted counterfeit quarter, re-checking display: " << testVendingMachine.check_display() << endl;
    assert(testVendingMachine.check_display() == "0.40");

    testVendingMachine.insert_coin("Quarter");
    testVendingMachine.insert_coin("Quarter");
    testVendingMachine.insert_coin("Quarter");
    cout << "Inserted 3 quarters, re-checking display: " << testVendingMachine.check_display() << endl;
    assert(testVendingMachine.check_display() == "1.15");

    testVendingMachine.collect_returned_coins();

    return 0;
}
