#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X;
    cin >> X;
    vector<pair<string, string>> same_constraints(X);
    for (int i = 0; i < X; ++i) {
        cin >> same_constraints[i].first >> same_constraints[i].second;
    }

    int Y;
    cin >> Y;
    vector<pair<string, string>> diff_constraints(Y);
    for (int i = 0; i < Y; ++i) {
        cin >> diff_constraints[i].first >> diff_constraints[i].second;
    }

    int G;
    cin >> G;
    
    unordered_map<string, int> group_map;
    
    for (int i = 0; i < G; ++i) {
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
  
        group_map[s1] = i;
        group_map[s2] = i;
        group_map[s3] = i;
    }

    int violations = 0;

    for (const auto& pair : same_constraints) {
        if (group_map[pair.first] != group_map[pair.second]) {
            violations++;
        }
    }

    for (const auto& pair : diff_constraints) {
        if (group_map[pair.first] == group_map[pair.second]) {
            violations++;
        }
    }
    cout << violations << endl;

    return 0;
}
