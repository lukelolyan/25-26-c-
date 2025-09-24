#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> reconstruct(vector<int>& meas) {

    sort(meas.begin(), meas.end());

    int n = meas.size();
    int k = (n + 1) / 2; 

    vector<int> lows(meas.begin(), meas.begin() + k);
    vector<int> highs(meas.begin() + k, meas.end());

 
    reverse(lows.begin(), lows.end());

    vector<int> result;
    int i = 0, j = 0;
    for (int pos = 0; pos < n; pos++) {
        if (pos % 2 == 0) {  
            result.push_back(lows[i++]);   
        } else {
            result.push_back(highs[j++]);  
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> measurements(n);

    for (int i = 0; i < n; i++) {
        cin >> measurements[i];
    }

    vector<int> result = reconstruct(measurements);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i + 1 < result.size()) cout << " ";
    }
    cout << "\n";

    return 0;
}
