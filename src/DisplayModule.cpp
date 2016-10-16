#include "DisplayModule.h"

#include <stdio.h>

DisplayModule::DisplayModule()
{
    //ctor
    message = "INSERT COIN";
}

DisplayModule::~DisplayModule()
{
    //dtor
}

void DisplayModule::update_display(string new_message)
{
    message = new_message;
}

void DisplayModule::update_display(float new_value)
{
    char buffer [5];
    sprintf(buffer, "%.2f", new_value);
    string new_string(buffer);
    message = new_string;
}

string DisplayModule::current_display_value()
{
    return message;
}
