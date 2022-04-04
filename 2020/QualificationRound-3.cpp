#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

//                  NAME       st   et
#define WORKER pair<char, pair<int, int>>
//               index     st   et
#define JOB pair<int, pair<int, int>>

#define NAME first

#define IX first
#define ST second.first
#define ET second.second

struct compareFunc {
	bool operator() (JOB j1, JOB j2) {
		return j1.second.first > j2.second.first;
	}
};

void solve() {
	int jobCount;
	cin >> jobCount;

	vector<JOB> jobList;
	priority_queue<JOB, vector<JOB>, compareFunc> q;

	WORKER c, j;
	c.NAME = 'C';
	c.ST = -1;
	c.ET = -1;

	j.NAME = 'J';
	j.ST = -1;
	j.ET = -1;

	for (int i = 0; i < jobCount; i++) {
		int startTime, endTime;
		cin >> startTime >> endTime;

		jobList.push_back({ i, { startTime, endTime } });
		q.push({ i, { startTime, endTime } });
	}

	vector<char> schedule;
	schedule.resize(jobCount, 0);

	while (!q.empty()) {
		JOB job = q.top();
		q.pop();

		if (c.ET <= job.ST) {
			schedule[job.IX] = c.NAME;

			c.ST = job.ST;
			c.ET = job.ET;

			continue;
		}

		if (j.ET <= job.ST) {
			schedule[job.IX] = j.NAME;

			j.ST = job.ST;
			j.ET = job.ET;

			continue;
		}

		cout << "IMPOSSIBLE\n";
		return;
	}

	for (int i = 0; i < schedule.size(); i++) {
		cout << schedule[i];
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