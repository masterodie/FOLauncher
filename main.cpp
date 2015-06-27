#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <tclap/CmdLine.h>
#include <vector>

#include "CommandlineInterface.h"
#include "Application.h"
#include "constants.cpp"
#include "helpers.h"

using namespace std;

vector<string> splitPath(string path) {
	vector<string> tmp;
	string delimiter = "\\";
    unsigned int pos = path.find_last_of(delimiter);
    if((pos <= path.size())) {
        string substr = path.substr(0, pos);
        tmp.push_back(getWorkingDirectory() + '\\' + substr);
    tmp.push_back(path.substr(pos+1 , path.size()));
    } else {
        pos = 0;
        tmp.push_back(getWorkingDirectory());
        tmp.push_back(path);
    }
	return tmp;
}

int main(int argc, char** argv)
{
	string path_fo3 = "Fallout3.exe";
	string path_fo3_launcher = "FalloutLauncher_ORG.exe";
	string path_fose = "fose_loader.exe";
	string path_mod_organizer = "ModOrganizer\\ModOrganizer.exe";

	//Command Line Parser
	try {
		TCLAP::CmdLine cmd("FOLauner - Fallout 3 Launcher Replacement", ' ', "");
		TCLAP::SwitchArg debug_arg("d", "debug", "Debug output", cmd, false);
		TCLAP::SwitchArg disable_mod_organizer_arg("", "disable-mo", "Disable Mod Organizer's virtual filesystem", cmd, false);
		TCLAP::ValueArg<string> mod_organizer_profile_arg("p", "mod-organizer-profile", "Set Mod Organizer Profile", false, "Default", "string", cmd);
		TCLAP::ValueArg<string> path_mod_organizer_arg("", "mod-organizer-path", "Set Path to ModOrganizer.exe", false, path_mod_organizer, "string", cmd);
		TCLAP::ValueArg<string> path_fose_arg("", "fose-path", "Set Path to fose_loader.exe", false, path_fose, "string", cmd);
		TCLAP::ValueArg<string> path_fo3_launcher_arg("", "launcher-path", "Set Path to FalloutLauncher.exe", false, path_fo3_launcher, "string", cmd);
		TCLAP::ValueArg<string> path_fo3_arg("", "fallout-path", "Set Path to Fallout3.exe", false, path_fo3, "string", cmd);
		TCLAP::SwitchArg start_mod_organizer_arg("m", "mod-organizer", "Start Mod Organizer", cmd, false);
		TCLAP::SwitchArg start_fose_arg("s", "fose", "Start Fallout Script Extender", cmd, false);
		TCLAP::SwitchArg start_fo3_launcher_arg("l", "launcher", "Start Fallout 3 Launcher", cmd, false);
		TCLAP::SwitchArg start_fo3_arg("f", "fallout3", "Start Fallout 3", cmd, false);
		cmd.parse(argc, argv);

		bool debug = debug_arg.getValue();

		bool start_fo3 = start_fo3_arg.getValue();
		bool start_fo3_launcher = start_fo3_launcher_arg.getValue();
		bool start_fose = start_fose_arg.getValue();
		bool start_mod_organizer = start_mod_organizer_arg.getValue();
		path_fo3 = path_fo3_arg.getValue();
		path_fo3_launcher = path_fo3_launcher_arg.getValue();
		path_fose = path_fose_arg.getValue();
		path_mod_organizer = path_mod_organizer_arg.getValue();

		string mod_organizer_profile = mod_organizer_profile_arg.getValue();
		bool use_mod_organizer = !disable_mod_organizer_arg.getValue();

		vector<string> fo3 = splitPath(path_fo3);
		vector<string> fo3_launcher = splitPath(path_fo3_launcher);
		vector<string> fose = splitPath(path_fose);
		vector<string> mod_organizer = splitPath(path_mod_organizer);

		Application apps[4] = {
			Application(fo3[0], fo3[1], "Fallout 3"),
			Application(fo3_launcher[0], fo3_launcher[1], "Fallout 3 Launcher"),
			Application(fose[0], fose[1], "Fallout Script Extender"),
			Application(mod_organizer[0], mod_organizer[1], "Mod Organizer"),
		};

		if(use_mod_organizer) {
			for(int i = 0; i < 2; i = i+2){
				string args = "-p '" + mod_organizer_profile + "' '" + apps[i].getBasePath() + '\\' + apps[i].getExecutable() + "'";
				apps[i].setArguments(args);
                apps[i].setBasePath(apps[MOD_ORGANIZER-1].getBasePath());
                apps[i].setExecutable(apps[MOD_ORGANIZER-1].getExecutable());
			}
		}

		if(((int)start_fo3 + (int)start_fo3_launcher + (int)start_fose + (int)start_mod_organizer) > 1) {
			cout << "Please only provide one application to launch at a time.\nOnly the first argument will be used!\n" << endl;
		}

		if(start_fo3 || start_fo3_launcher || start_fose || start_mod_organizer) {
			Application app("", "", "");
			if(start_fo3) {
				app = apps[FALLOUT-1];
			} else if(start_fo3_launcher) {
				app = apps[FALLOUT_LAUNCHER-1];
			} else if(start_fose) {
				app = apps[FOSE-1];
			} else if(start_mod_organizer) {
				app = apps[MOD_ORGANIZER-1];
			}
			if(debug) cout << "Application Path: " << app.getExecutable() << endl;
			app.run();
			return 0;
		}

		CommandlineInterface c;
		c.print_choices();
		int choice = c.wait_for_input();
		Application app("", "", "");
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
	} catch (TCLAP::ArgException &e) {
		cerr << "error: " << e.error() << " for arg " << e.argId() << endl;
	}
    return 0;
}
