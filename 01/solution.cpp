
/*****************************
 * Day 1: Historian Hysteria *
 *****************************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include "../utils/util.h"

using namespace std;

static const bool PART_2_ENABLED = true;

pair<vector<int>, vector<int>> parseIntoSortedColumns(vector<string> lines) {
    vector<vector<string>> wordsInLines = parseAllLines(lines);
    vector<int> firstColumn;
    vector<int> secondColumn;
    for(vector<string> wordsInLine: wordsInLines) {
        firstColumn.push_back(stoi(wordsInLine[0]));
        secondColumn.push_back(stoi(wordsInLine[1]));
    }

    sort(firstColumn.begin(), firstColumn.end());
    sort(secondColumn.begin(), secondColumn.end());
    return make_pair(firstColumn, secondColumn);
}

long long part2(vector<string> lines) {
    pair<vector<int>, vector<int>> sortedColumns = parseIntoSortedColumns(lines);

    int startJ = 0;
    int previousN = 0;
    int previousSimilarityScore = 0;
    int sumSimilarities = 0;
    for(int i = 0; i < sortedColumns.first.size(); i++) {
        int n = sortedColumns.first[i];
        if(n == previousN) {
            sumSimilarities += previousSimilarityScore;
            continue;
        }

        int secondColumnNCount = 0;
        for(int j = startJ; j < sortedColumns.second.size(); j++) {
            if(sortedColumns.second[j] == n) {
                secondColumnNCount++;
                continue;
            }
            if(sortedColumns.second[j] > n) {
                startJ = j;
                break;
            }
        }
        int similarityScore = n * secondColumnNCount;
        previousSimilarityScore = similarityScore;
        sumSimilarities += similarityScore;
    }

    return sumSimilarities;
}

long long part1(vector<string> lines) {
    pair<vector<int>, vector<int>> sortedColumns = parseIntoSortedColumns(lines);
    long long sumDistance = 0;
    for(int i = 0; i < sortedColumns.first.size(); i++) {
        sumDistance += abs(sortedColumns.first[i] - sortedColumns.second[i]);
    }
    return sumDistance;
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