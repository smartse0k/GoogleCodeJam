#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>

#include <cmath>

using namespace std;

int location[100000] = { 0, };
vector<pair<int, int*>> foundList;

void save(int depth) {
	int size = depth + 1;
	int *ret = new int[size];

	for (int i = 0; i <= depth; i++) {
		ret[i] = location[i];
	}

	foundList.push_back(make_pair(size, ret));
}

void dfs(int dir, int x, int y, int depth, int tx, int ty) {
	int jump = pow(2, depth);
	int nextX = x;
	int nextY = y;

	switch (dir) {
	case 0: // S
		nextY -= jump;
		break;
	case 1: // N
		nextY += jump;
		break;
	case 2: // W
		nextX -= jump;
		break;
	case 3: // E
		nextX += jump;
		break;
	}

	if (nextX == tx && nextY == ty) {
		save(depth);
		return;
	}

	if (abs(nextX) > abs(tx * tx)) {
		return;
	}

	if (abs(nextY) > abs(ty * ty)) {
		return;
	}

	for (int i = 0; i < 4; i++) {
		location[depth + 1] = i;
		dfs(i, nextX, nextY, depth + 1, tx, ty);
	}
}

void solve() {
	int X, Y;
	cin >> X >> Y;

	foundList.clear();

	int curX = 0, curY = 0;
	for (int i = 0; i < 4; i++) {
		location[0] = i;
		dfs(i, curX, curY, 0, X, Y);
	}

	if (foundList.size() == 0) {
		cout << "IMPOSSIBLE\n";
		return;
	}

	int min = (int)(0x80000000 - 1);
	int pos = -1;
	for (int i = 0; i < foundList.size(); i++) {
		if (foundList[i].first < min) {
			min = foundList[i].first;
			pos = i;
		}
	}

	int *ret = foundList[pos].second;
	for (int i = 0; i < min; i++) {
		switch (ret[i]) {
		case 0:
			cout << "S";
			break;
		case 1:
			cout << "N";
			break;
		case 2:
			cout << "W";
			break;
		case 3:
			cout << "E";
			break;
		}
	}
	cout << "\n";
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
