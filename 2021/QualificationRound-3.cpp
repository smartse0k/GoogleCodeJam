#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int T, C;
int *list = new int[5000];
int *checklist;
int *stk = new int[5000];

int getCost(int *arr) {
	int cost = 0;
	stack<int> s;

	for(int i=0; i<T - 1; i++) {
		int minValue = 0x7fffffff,
			minIndex = -1;

		for(int jj=i; jj<T; jj++) {
			if(minValue > arr[jj]) {
				minValue = arr[jj];
				minIndex = jj;
			}
		}

		for(int jj=i; jj<=minIndex; jj++) {
			s.push( list[jj] );
		}
		for(int jj=i; jj<=minIndex; jj++) {
			arr[jj] = s.top();
			s.pop();
			cost++;
		}
	}

	return cost;
}

void solve() {
	cin >> T >> C;

	for(int i=0; i<T; i++)
		list[i] = i + 1;

	do {
		if(checklist) {
			delete checklist;
		}
		checklist = new int[T];

		for(int i=0; i<T; i++)
			checklist[i] = list[i];

		
		int cost = getCost(checklist);

		if(cost == C) {
			for(int i=0; i<T; i++) {
				cout << list[i] << " ";
			}
			return;
		}
	} while( next_permutation(list, list+T) );

	cout << "IMPOSSIBLE";
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