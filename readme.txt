Hangman Game

I recommend that you use a g++ compiler.
The g++ compiler can be downloaded here: https://github.com/msys2/msys2-installer/releases/download/2024-01-13/msys2-x86_64-20240113.exe

A new PATH should then be created to point to C:\msys64\ucrt64\bin on windows.

You will be prompted to open a terminal in which you can paste the following command:

pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain

Accept all default settings