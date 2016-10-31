#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

// Walking Dog Cleared

int main(){
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int testcase;
    cin >> testcase;
    priority_queue<int, std::vector<int>, std::greater<int> > dogs;
    vector<int> doggies;
    priority_queue<int> differences;
    int m = 0;
    for(int i = 0; i < testcase; i++){
        int N;
        int K;
        cin >> N;
        cin >> K;
        for(int j = 0; j < N; j++){
            int dogweight = 0;
            cin >> dogweight;
            dogs.push(dogweight);
        }
        while(dogs.size()){
          doggies.push_back(dogs.top());
          dogs.pop();
        }
        for(int i = 1; i < doggies.size(); i++){
            //cout << "differences" << abs(doggies[i] - doggies[i-1]) << endl;
            differences.push(doggies[i] - doggies[i-1]);
          }
        for(int t = 0 ; t<K-1; t++){
          //cout << "top is currently:" << differences.top() << endl;
          differences.pop();
        }
        int sum = 0;
        while(differences.size()){
          //cout << "top is currently:" << differences.top() << endl;
          sum += differences.top();
          differences.pop();
        }
        cout << sum << endl;
        doggies.clear();
    }
}
