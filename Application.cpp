#include <iostream>

#include "Application.hpp"

Application::Application()
{
    name = "Untitled";
    path = ".";
}

Application::Application(std::string n, std::string p)
{
    name = n;
    path = p;
}

int Application::run()
{
    std::cout << "Hello App";
    return 0;
}
