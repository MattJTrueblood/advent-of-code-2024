
/*****************************
 * Day 2: Red-Nosed Reports  *
 *****************************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../utils/util.h"

using namespace std;

static const bool PART_2_ENABLED = true;

vector<vector<string>> getSkipOneVariationsOfLine(vector<string> line) {
    vector<vector<string>> result;

    for (int i = 0; i < line.size(); i++) {
        vector<string> variation = line;
        variation.erase(variation.begin() + i);
        result.push_back(variation);
    }

    return result;
}

bool lineIsSafe(vector<string> line) {
    int previous = -1;
    bool descending;
    for(int i = 0; i < line.size(); i++) {
        int current = stoi(line[i]);
        if(i > 0) {
            //check if diff between 1 and 3
            int diff = abs(current - previous);
            if(diff < 1 || diff > 3) {
                return false;
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
                        return false;
                    }
                }
                if(descending == false) {
                    if(previous > current) {
                        return false;
                    }
                }
            }
        }
        previous = current;
    }
    return true;
}

long long part2(vector<string> lines) {
    vector<vector<string>> wordsInLines = parseAllLines(lines);
    long long safeCount = 0;
    for(vector<string> line: wordsInLines) {
        vector<vector<string>> variations = getSkipOneVariationsOfLine(line);
        for(vector<string> variation: variations) {
            if(lineIsSafe(variation)) {
                safeCount++;
                break;
            }
        }
    }
    return safeCount;
}

long long part1(vector<string> lines) {
    vector<vector<string>> wordsInLines = parseAllLines(lines);
    long long safeCount = 0;

    for(vector<string> line: wordsInLines) {
        if(lineIsSafe(line)) {
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