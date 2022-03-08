#include <iostream>
#include <vector>


using namespace std;

int arrayPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int maximized_sum = 0;
    for (int i = 0; i < nums.size(); i+=2) {
        cout << nums[i] << " : " << nums[i+1] << endl;
        nums[i] < nums[i+1] ?  maximized_sum+=nums[i] : maximized_sum+=nums[i+1];
    }

    return maximized_sum;
}

int main() {
    vector<int> nums = {6, 2, 6, 5, 1, 2};

    cout << arrayPairSum(nums) << endl;
}