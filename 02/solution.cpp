
/**********************
 * Day N:  ~~~~~~~~~  *
 **********************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../utils/util.h"

using namespace std;

static const bool PART_2_ENABLED = false;

long long part2(vector<string> lines) {
    // TODO
    return -1;
}

long long part1(vector<string> lines) {
    vector<vector<string>> wordsInLines = parseAllLines(lines);
    long long safeCount = 0;

    for(vector<string> line: wordsInLines) {
        int previous = -1;
        bool descending;
        bool safe = true;
        
        for(int i = 0; i < line.size(); i++) {
            int current = stoi(line[i]);
            if(i > 0) {
                //check if diff between 1 and 3
                int diff = abs(current - previous);
                if(diff < 1 || diff > 3) {
                    safe = false;
                    break;
                }

                if(i == 1) {
                    // figure out ascending or descending
                    if(previous < current) {
                        descending = false;
                    } else {
                        descending = true;
                    }
                }
                if(i > 1) {
                    if(descending == true) {
                        if(previous < current) {
                            safe = false;
                            break;
                        }
                    }
                    if(descending == false) {
                        if(previous > current) {
                            safe = false;
                            break;
                        }
                    }
                }
            }
            previous = current;
        }
        if(safe == true) {
            safeCount++;
        }
    }

    return safeCount;
}

int main(int argc, char* argv[]) {
    //check arguments
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <filename>\n";
        return 1;
    }
    cout << "Filename: " << argv[1] << endl;

    //parse file
    vector<string> lines = parseFile(argv[1]);

    // now handle lines to generate the result
    long long result;
    if(PART_2_ENABLED) {
        result = part2(lines);
    } else {
        result = part1(lines);
    }

    //print final result to console
    cout << "result=" << result << endl;
    return 0;
}