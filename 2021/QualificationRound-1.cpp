#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void solve() {
	int N;
	cin >> N;

	int cost = 0;

	vector<int> list(N);
	stack<int> s;
	
	for(int i=0; i<N; i++) {
		cin >> list[i];
	}

	for(int i=0; i<N - 1; i++) {
		int minValue = 0x7fffffff,
			minIndex = -1;

		for(int jj=i; jj<N; jj++) {
			if(minValue > list[jj]) {
				minValue = list[jj];
				minIndex = jj;
			}
		} // for 2

		
		for(int jj=i; jj<=minIndex; jj++) {
			s.push( list[jj] );
		}
		for(int jj=i; jj<=minIndex; jj++) {
			list[jj] = s.top();
			s.pop();
			cost++;
		}
	} // for 1

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