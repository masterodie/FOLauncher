#include <iostream>
#include <string>
#include <conio.h>

#include "CommandlineInterface.hpp"
#include "Application.hpp"
#include "constants.cpp"

int main()
{
    Application apps[4];
    CommandlineInterface c;
    c.print_choices();
    int choice = c.wait_for_input();
    Application app;
    switch(choice) {
        case FALLOUT:
            apps[FALLOUT-1].run();
            break;
        case FALLOUT_LAUNCHER:
            apps[FALLOUT_LAUNCHER-1].run();
            break;
        case FOSE:
            apps[FOSE-1].run();
            break;
        case MOD_ORGANIZER:
            apps[MOD_ORGANIZER-1].run();
            break;
    }
    return 0;
}
