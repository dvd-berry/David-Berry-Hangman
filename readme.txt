Hangman Game

I recommend that you use a g++ compiler.
If you are on windows, the g++ compiler can be downloaded in the msys2 vuild system for windows located here: 
https://github.com/msys2/msys2-installer/releases/download/2024-01-13

The executable that you will be looking for is the following, which is located in the assets dropdown on the site above:
https://github.com/msys2/msys2-installer/releases/download/2024-01-13/msys2-x86_64-20240113.exe

A new PATH should then be created to point to C:\msys64\ucrt64\bin on windows.

You will be prompted to open a terminal in which you can paste the following command:

pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain

Accept all default settings.

The program can then be compiled on the command line from the folder containing the files using the following command:
g++ main.cpp -o main.exe

And then run with:
./main.exe

This project took me 3 hours and 58 minutes to complete. My process for completing this project was to start by creating a Hangman class and conceptualizing how I felt the overall structure of the project would be. I proceeded by adding all of the member variables and functions at the beginning that I imagined would be necessary, and then I proceeded by implementing the early portion of the game, from beginning to end. As I wrote the code for the project, I added any variables or functions that I had not anticipated needing at conceptualization. I finished writing the overall structure from beginning to end of my code at around 2 hours, and then I spent the remainder of the time debugging and cleaning up formatting issues, which took surprisingly long. In full disclosure, there was one bug that I felt unable to solve while debugging after roughly 15 minutes, at which point I asked my dad to look at that line and see if he could figure out what was going wrong with it. 

That line of code was:
incorrectLetters(string) += c(char) + ", ";

The problem this code was causing was that when I printed incorrectLetters, it printed "orrec" and after messing around with it in debugging, "rrect", when it should have simply been a character and a comma. When I was debugging it I put a break point in the line and watched as I ran this line of code. I hovered over c, and it was 'Z', and I hovered over ", ", and it was simply itself, and incorrectLetters was "". When I stepped over to the next line, incorrectLetters turned into "rrect", which made no sense to me. I looked for anywhere there might be a string of the word "correct", or of the substring "rrec", but there was nothing that seemed it could have interfered, and which point I asked my dad, because the error seemed so impossible, who had to look at it for a while himself. He showed me how to put a watch on c + ", ", which he had done, and learned that the problem was that it was attempting to concatinate a char, so it translated ", " into a numerical value of some sort, which ended up pointing the overall value that was being added to incorrectLetters to an address of some sort of output stream that had said the word correct. After he helped me with that, I solved the rest of the project on my own.

The primary things I was seeking in my debugging phase were any edge case errors I could find in program path flow or in the appearance and organization of the output.

I used a class so as to have a main function that was very clean. I kept the prompt to ask the user if they wanted to play a game in main so that an unneccesary object would not be created, and because I can imagine that this functionality could want to be extended to choose from a library of games.

I implemented the lists of words that had been used, and letters that could be guessed so that I could have the most efficient big O run time of O(log(n)) for the needed functionality, so that my repetetive find() statements would not be on O(n) time as they would if I used a vector, linked list, or array.

I took a minimalist commenting approach to explain any parts of the code that would not be intrinsically understandable based on variable names or logic, to make the files the cleanest they could be for future programmers, though I understand that commenting approach should be adjusted based on the needs of a team or according to coding standards for the team.
