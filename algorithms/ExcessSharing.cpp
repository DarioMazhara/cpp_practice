#include <stdio.h>
#include <iostream>

using namespace std;

double champagneTower(int poured, int query_row, int query_glass) {
    if (poured <= 0)
        return 0;
    query_row-=1;
    double cups_fill_prev = 0;
    double cups_fill = 0;
    double streams_in;
    double excess;
    int query_glass_1_2;
    double how_full;

    cout << "Poured: " << poured << "\nRow: " << query_row << "\nGlass: " <<
    query_glass << endl;

    for (int i = 0; i < query_row; i++) {
        cups_fill_prev += (query_row-i);
        cups_fill += (query_row+1)-i;
    }
    cout << "Cups to fill prev: " << cups_fill_prev << endl;
    cout << "Cups fill: " << cups_fill << endl;

    streams_in = 2 * (query_row-1) + 2;
    cout << "Streams pouring into " << query_row << ": " << streams_in << endl;
    excess = cups_fill-cups_fill_prev
    cout << "Excess cups: " << excess << endl;
    
    if (query_glass == 1 || query_glass == query_row)
        query_glass_1_2 = 1;
    else
        query_glass_1_2 = 2;
    
    how_full = (query_glass_1_2/streams_in)*excess;
    if (how_full > 1.0)
        return 1.0;
    
    return how_full;
}
int main() {

    cout << champagneTower(25, 6, 1) << endl;
    return 0;
}