#include <iostream>
#include <math.h>
using namespace std;

//Time O(n), Space O(1)
int climbStairs(int n) {
    //n = how many stairs to climb
    //return all variations of 1 or 2 steps to get to n
    if(n==1)
        return 1;
    if(n==2)
        return 2;
    int pre = 1;
    int curr = 1;
    int temp = 0;
    for (int i = 1; i < n; i++) {
        temp = curr;
        curr += pre;
        pre = temp;
    }
    return curr;
}

//Time O(logn), Space O(1)
//using matrix multiplication
int climbStairs_2(int n) {
    int q[][] = {{1, 1}, {1, 0}};
    int res[][] = pow(q, n);
    return res[0][0];
} 
int[][] pow(int a[][], int n) {
    int ret[][] = {{1,0},{0,1}};
    while(n>0) {
        if ((n & 1) == 1)
            ret = multiply(ret, a);
        n >>= 1;
        a = multiply(a, a);
    }
    return ret;
}

int[][] multiply(int a[][], int b[][]) {
    int c[2][2];
    for (int i = 0; i<2; i++) {
        for (int j = 0; j < 2; j++) {
            c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
        }
    }
    return c;
}
//Time O(1) Space O(1)
int climbStairs_3(int n) {
    double sqrt5 = sqrt(5);
    double fibn = ((1+sqrt5)/2)^(n+1) - ((1-sqrt5)/2)^(n+1);
    return (int)fibn/sqrt5;
}
int main() {
    cout << climbStairs(9) << endl;
}