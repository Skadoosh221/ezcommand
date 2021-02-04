# EZcommand
It makes it easy to access/call functions by user input. For C++ users.

## How to use
First you need to initialize it and include the header.
  
```cpp
#include "ezcommand.h"
CommandAPI cm;
```

Then you put in a function you want to use along with a name and put the parameter as ```vector<string>``` (```vector<string>``` is always neccesary even if your function doesn't use parameters and you cannot use any other vector type). e.g:
  
```cpp
#include "ezcommand.h"
#include <iostream>
CommandAPI cm;

void test(vector<string> param) {
	std::cout << "Oh hi mark.\n";
}

void main() {
	// Puts the command into a functionlist to be used.
	cm.PushCommand(test, "test_command_name");
}
```

And then you can call it using something like this:

```cpp
#include "ezcommand.h"
#include <iostream>
CommandAPI cm;

void test(vector<string> param) {
	std::cout << "Oh hi mark.\n";
	std::cout << "You say: " << param[0];
}

void main() {
	string command = "test_command_name";
	vector<string> params{ "I'm so cool." };

	// Puts the command into a functionlist to be used.
	cm.PushCommand(test, "test_command_name");
	cm.UseCommand(command, params);
}
```

If you want to have user input instead you can use:
```cpp
#include "ezcommand.h"
#include <iostream>
CommandAPI cm;

void test(vector<string> param) {
	std::cout << "Oh hi mark.\n";
	std::cout << "You say: ";
	for (auto t : param) {
		std::cout << t << " ";
	}
}

void main() {
	string cmd;
	vector<string> params;

	// Puts the command into a functionlist to be used.
	cm.PushCommand(test, "say");

	// This will get the input of the user and store their command and parameters in cmd and params respectively.
	cm.GetCommandInput(cmd, params);

	cm.UseCommand(cmd, params);
}
```
Here is another example:
```cpp
#include "ezcommand.h"
using namespace std;
CommandAPI cm;
int kd = 0;

// Command Functions
void test(vector<string> params) {
	for (auto t : params) {
		kd += stoi(t);
	}
}

void test2(vector<string> params) {
	for (auto t : params) {
		kd -= stoi(t);
	}
}

// MAIN
int main() {
	cm.PushCommand(test, "add");
	cm.PushCommand(test2, "sub");

	string command;
	vector<string> params;

	while (1) {
		cout << "Your command sir: ";
		cm.GetCommandInput(command, params);
		cm.UseCommand(command, params);
		cout << kd << endl;
	}

	return 0;
}
```
