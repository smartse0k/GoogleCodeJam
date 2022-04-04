#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

void findNumberList(vector< vector<int>* > &v, int *arr, int N, int maxDepth, int depth) {
	if (depth == maxDepth) {
		vector<int> *v2 = new vector<int>();
		for (int i = 0; i < N; i++) {
			v2->push_back(arr[i]);
		}
		v.push_back(v2);
		return;
	}

	for (int i = 0; i < N; i++) {
		arr[depth] = i + 1;
		findNumberList(v, arr, N, maxDepth, depth + 1);
	}
}

void makeLatinTrace(vector< vector<int>* > &resultV, int N, int K) {
	int *arr = new int[N];
	vector< vector<int>* > v;

	findNumberList(v, arr, N, N, 0);

	for (int i = 0; i < v.size(); i++) {
		vector<int> *currentV = v[i];
		int sum = 0;

		for (int jj = 0; jj < N; jj++) {
			int current = currentV->at(jj);
			sum += current;
		}

		if (sum == K) {
			resultV.push_back(currentV);
		}
	}
}

void testPrintMap(vector<int> *map) {
	return;

	cout << "\n\n";

	for (int i = 0; i < map->size(); i++) {
		for (int jj = 0; jj < map->size(); jj++) {
			cout << map[i][jj] << " ";
		}
		cout << "\n";
	}

	cout << "\n\n";
}

void dfs(int N, vector<int> *map, vector<bool> *checkX, vector<bool>* checkY, int currentPos, bool &isSolve) {
	int x = currentPos % N;
	int y = currentPos / N;

	if (currentPos + 1 == N * N) {
		isSolve = true;

		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				if (map[y][x] == 0) {
					isSolve = false;
				}
			}
		}

		testPrintMap(map);
		return;
	}

	if (map[y][x] == 0) {
		for (int i = 1; i <= N; i++) {
			if (checkY[y][i] && checkX[x][i]) {
				checkY[y][i] = false;
				checkX[x][i] = false;

				testPrintMap(map);

				map[y][x] = i;
				if (map[0][0] == 2 && map[0][1] == 1 && map[0][2] == 3 && 
					map[1][0] == 3 && map[1][1] == 2 && map[1][2] == 1 ) {
					cout << "";
				}
				dfs(N, map, checkX, checkY, currentPos + 1, isSolve);
				
				if (isSolve) {
					return;
				}

				map[y][x] = 0;
				checkY[y][i] = true;
				checkX[x][i] = true;
			}
		}
	} else {
		testPrintMap(map);
		dfs(N, map, checkX, checkY, currentPos + 1, isSolve);
	}
}

bool solve2(int N, vector<int> *latinTrace, vector<int> *map) {
	vector<bool> *checkX = new vector<bool>[N + 1];
	vector<bool> *checkY = new vector<bool>[N + 1];

	for (int i = 0; i < N; i++) {
		int num = latinTrace->at(i);

		map[i].resize(N, 0);
		map[i][i] = num;

		checkX[i].resize(N + 1, true);
		checkX[i][num] = false;

		checkY[i].resize(N + 1, true);
		checkY[i][num] = false;
	}

	bool isSolve = false;
	dfs(N, map, checkX, checkY, 0, isSolve);

	return isSolve;
}

void solve() {
	int N, K;
	cin >> N >> K;

	vector< vector<int>* > latinTraceList;
	makeLatinTrace(latinTraceList, N, K);

	for (int i = 0; i < latinTraceList.size(); i++) {
		vector<int> *map = new vector<int>[N];
		bool ret = solve2(N, latinTraceList[i], map);
		if (ret) {
			cout << "POSSIBLE\n";

			for (int i = 0; i < N; i++) {
				for (int jj = 0; jj < N; jj++) {
					cout << map[i][jj];

					if (jj < N - 1) {
						cout << " ";
					}
				}
				cout << "\n";
			}

			return;
		}
	}

	cout << "IMPOSSIBLE\n";
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
