#include <iostream>


using namespace std;

long long trappingWater(int arr[], int n) {
    //height of the lowest block at the beginning or end of the blocks is the limit of the water

    long long max_water_height;
    arr[0] <= arr[n-1] ? max_water_height = arr[0] : max_water_height = arr[n-1];

    int trapped = 0;
    for(int i = 1; i < (n-1); i++) {
        if (arr[i] <= max_water_height)
            trapped += (max_water_height-arr[i]);
    }
    return trapped;

}

int main() {
    int arr[6] = {3, 0, 0, 2, 0, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << trappingWater(arr, n) << endl;
}