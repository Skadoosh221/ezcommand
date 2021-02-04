#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using std::string;
using std::vector;

// For getting thos sweet command stuff
class CommandAPI {
public:
	vector<void(*)(vector<string>)> functions;
	vector<string> fnames;

	// Pushes a new function into the list along with its name
	void PushCommand(void (*f)(vector<string>), string name) {
		functions.push_back(f);
		fnames.push_back(name);
	}

	// Gets user input for a command and outputs to the referenced parameters
	void GetCommandInput(string& command, vector<string>& params) {
		string c, l, p;
		vector<string> pp;

		std::cin >> c;
		std::getline(std::cin, l);
		std::istringstream stream(l);

		while (stream >> p) {
			pp.push_back(p);
		}
		
		command = c;
		params = pp;
	}

	// Uses a function
	void UseCommand(string name, vector<string> params) {
		bool commandYes = false;
		for (int i = 0; i < fnames.size(); i++) {
			if (name == fnames[i]) {
				commandYes = true;
				functions[i](params);
			}
		}

		if (!commandYes) {
			std::cerr << "Error: " << name << " does not exist!\n";
		}
	}
};