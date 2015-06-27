#include <iostream>
#include <conio.h>

#include "CommandlineInterface.h"
#include "constants.cpp"


void CommandlineInterface::print_choices()
{
    std::cout << "Fallout 3 Launcher (ESC quits)" << std::endl << std::endl;
    std::cout << "<" << FALLOUT << "> Start Fallout 3" << std::endl;
    std::cout << "<" << FALLOUT_LAUNCHER << "> Start Fallout 3 Launcher" << std::endl;
    std::cout << "<" << FOSE << "> Start Fallout Script Extener" << std::endl;
    std::cout << "<" << MOD_ORGANIZER << "> Start Mod Organizer" << std::endl;
    std::cout << std::endl;
}

int CommandlineInterface::wait_for_input()
{
    char c;
    c = getch();
    while(c != 27) {
        switch(int g = c - 48){
            case FALLOUT:
                std::cout << "Starting Fallout 3" << std::endl;
                return g;
            case FALLOUT_LAUNCHER:
                std::cout << "Starting Fallout Launcher" << std::endl;
                return g;
            case FOSE:
                std::cout << "Starting Fallout Script Extender" << std::endl;
                return g;
            case MOD_ORGANIZER:
                std::cout << "Starting Mod Organizer" << std::endl;
                return g;
        }
        c = getch();
    }
    return -1;
}

