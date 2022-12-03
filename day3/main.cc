#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
using namespace std;

void part1() {
    ifstream ins("sample.txt");
    string s;
    int sum = 0;
    while (ins) {
        getline(ins, s);
        if (!ins) break;
        set<char> firstHalf(s.begin(), s.begin() + (s.size() / 2));
        set<char> secondHalf(s.begin() + (s.size() / 2), s.end());
        set<char> intersected;
        set_intersection(firstHalf.begin(), firstHalf.end(), secondHalf.begin(), secondHalf.end(), inserter(intersected, intersected.begin()));
        for (auto c : intersected) {
            isupper(c) ? sum += c - 38 : sum += c - 96; /// A a Z z
            //cout << "CHARACTER " << c << " " << (isupper(c) ? c - 38 : c - 96) << " ";
        }
    }
    cout << "Part 1 - SUM: " << sum << endl;
}

void part2() {
    ifstream ins("input.txt");
    string one, two, three;
    int sum = 0;
    while (ins) {
        getline(ins, one);
        if (!ins) break;
        getline(ins, two);
        getline(ins, three);
        set<char> first(one.begin(), one.end());
        set<char> second(two.begin(), two.end());
        set<char> third(three.begin(), three.end());
        set<char> intersected;
        set<char> intersected2;
        set_intersection(first.begin(), first.end(), second.begin(), second.end(), inserter(intersected, intersected.begin()));
        set_intersection(intersected.begin(), intersected.end(), third.begin(), third.end(), inserter(intersected2, intersected2.begin()));
        for (auto c : intersected2) {
            isupper(c) ? sum += c - 38 : sum += c - 96; /// A a Z z
            //cout << c << endl;
        }
    }
    cout << "Part 2 - SUM: " << sum << endl;
}

int main() {
    part1();
    part2();
}