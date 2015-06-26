#include <string>

#ifndef APPLICATION_H
#define APPLICATION_H

class Application {
    std::string name;
    std::string path;
    public:
		Application();
		Application(std::string name, std::string path);
        int run();
};
#endif

