// Pesta

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> child;
int leafCount = 0;

void dfs(int u) {
    if (child[u].empty()) {
        leafCount++;
        return;
    }
    for (int v : child[u]) {
        dfs(v);
    }
}

int main() {
    int n;
    cin >> n;

    child.assign(n + 1, vector<int>());
    vector<int> p(n + 1);
    vector<int> roots;

    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        if (p[i] == -1) {
            roots.push_back(i);
        } else {
            child[p[i]].push_back(i);
        }
    }

    for (int r : roots) {
        dfs(r);
    }

    cout << leafCount << endl;
    return 0;
}