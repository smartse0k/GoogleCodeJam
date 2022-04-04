#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

void solve() {
    int N;
    cin >> N;

    priority_queue<int, vector<int>, std::greater<int>> q;

    int input;
    for (int i = 0; i < N; i++) {
        cin >> input;
        q.push(input);
    }

    int s = 0;

    while (!q.empty()) {
        int current = q.top();
        q.pop();

        if (current > s) {
            s++;
        }
    }

    cout << s << "\n";
}

int main(void)
{
    int count;

    cin >> count;
    for (int i = 0; i < count; i++) {
        cout << "Case #" << (i + 1) << ": ";
        solve();
    }

    return 0;
}