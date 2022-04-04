#include <iostream>
#include <string>
#include <queue>

using namespace std;

void solve() {
	string input;
	cin >> input;

	queue<char> q;
	int depth = 0;

	for (int i = 0; i < input.size(); i++) {
		char cCurrent = input.at(i);
		int iCurrent = cCurrent - '0';

		if (depth == iCurrent) {
			q.push(cCurrent);
			continue;
		}

		if (depth < iCurrent) {
			while (depth < iCurrent) {
				q.push('(');
				depth++;
			}
		} else if (depth > iCurrent) {
			while (depth > iCurrent) {
				q.push(')');
				depth--;
			}
		}
		
		q.push(cCurrent);
	}

	while (depth > 0) {
		q.push(')');
		depth--;
	}

	while (!q.empty()) {
		char c = q.front();
		q.pop();
		cout << c;
	}

	cout << "\n";
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int testCount;
	cin >> testCount;

	for (int i = 0; i < testCount; i++) {
		cout << "Case #" << (i + 1) << ": ";
		solve();
	}

	return 0;
}