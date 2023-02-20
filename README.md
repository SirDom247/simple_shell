# Simple Shell

This is a simple shell program written in C that can run basic command-line operations. The program uses `fork()` and `exec()` system calls to create child processes and execute commands.

## Installation

To build the program, clone the repository and run the following commands:

$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
$ ./hsh

## Usage

Once the program is running, enter commands in the command-line interface and hit enter to execute. The shell supports basic command-line operations such as `cd`, `ls`, `cat`, `echo`, `mkdir`, `rmdir`, `rm`, and `exit`. 

## Known Issues

- The shell program does not support pipes, redirection, or background processes.
- There may be some compatibility issues on Windows operating systems.

## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License

[MIT](https://choosealicense.com/licenses/mit/)

