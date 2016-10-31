#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

// Broke on large test cases

int main() {
    int C, H, O;
    int water = 0, cd = 0, glucose = 0;
    bool flag = false;
        cin >> C >> H >> O;
        cout << "Carbon:" << C << endl;
        cout << "Hydrogen:" << H << endl;
        cout << "Oxygen:" << O << endl;
        glucose = H/12;
        C -= glucose*6;
        H -= glucose*12;
        O -= glucose*6;
        cout << "Carbon:" << C << endl;
        cout << "Hydrogen:" << H << endl;
        cout << "Oxygen:" << O << endl;
        cout << "Glucose:" << glucose << endl;
        while(glucose >= 0){
            if(C == 0 && H == 0 && O == 0){
                cout << water << " " << cd << " "<< glucose;
                flag = true;
                break;
            }
            cout << "Carbon:" << C << endl;
            cout << "Hydrogen:" << H << endl;
            cout << "Oxygen:" << O << endl;
            cd = C;
            C -= cd;
            O -= cd*2;
            if(C == 0 && H == 0 && O == 0 && O >= 0){
                cout << water << " " << cd << " "<< glucose;
                flag = true;
                break;
            }
            water = O;
            O -= water;
            H -= H*2;
            if(C == 0 && H == 0 && O == 0 && H >= 0){
                cout << water << " " << cd << " "<< glucose;
                flag = true;
                break;
            }
            glucose--;
            if(glucose > 0){
              C += 6;
              H += 12;
              O += 6;
            }
        }
        if(!flag) { cout << "Error"; }
        cout << endl;
        flag = false;
    return 0;
}
