#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;

    KthLargest(int k, vector<int>& nums) {
        K = k;
        for (int &x : nums) {
            pq.push(x);
            if(pq.size() > k)
                pq.pop();
        }
    }

    int add(int val) {
        pq.push(val);
        if(pq.size() > K)
            pq.pop();
        return pq.top();
    }
    
};

int main() {
    vector<int> nums = {4, 5, 8, 2};
    KthLargest* kthlargest = new KthLargest(3, nums);
    cout << kthlargest->add(3) << endl;
    cout << kthlargest->add(5) << endl;
    cout << kthlargest->add(10) << endl;
    cout << kthlargest->add(9) << endl;
    cout << kthlargest->add(4) << endl;
}