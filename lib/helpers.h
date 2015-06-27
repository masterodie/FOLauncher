#include <iostream>
#include <string>
#include <windows.h>

#ifndef GETCWD_H
#define GETCWD_H
std::string getWorkingDirectory() {
    char buffer[MAX_PATH];
    GetModuleFileName( NULL, buffer, MAX_PATH );
	std::string::size_type pos = std::string( buffer ).find_last_of( "\\/" );
    return std::string( buffer ).substr( 0, pos);
}
#endif

