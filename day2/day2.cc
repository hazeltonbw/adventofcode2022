#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
using namespace std;


int main() {
    ifstream ins("input.txt");
    string s;
    unordered_map<char, int> OPP = { {'A', 1}, {'B', 2}, {'C', 3} }; 
    enum RPS { Rock = 65, Paper, Scissors };
    const int DRAW = 3;
    const int WIN = 6;
    char opp, mine;
    int score = 0;
    while (ins) {
        getline(ins, s);
        if (!ins) break;
        stringstream ss(s);
        ss >> opp >> mine;
        mine -= 'X' - 'A'; // change mine to same ascii value for easy comparison
        if (opp == mine){
            score += DRAW;
        }
        else if (mine == RPS::Rock) {
            if (opp == RPS::Scissors) {
                score += WIN;
            }
        }
        else if (mine == RPS::Paper) {
            if (opp == RPS::Rock) {
                score += WIN;
            }
        }
        else { // we're scissors
            if (opp == RPS::Paper) {
                score += WIN;
            }
        }
        score += OPP.at(mine);
    }
    cout << score << endl;
}