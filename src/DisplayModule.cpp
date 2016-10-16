#include "DisplayModule.h"

#include <stdio.h>

DisplayModule::DisplayModule()
{
    //ctor
    message = "INSERT COIN";
    previous_message = "";
}

DisplayModule::~DisplayModule()
{
    //dtor
}

void DisplayModule::update_display(string new_message)
{
    previous_message = message;
    message = new_message;
}

void DisplayModule::update_display(float new_value)
{
    previous_message = message;
    char buffer [5];
    sprintf(buffer, "%.2f", new_value);
    string new_string(buffer);
    message = new_string;
}

string DisplayModule::current_display_value()
{
    string return_message = message;

    if (message == "THANK YOU")
    {
        update_display("INSERT COIN");
    }
    else if (message[0] == 'P')
    {
        update_display(previous_message);
    }

    return return_message;
}
