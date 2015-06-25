#include <iostream>
#include <string>
#include <stdio.h>
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
            app = apps[FALLOUT-1];
            break;
        case FALLOUT_LAUNCHER:
            app = apps[FALLOUT_LAUNCHER-1];
            break;
        case FOSE:
            app = apps[FOSE-1];
            break;
        case MOD_ORGANIZER:
            app = apps[MOD_ORGANIZER-1];
            break;
    }
    app.run();
    return 0;
}
