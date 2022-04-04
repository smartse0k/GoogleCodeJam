#include <iostream>

using namespace std;

char map[101][101];

void ready() {
    char ascii[2][2] = {{'+', '-'}, {'|', '.'}};

    for (int r = 0; r < 100; r++) {
        int ar = r % 2;
        for (int c = 0; c < 100; c++) {
            int cr = c % 2;
            map[r][c] = ascii[ar][cr];
        }
    }

    for (int r = 0; r < 2; r++) {
        for (int c = 0; c < 2; c++) {
            map[r][c] = '.';
        }
    }
}

void solve(int R, int C)
{
    int tr = R * 2 + 1;
    int tc = C * 2 + 1;

    for (int r = 0; r < tr; r++) {
        for (int c = 0; c < tc; c++) {
            cout << map[r][c];
        }

        cout << "\n";
    }
}

int main(void)
{
    int count;
    int i1, i2, i3, i4, i5;

    ready();

    cin >> count;
    for (int i = 0; i < count; i++) {
        cin >> i1 >> i2;

        cout << "Case #" << (i + 1) << ":\n";
        solve(i1, i2);
    }

    return 0;
}