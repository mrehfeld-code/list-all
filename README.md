# list-all
`list-all` is a simple one-file C application. It lists all files in all subdirectories
in a root directory.

### Usage
If no command line argument is given `list-all` uses the current directory
as root dir. It gets the total path of the current directory with `getenv()`
and the environment variable `$PWD`, so it only works on Linux and macOS systems.
If one or more arguments are given `list-all` uses the first command line argument
as root directory.

### Installation
Just run the commands below and have fun. 
```bash
git clone https://github.com/mrehfeld-code/list-all 
cd list-all 
cmake -S . -B build
cd build
make list-all 
sudo make install
```

### Terms of Use
This project is licensed under the MIT License. You are allowed to use, copy,
change and sell the code on your own. 
