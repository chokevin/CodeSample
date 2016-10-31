#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Cleared

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int tests;
    int games;
    vector<int> game;
    int piles;
    int sum;

    cin >> tests;
    for(int i = 0; i < tests; i++){
        cin >> games;
        for(int i = 0; i < games; i++){
            cin >> piles;
            for(int i = 0; i < piles; i++){
                int input;
                cin >> input;
                game.push_back(input);
            }
        }
        int turn = 0;
        for(int i = 0; i < game.size(); i++){
            if(game[i] % 2 == 1 & game[i] > 1)  turn += game[i]/2;
        }
        turn % 2 == 1 ? cout << "Alice" << endl : cout << "Bob" << endl;
        game.clear();
    }
    return 0;
}
