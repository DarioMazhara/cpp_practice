#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;


bool formsSquare(vector<pair<int, int>> coords) {

    if (coords.size() != 4)
        return false;

    static vector<int> axis_vals = {};
    unordered_map<int, int> axis_freq;
    typedef pair<int, int> point;
    vector<pair<int, int>> duplicate_test;
    for (pair<int, int> i : coords) {
        if(count(duplicate_test.begin(), duplicate_test.end(), i))
            return false;
        duplicate_test.push_back(i);
    }

    for (int i = 0; i < coords.size(); i++) {
        if (!axis_freq[coords[i].first]) {
            int x = coords[i].first;
            axis_vals.push_back(x);
            axis_freq[coords[i].first]++;
            axis_freq[coords[i].second]++;

        }
        if (!axis_freq[coords[i].second]) {
            int y = coords[i].second;
            axis_vals.push_back(y);

            axis_freq[coords[i].second]++;
        }
        axis_freq[coords[i].first]++;
        axis_freq[coords[i].second]++;
    }

    cout << axis_freq[axis_vals[0]] + axis_freq[axis_vals[1]] << endl;
    cout << axis_vals.size() << endl;
    if (axis_vals.size() == 2 && (axis_freq[axis_vals[0]] + axis_freq[axis_vals[1]] == 8))
        return true;
  
    
    return false;
}




int main() {
    pair<int, int> c1 = {10,20};
    pair<int, int> c2 = {20,10};
    pair<int, int> c3 = {10,10};
    pair<int, int> c4 = {20,20};
    vector<pair<int, int>> coords = {c1, c2, c3, c4};

    cout << (formsSquare(coords) ? "true" : "false") << endl;
}