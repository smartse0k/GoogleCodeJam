#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
#include <cstdint>

using namespace std;

class Module {
public:
    int index;
    int64_t number;
    int64_t total;
    Module* parent;
    vector<Module*> child;
    bool mark;

    Module(int index, int64_t n) {
        this->index = index;
        number = n;
        total = n;
        parent = nullptr;
        mark = false;
    }

    void pushChild(Module* m) {
        child.push_back(m);
        m->parent = this;
    }
};

struct compare {
    bool operator()(Module* l, Module* r) {
        return l->number > r->number;
    }
};

void solve() {
    int N;
    cin >> N;

    vector<Module*> root;
    vector<Module*> modules;

    int input;
    for (int i = 0; i < N; i++) {
        cin >> input;
        Module* m = new Module(i, input);
        modules.push_back(m);
    }

    for (int i = 0; i < N; i++) {
        cin >> input;

        if (input > 0) {
            modules[input - 1]->pushChild(modules[i]);
        }
        else {
            root.push_back(modules[i]);
        }
    }

    int rootCount = root.size();

    queue<Module*> q;
    for (int i = 0; i < rootCount; i++) {
        priority_queue<Module*, vector<Module*>, compare> pq;
        
        pq.push(root[i]);
        while (!pq.empty()) {
            Module* m = pq.top();
            pq.pop();

            if (m->child.size() == 0) {
                q.push(m);
                continue;
            }

            for (Module* child : m->child) {
                pq.push(child);
            }
        }
    }

    int64_t result = 0;
    
    while (!q.empty()) {
        int64_t resultSub = 0;

        Module* current = q.front();
        q.pop();

        do {
            if (current->mark) {
                break;
            }
            current->mark = true;
            resultSub = max(resultSub, current->number);
            current = current->parent;
        } while (current != nullptr);

        result += resultSub;
    }

    cout << result << "\n";
}

int main(void)
{
    int count;

    cin >> count;
    for (int i = 0; i < count; i++) {
        cout << "Case #" << (i + 1) << ": ";
        solve();
    }

    return 0;
}