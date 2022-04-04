#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
#include <cstdint>
#include <thread>
#include <cstring>

using namespace std;

class Room {
public:
    int id;
    int routeCount;
    bool* route;
    vector<int> discover;

    Room(int id);
};

Room::Room(int id) {
    this->id = id;
    routeCount = -1;
    route = nullptr;
}

int N, K;
vector<Room*> rooms;
int id, routeCount;
int lastId = 0, lastRouteCount = 0;

void W() {
    cout << "W\n";
    cerr << "output >> W\n";
}

void thinkT() {
    int randMax = 100;
    int target = -1;
    int min = N;

    do {
        int next = rand() % N;

        Room* r = rooms[next];

        int discoverSize = r->discover.size();

        if (discoverSize < min) {
            min = discoverSize;
            target = next;
        }

        randMax--;
    } while (randMax > 0);

    cerr << "output >> " << "T " << (target + 1) << "\n";
    
    cout << "T " << (target + 1) << "\n";
    cout.flush();
}

void think() {
    //this_thread::sleep_for(chrono::milliseconds(1000));

    if (K % 2 == 0) {
        W();
    } else {
        thinkT();
    }
}

void solve() {
    cin >> N >> K;
    cerr << "input >> N=" << N << ", K=" << K << "\n";

    rooms.clear();
    for (int i = 0; i < N; i++) {
        Room* room = new Room(i);
        room->route = new bool(N);
        rooms.push_back(room);
    }

    while (K > 0) {
        K--;

        cin >> id >> routeCount;
        cerr << "input >> id=" << id << ", routeCount=" << routeCount << "\n";

        Room* room = rooms[id - 1];
        room->routeCount = routeCount;

        if (lastId > 0) {
            cerr << "TEST\n";
            cerr << room->route[lastId - 1];

            room->route[lastId - 1] = true;

            room = rooms[lastId - 1];
            room->route[id - 1] = true;
        }

        think();

        lastId = id;
        lastRouteCount = routeCount;
    }

    cerr << "test >> N=" << N << ", K=" << K << "\n";
}

int main(void)
{
    cin.tie(0);
    cin.sync_with_stdio(false);

    int count;

    cin >> count;
    for (int i = 0; i < count; i++) {
        solve();
    }

    return 0;
}