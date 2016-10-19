#include <iostream>
#include <string>
#include <cassert>

#include "VendingMachine.h"

using namespace std;

void test_coin_input();
void test_item_selection();
void test_change_return();
void test_coin_return();

int main()
{
    test_coin_input();
    test_item_selection();
    test_change_return();
    test_coin_return();

    return 0;
}

void test_coin_input()
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

    cout << endl;
}

void test_item_selection()
{
    VendingMachine testVendingMachine;
    testVendingMachine.insert_coin("Quarter");
    testVendingMachine.select_item("cola");
    string current_display = testVendingMachine.check_display();
    cout << "Inserted 0.25 dollars, selected cola, checking display: " << current_display << endl;
    assert(current_display == "PRICE 1.00");

    cout << "Checking display again: " << testVendingMachine.check_display() << endl;
    assert(testVendingMachine.check_display() == "0.25");

    testVendingMachine.insert_coin("Quarter");
    testVendingMachine.insert_coin("Quarter");
    testVendingMachine.select_item("candy");
    current_display = testVendingMachine.check_display();
    cout << "inserted 2 more quarters, selected candy, checking display: " << current_display << endl;
    assert(current_display == "THANK YOU");

    cout << "Checking display again: " << testVendingMachine.check_display() << endl;
    assert(testVendingMachine.check_display() == "INSERT COIN");

    cout << endl;
}

void test_change_return()
{
    VendingMachine testVendingMachine;
    testVendingMachine.insert_coin("Quarter");
    testVendingMachine.insert_coin("Quarter");
    testVendingMachine.insert_coin("Quarter");
    testVendingMachine.insert_coin("Dime");
    testVendingMachine.select_item("chips");
    string current_display = testVendingMachine.check_display();
    cout << "Inserted 0.85 dollars, spending 0.50, checking display: " << current_display << endl;
    assert(current_display == "THANK YOU");
    assert(testVendingMachine.collect_returned_coins() == 35);

    testVendingMachine.insert_coin("Quarter");
    testVendingMachine.insert_coin("Quarter");
    testVendingMachine.insert_coin("Quarter");
    testVendingMachine.select_item("candy");
    cout << "Inserted 0.75 dollars, spending 0.65, checking display: " << current_display << endl;
    assert(testVendingMachine.collect_returned_coins() == 10);

    testVendingMachine.insert_coin("Quarter");
    testVendingMachine.insert_coin("Quarter");
    testVendingMachine.insert_coin("Quarter");
    testVendingMachine.insert_coin("Quarter");
    testVendingMachine.select_item("cola");
    cout << "Inserted 1.00 dollars, spending 1.00, checking display: " << current_display << endl;
    assert(testVendingMachine.collect_returned_coins() == 0);

    cout << endl;
}

void test_coin_return()
{
    VendingMachine testVendingMachine;
    testVendingMachine.insert_coin("Quarter");
    testVendingMachine.insert_coin("Quarter");
    testVendingMachine.insert_coin("Quarter");
    testVendingMachine.insert_coin("Quarter");
    cout << "Inserted 4 quarters, returning coins" << endl;
    testVendingMachine.return_coins();
    assert(testVendingMachine.collect_returned_coins() == 100);

    testVendingMachine.insert_coin("Quarter");
    testVendingMachine.insert_coin("Dime");
    testVendingMachine.insert_coin("Nickel");
    testVendingMachine.insert_coin("Quarter");
    cout << "Inserted 2 quarters, 1 dime, and 1 nickel: returning coins" << endl;
    testVendingMachine.return_coins();
    assert(testVendingMachine.collect_returned_coins() == 65);
}
