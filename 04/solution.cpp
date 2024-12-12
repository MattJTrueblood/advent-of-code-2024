
/************************
 * Day 4: Ceres Search  *
 ************************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../utils/util.h"

using namespace std;

static const bool PART_2_ENABLED = false;

// find the number of times a substr appears in a string
int countOccurancesInString(string str, string substr) {
    int count = 0;
    int pos = str.find(substr);
    while (pos < str.size()) {
        count++;
        pos = str.find(substr, pos + substr.size());
    }
    return count;
}

// find all horizontal, vertical, diagonal and reverse lines in a grid
vector<string> getAllGridLines(vector<string> lines) {
    vector<string> allGridLines;

    //horizontal
    for(string line: lines) {
        allGridLines.push_back(line);
        allGridLines.push_back(string(line.rbegin(), line.rend()));
    }

    //vertical
    for(int col = 0; col < lines[0].size(); col++) {
        string current = "";
        for(int row = 0; row < lines.size(); row++) {
            current.push_back(lines[row][col]);
        }
        allGridLines.push_back(current);
        allGridLines.push_back(string(current.rbegin(), current.rend()));
    }

    //diagonals
    //going diagonal-down-right
    for(int startRow = 0; startRow < lines.size(); startRow++) {
        int row = startRow;
        string current = "";
        for(int col = 0; col < lines[0].size(); col++) {
            current.push_back(lines[row][col]);
            row++;
            if(row >= lines.size()) {
                break;
            }
        }
        allGridLines.push_back(current);
        allGridLines.push_back(string(current.rbegin(), current.rend()));
    }
    for(int startCol = 1; startCol < lines[0].size(); startCol++) {
        int col = startCol;
        string current = "";
        for(int row = 0; row < lines.size(); row++) {
            current.push_back(lines[row][col]);
            col++;
            if(col >= lines[0].size()) {
                break;
            }
        }
        allGridLines.push_back(current);
        allGridLines.push_back(string(current.rbegin(), current.rend()));
    }

    //going diagonal-up-right
    for(int startRow = 0; startRow < lines.size(); startRow++) {
        int row = startRow;
        string current = "";
        for(int col = lines[0].size() - 1; col >= 0; col--) {
            current.push_back(lines[row][col]);
            row++;
            if(row >= lines.size()) {
                break;
            }
        }
        allGridLines.push_back(current);
        allGridLines.push_back(string(current.rbegin(), current.rend()));
    }
    for(int startCol = 0; startCol < lines[0].size() -1; startCol++) {
        int col = startCol;
        string current = "";
        for(int row = 0; row < lines.size(); row++) {
            current.push_back(lines[row][col]);
            col--;
            if(col < 0 ) {
                break;
            }
        }
        allGridLines.push_back(current);
        allGridLines.push_back(string(current.rbegin(), current.rend()));
    }

    return allGridLines;
}

long long part2(vector<string> lines) {
    // TODO
    return -1;
}

long long part1(vector<string> lines) {

    vector<string> allGridLines = getAllGridLines(lines);
    long long count = 0;
    for(string gridLine: allGridLines) {
        count += countOccurancesInString(gridLine, "XMAS");
    }

    return count;
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