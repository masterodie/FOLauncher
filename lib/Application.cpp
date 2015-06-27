#include <iostream>
#include <windows.h>
#include <shellapi.h>

#include "Application.h"

Application::Application(std::string b, std::string e, std::string t)
{
    title = t;
    path = b;
    exe = e;
    args = "";
}

void Application::setTitle(std::string t)
{
    title = t;
}

std::string Application::getTitle() {
    return title;
}

void Application::setExecutable(std::string e)
{
    exe = e;
}

std::string Application::getExecutable()
{
    return exe;
}

void Application::setArguments(std::string a) {
    args = a;
}

std::string Application::getArguments()  {
    return args;
}

void Application::setBasePath(std::string p)
{
    path = p;
}

std::string Application::getBasePath()
{
    return path;
}

int Application::run()
{
    command();
    return 0;
}

void Application::command()
{
    SHELLEXECUTEINFO shExecInfo;

    shExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);

    shExecInfo.fMask = 0;
    shExecInfo.hwnd = NULL;
    shExecInfo.lpVerb = "runas";
    shExecInfo.lpFile = exe.c_str();
    shExecInfo.lpParameters = args.c_str();
    shExecInfo.lpDirectory = path.c_str();
    shExecInfo.nShow = SW_NORMAL;
    shExecInfo.hInstApp = NULL;

    ShellExecuteEx(&shExecInfo);

    std::cout << "Applicatoin \"" << title << "\" has been started" << std::endl;
    std::cout << "Executable: \"" << exe << "\"" << std::endl;
    std::cout << "in diectory: \"" << path << "\"" << std::endl;
    std::cout << "with arguments: \"" << args << "\"" << std::endl;
}

