
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
using namespace std;

int main() {
    ifstream ins("input.txt");
    unordered_map<char, int> OPP = { {'A', 1}, {'B', 2}, {'C', 3} };
    enum RPS { Rock = 65, Paper, Scissors };
    const int DRAW = 3;
    const int WIN = 6;
    char opp, mine;
    string s;
    int score = 0;
    while (ins) {
        getline(ins, s);
        if (!ins) break;
        stringstream ss(s);
        ss >> opp >> mine;

        if (mine == 'X') {
            // need to lose
            if (opp == RPS::Rock) {
                // scissors loses to rock,
                // no points for losing
                score += OPP.at(RPS::Scissors); 
            }
            else if (opp == RPS::Paper) {
                // rock loses to paper
                score += OPP.at(RPS::Rock);
            }
            else {
                // paper loses to scissors
                score += OPP.at(RPS::Paper);
            }
        }
        else if (mine == 'Y') {
            // need to draw
            score += DRAW + OPP.at(opp);
        }
        else {
            // need to win
            if (opp == RPS::Rock){
                score += OPP.at(RPS::Paper);
            }
            else if (opp == RPS::Paper) {
                score += OPP.at(RPS::Scissors);
            }
            else {
                score += OPP.at(RPS::Rock);
            }
            score += WIN;
        }

        /*
        * Scary Ternary Operator example for fun... eek

        mine == 'X' ? opp == RPS::Rock ? score += OPP.at(RPS::Scissors) : opp == RPS::Paper ? score += OPP.at(RPS::Rock) : score += OPP.at(RPS::Paper)
        : mine == 'Y' ? score += DRAW + OPP.at(opp)
        : opp == RPS::Rock ? score += OPP.at(RPS::Paper) + WIN: opp == RPS::Paper ? score += OPP.at(RPS::Scissors) + WIN : score += OPP.at(RPS::Rock) + WIN;

        */
    }
    cout << score << endl;
}
