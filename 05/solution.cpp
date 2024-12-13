
/************************
 * Day 5:  Print Queue  *
 ************************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include "../utils/util.h"

using namespace std;

static const bool PART_2_ENABLED = false;

pair<int, int> parseRule(string rule) {
    return {stoi(rule.substr(0, 2)), stoi(rule.substr(3, 2))};
}

unordered_map<int, vector<int>> createRuleMap(vector<string> rules) {
    unordered_map<int, vector<int>> ruleMap;
    for(string rule: rules) {
        pair<int, int> ruleNumbers = parseRule(rule);
        ruleMap[ruleNumbers.first].push_back(ruleNumbers.second);
    }
    return ruleMap;
}

pair<vector<string>, vector<string>> splitInputIntoTwoParts(vector<string> lines) {
    vector<string> partOne;
    vector<string> partTwo;
    bool partOneFinished = false;
    for(string line: lines) {
        if(line.size() == 0) {
            partOneFinished = true;
            continue;
        }
        if(partOneFinished) {
            partTwo.push_back(line);
        } else {
            partOne.push_back(line);
        }
    }
    return {partOne, partTwo};
}

vector<int> parseUpdateLine(const string& str) {
    vector<int> result;
    stringstream ss(str);
    string token;

    while (getline(ss, token, ',')) {
        result.push_back(stoi(token));
    }
    return result;
}

vector<vector<int>> parseUpdateLines(vector<string> updateLines) {
    vector<vector<int>> result;
    for(string line: updateLines) {
        result.push_back(parseUpdateLine(line));
    }
    return result;
}

bool isValidUpdate(vector<int> update, unordered_map<int, vector<int>> &rules) {
    for(int i = 0; i < update.size(); i++) {
        int currentPageNumber = update[i];
        vector<int> rulesForCurrentPageNumber = rules[currentPageNumber];
    }
}

long long part2(vector<string> lines) {
    // TODO
    return -1;
}

long long part1(vector<string> lines) {
    pair<vector<string>, vector<string>> splitInput = splitInputIntoTwoParts(lines);
    unordered_map<int, vector<int>> ruleMap = createRuleMap(splitInput.first);
    vector<vector<int>> updatesList = parseUpdateLines(splitInput.second);

    long long result = 0;
    for(vector<int> update: updatesList) {
        if(isValidUpdate(update, ruleMap)) {
            result++;
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