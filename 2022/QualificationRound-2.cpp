#include <iostream>
#include <algorithm>

using namespace std;

#define MAXVALUE 1000000

bool solve1(int c, int m, int y, int k) {
    int total = c + m + y + k;
    
    int overflow = total - MAXVALUE;
    if (overflow < 0) {
        return false;
    }

    if (overflow == 0) {
        cout << c << " " << m << " " << y << " " << k << "\n";
        return true;
    }

    int sub = 0;

    // C
    sub = min(c, overflow);
    c -= sub;
    overflow -= sub;

    if (overflow == 0) {
        cout << c << " " << m << " " << y << " " << k << "\n";
        return true;
    }

    // M
    sub = min(m, overflow);
    m -= sub;
    overflow -= sub;

    if (overflow == 0) {
        cout << c << " " << m << " " << y << " " << k << "\n";
        return true;
    }

    // Y
    sub = min(y, overflow);
    y -= sub;
    overflow -= sub;

    if (overflow == 0) {
        cout << c << " " << m << " " << y << " " << k << "\n";
        return true;
    }

    // K
    sub = min(k, overflow);
    k -= sub;
    overflow -= sub;

    if (overflow == 0) {
        cout << c << " " << m << " " << y << " " << k << "\n";
        return true;
    }

    return false;
}

void solve(int *ink)
{
    int retC = -1, retM = -1, retY = -1, retK = -1;

    int* p1 = ink;
    int* p2 = ink + 4;
    int* p3 = ink + 8;

    int minC = min(min(p1[0], p2[0]), p3[0]);
    int minM = min(min(p1[1], p2[1]), p3[1]);
    int minY = min(min(p1[2], p2[2]), p3[2]);
    int minK = min(min(p1[3], p2[3]), p3[3]);

    if (solve1(minC, minM, minY, minK)) {
        return;
    }

    cout << "IMPOSSIBLE\n";
}

int main(void)
{
    int count;
    int input[12];

    cin >> count;
    for (int i = 0; i < count; i++) {
        for (int jj = 0; jj < 12; jj++) {
            cin >> input[jj];
        }

        cout << "Case #" << (i + 1) << ": ";
        solve(input);
    }

    return 0;
}