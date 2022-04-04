#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cstring>

using namespace std;

int X, Y;
char str[5000];
int strSize;
char last;

int calc(char *s, char startWith) {
	int cost = 0;
	char last = startWith;

	for(int i=1; i<strSize; i++) {
		if(last == s[i]) {
			continue;
		}

		char cur = s[i];

		switch(cur) {
		case 'C':
			//cout << "JC ";
			cost += Y;
			break;
		case 'J':
			//cout << "CJ ";
			cost += X;
			break;
		case '?':
			int add = 0;
			cur = last;
			break;
		}

		last = cur;
	}

	return cost;
}

void solve() {
	cin >> X >> Y >> str;
	strSize = strlen(str);

	int cost = 0;

	if(str[0] == '?') {
		int costC = calc(str, 'C');
		int costJ = calc(str, 'J');
		
		cost = min(costC, costJ);
	} else {
		cost = calc(str, str[0]);
	}

	cout << cost;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for(int i=1; i<=T; i++) {
		cout << "Case #" << i <<": ";
		solve();
		cout << "\n";
	}

	return 0;
}