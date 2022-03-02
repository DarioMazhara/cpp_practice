#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

bool isSubsequence(string s, string t) {
    //s = possible subsequence

    for (int i = 0; i < s.size(); i++) {
        if(t[i]!=s[i]) {
            t.erase(i, i);
            continue;
        }
    }
    return t == s;
}

int main() {
    string s = "abc";
    string t = "ahbgdc";

    cout << isSubsequence(s, t) << endl;
}