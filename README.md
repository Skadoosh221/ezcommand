# EZcommand
It makes it easy to access/call functions by user input.

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
  vector<string> params {"I'm so cool."};

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
  std::cout << "You say: " << param[0];
}

void main() {
  string cmd;
  vector<string> params;

  // Puts the command into a functionlist to be used.
  cm.PushCommand(test, "test_command_name");
  
  // This will get the input of the user and store their command and parameters in cmd and params respectively.
  cm.GetCommandInput(cmd, params);
  
  cm.UseCommand(cmd, params);
}
```
Well great job now you can become the EZ EXPERT!
