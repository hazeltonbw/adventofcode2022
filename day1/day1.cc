#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

int main() {
        ifstream ins("puzzleinput.txt");
        string s;
        priority_queue<int> elfLeaderboard;
        int sumOfCaloriesForElf = 0;
        while (ins) {
                int calories = 0;
                getline(ins, s);
                if (!ins) break;
                if (s == "") {
                        elfLeaderboard.push(sumOfCaloriesForElf);
                        sumOfCaloriesForElf = 0;
                        continue;
                }
                try {
                        calories = stoi(s);
                } catch(...) {
                        cout << "Something went wrong...\n";
                        exit(1);
                }
                sumOfCaloriesForElf += calories;
        }
        cout << "Elf carrying the most calories has " <<  elfLeaderboard.top() << " calories." << endl;

        int top3 = 0;
        for (int i = 0; i < 3; i++) {
                top3 += elfLeaderboard.top();
                elfLeaderboard.pop();
        }
        cout << "The top 3 elves have " << top3 << " calories combined. " << endl;
}
