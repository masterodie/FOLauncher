#include <string>

#ifndef APPLICATION_H
#define APPLICATION_H

class Application {
    std::string title;
    std::string path;
	std::string exe;
	std::string args;
    public:
		Application(std::string exe);
		Application(std::string exe, std::string title);
		Application(std::string base_path, std::string exe, std::string title);
		void setTitle(std::string title);
		std::string getTitle();
		void setExecutable(std::string path);
		std::string getExecutable();
		void setArguments(std::string title);
		std::string getArguments();
		void setBasePath(std::string path);
		std::string getBasePath();
		void command();
        int run();
};
#endif

