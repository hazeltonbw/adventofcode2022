#include <iostream>
#include <set>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

void createRangeOfIntsForSet(set<int> &s, int start, int end) {
    for (int i = start; i < end + 1; i++) {
        s.insert(i);
    }
}

int main() {
    ifstream ins("input.txt");
    string s,e;
    int partOneSum = 0, partTwoSum = 0;
    while (ins) {
        getline(ins, s);
        if (!ins) break;
        stringstream ss(s);
        getline(ss, s, '-'); 
        getline(ss, e, ',');
        set<int> firstRange, secondRange, intersected;
        int start = stoi(s);
        int end = stoi(e);
        createRangeOfIntsForSet(firstRange, start, end);
        getline(ss, s, '-');
        getline(ss, e);
        start = stoi(s);
        end = stoi(e);
        createRangeOfIntsForSet(secondRange, start, end);
        set_intersection(firstRange.begin(), firstRange.end(), 
                        secondRange.begin(), secondRange.end(),
                        inserter(intersected, intersected.begin()));
        
        auto smallerSetSize = firstRange.size() < secondRange.size() ? firstRange.size() : secondRange.size();
        if (intersected.size() == smallerSetSize) {
            // if the intersected set is the same size as 
            // the smaller set, then the bigger set fully
            // contained the smaller set
            partOneSum++;
        }
        if (intersected.size()) {
            // if there's any intersected numbers, 
            // then there's overlap between
            // the two ranges of numbers
            partTwoSum++;
        }
    }
    cout << "There were " << partOneSum << " assignment pairs that fully contained another.\n";
    cout << "There were " << partTwoSum << " assignment pairs that overlap somehow.\n";
}