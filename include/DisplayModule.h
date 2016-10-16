#ifndef DISPLAYMODULE_H
#define DISPLAYMODULE_H

#include <string>
using namespace std;

class DisplayModule
{
    public:
        DisplayModule();
        virtual ~DisplayModule();
        void update_display(string new_message);
        void update_display(float new_value);
        string current_display_value();

    protected:

    private:
        string message;
};

#endif // DISPLAYMODULE_H
