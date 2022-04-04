#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int N;
	cin >> N;

	int k = 0,
		r = 0,
		c = 0;

	vector<int>* isContainRow = new vector<int>[N + 1];
	vector<int>* isContainCol = new vector<int>[N + 1];

	for (int i = 0; i < N; i++) {
		isContainRow[i].resize(N + 1, false);
		isContainCol[i].resize(N + 1, false);
	}

	
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			int number;
			cin >> number;


			if (x == y) {
				k += number;
			}

			isContainRow[y][number]++;
			isContainCol[x][number]++;
		}
	}

	for (int i = 0; i < N; i++) {
		bool isR = false, isC = false;

		for (int num = 1; num <= N; num++) {
			if (isContainRow[i][num] > 1) {
				isR = true;
			}

			if (isContainCol[i][num] > 1) {
				isC = true;
			}
		}

		if (isR) {
			r++;
		}

		if (isC) {
			c++;
		}
	}

	cout << k << " " << r << " " << c << "\n";

	delete[] isContainRow;
	delete[] isContainCol;
}

int main(void) {
	cin.tie(0);
	cin.sync_with_stdio(false);
	ios::sync_with_stdio(false);

	int testCount;
	cin >> testCount;

	for (int i = 0; i < testCount; i++) {
		cout << "Case #" << (i + 1) << ": ";
		solve();
	}

	return 0;
}