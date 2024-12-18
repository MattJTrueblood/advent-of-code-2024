# advent-of-code-2024

https://adventofcode.com/2024/

Advent of Code is an annual programming challenge that I am participating in this year.  Each day has a small programming problem to solve.  I'm saving each of my solution code blocks in this repo.

### How to run

Each day's challenge is in a numbered folder.  Inside that folder is a Makefile and a .cpp file.  To build the program, use:

    make build

All of the tasks thus far take a file as input, stored in the folder as input.txt.  To run the program with a given file, use:

    make run file="<FILENAME_GOES_HERE>"

Each of the tasks also has a part 1 and a part 2 which have different requirements and produce different results.  By default it will use the part 2 implementation.  To check the part 1 results instead, you can change this line located near the top of each .cpp file from:

    static const bool PART_2_ENABLED = true;

to

    static const bool PART_2_ENABLED = false;

then, re-build and run the program to get the part 1 results.

### random notes

use:

    sed -i 's/\r//g' "sample.txt"

to remove crlf characters from a text file.  Helpful for some problems where you want to copy-paste a sample from the site.  Normally the input.txt files don't have these characters but if you make a text file in windows it adds them automatically.
