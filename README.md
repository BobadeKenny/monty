# The Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

### Monty byte code files
Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument.
## Installation
* Clone this repository
```bash
git clone https://github.com/BobadeKenny/monty.git
```
* Compile the code with ```gcc```
```bash
gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```
## Usage
```bash
monty file
```
Where ```file``` is the path to the file containing Monty byte code.

* If the user does not give any file or more than one argument to your program, print the error message ```USAGE: monty file```, followed by a new line, and exit with the status ```EXIT_FAILURE```
* If, for any reason, it’s not possible to open the file, print the error message ```Error: Can't open file <file>```, followed by a new line, and exit with the status ```EXIT_FAILURE```
where ```<file>``` is the name of the file
* If the file contains an invalid instruction, print the error message ```L<line_number>: unknown instruction <opcode>```, followed by a new line, and exit with the status ```EXIT_FAILURE```
where ```<line_number>``` is the line number where the instruction appears.
* The monty program runs the bytecodes line by line and stop if either:
    * It executed properly every line of the file
    * It finds an error in the file
    * An error occured

The interpreter currently supports the following opcodes:
* ```push``` - Pushes an element to the stack.
    * Usage: ```push <int>```

    where ```<int>``` is an integer.
* ```pall``` - Prints all the values on the stack, starting from the top of the stack.
    * Usage: ```pall```
* ```pint``` - Prints the value at the top of the stack, followed by a new line.
    * Usage: ```pint```
* ```pop``` - Removes the top element of the stack.
    * Usage: ```pop```
* ```swap``` - Swaps the top two elements of the stack.
    * Usage: ```swap```
* ```add``` - Adds the top two elements of the stack.
    * Usage: ```add```

    The result is stored in the second top element of the stack, and the top element is removed, so that at the end, the top element of the stack contains the result and the stack is one element shorter.
* ```sub``` - Subtracts the top element of the stack from the second top element of the stack.
    * Usage: ```sub```

    The result is stored in the second top element of the stack, and the top element is removed, so that at the end, the top element of the stack contains the result and the stack is one element shorter.
* ```nop``` - Does nothing.
    * Usage: ```nop```
* ```div``` - Divides the second top element of the stack by the top element of the stack.
    * Usage: ```div```

    The result is stored in the second top element of the stack, and the top element is removed, so that at the end, the top element of the stack contains the result and the stack is one element shorter.
* ```mul``` - Multiplies the second top element of the stack with the top element of the stack.
    * Usage: ```mul```

    The result is stored in the second top element of the stack, and the top element is removed, so that at the end, the top element of the stack contains the result and the stack is one element shorter.
* ```mod``` - Computes the rest of the division of the second top element of the stack by the top element of the stack.
    * Usage: ```mod```

    The result is stored in the second top element of the stack, and the top element is removed, so that at the end, the top element of the stack contains the result and the stack is one element shorter.
* ```pchar``` - Prints the char at the top of the stack, followed by a new line.
    * Usage: ```pchar```

    The integer stored at the top of the stack is treated as the ascii value of the character to be printed.

    If the value is not in the ascii table (man ascii) print the error message ```L<line_number>: can't pchar, value out of range```, followed by a new line, and exit with the status ```EXIT_FAILURE```.
* ```pstr``` - Prints the string starting at the top of the stack, followed by a new line.
    * Usage: ```pstr```
    
    The integer stored in each element of the stack is treated as the ascii value of the character to be printed.
    
    The string stops when either:
    * The stack is over
    * The value of the element is 0
    * The value of the element is not in the ascii table
* ```rotl``` - Rotates the stack to the top.
    * Usage: ```rotl```

    The top element of the stack becomes the last one, and the second top element of the stack becomes the first one.
* ```rotr``` - Rotates the stack to the bottom.
    * Usage: rotr
    
    The last element of the stack becomes the top element of the stack.