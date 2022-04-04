#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>

#define card pair<int, int>

using namespace std;

void solve() {
	int R, S;
	cin >> R >> S;

	queue<int> ret;
	int left = R * (S - 1),
		right = R - 1,
		rightC = S - 2;

	ret.push(left);
	ret.push(right);

	while (true) {
		if (left > 1) {
			left--;
		}

		if (rightC == 0) {
			right--;
			rightC = S - 2;
		} else {
			rightC--;
		}

		if (right == 0) {
			break;
		}

		ret.push(left);
		ret.push(right);
	}

	cout << ret.size() / 2 << "\n";
	while (!ret.empty()) {
		for (int i = 0; i < 2; i++) {
			int o = ret.front();
			ret.pop();
			cout << o << " ";
		}
		
		cout << "\n";
	}
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int testCount;
	cin >> testCount;
	for (int i = 1; i <= testCount; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
}
