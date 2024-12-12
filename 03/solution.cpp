
/***********************
 * Day 3: Mull It Over *
 ***********************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include "../utils/util.h"

using namespace std;

static const bool PART_2_ENABLED = true;

// sregex_iterator lets us walk through the string and get all the matches to the pattern in order
vector<string> getAllMatches(const string& line, const regex& pattern) {
    vector<string> matches;
    for (sregex_iterator it(line.begin(), line.end(), pattern), end; it != end; it++) {
        matches.push_back(it->str());
    }
    return matches;
}

// from a statement like mul(x,y), where x and y are parseable ints, returns pair<x, y>
pair<int, int> parseMulStatement(const string& match) {
    regex pattern(R"(mul\((\d{1,3}),(\d{1,3})\))");
    smatch sm;
    if (regex_match(match, sm, pattern)) {
        int num1 = stoi(sm[1].str());
        int num2 = stoi(sm[2].str());
        return {num1, num2};
    }
    return {-1, -1}; // should never go here
}

long long part2(vector<string> lines) {
    long long result = 0;

    regex combinedPattern(R"(mul\(\d{1,3},\d{1,3}\)|do\(\)|don't\(\))");

    vector<string> allMatches;
    for(string line: lines) {
        vector<string> matches = getAllMatches(line, combinedPattern);
        for(string match: matches) {
            allMatches.push_back(match);
        }
    }

    bool enabled = true;
    for(string match: allMatches) {
        if(match == "do()") {
            enabled = true;
        } else if (match == "don't()") {
            enabled = false;
        }
        else {
            pair<int, int> numbers = parseMulStatement(match);
            if(enabled) {
                result += (numbers.first * numbers.second);
            }
        }
    }

    return result;
}

long long part1(vector<string> lines) {
    long long result = 0;

    regex pattern(R"(mul\(\d{1,3},\d{1,3}\))");

    for(string line: lines) {
        
        vector<string> matches = getAllMatches(line, pattern);
        for(string match: matches) {
            pair<int, int> numbers = parseMulStatement(match);
            result += (numbers.first * numbers.second);
        }
    }
    return result;
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