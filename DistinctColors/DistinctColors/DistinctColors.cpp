#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

int N;
int timer = 0;
vector <int> adj[200000];
set<int> colors[200000];
int ans[200000];
int color[200000];

void dfs(int node= 0, int parent = -1) {
    for (int i : adj[node]) {
        if (i != parent) {
            dfs(i, node);

            if (colors[i].size() > colors[node].size()) {
                swap(colors[i], colors[node]);
            }
            colors[node].insert(colors[i].begin(), colors[i].end());
        }
    }
    colors[node].insert(color[node]);
    ans[node] = colors[node].size();
}

int main()
{
    //string problemName = "";
    //freopen("test_input.txt", "r", stdin);
    //ifstream fin(problemName + ".in");
    //ofstream fout(problemName + ".out");
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tmp, tmp1;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> color[i];
    }

    for (int i = 0; i < N - 1; i++) {
        cin >> tmp >> tmp1;
        adj[tmp1 - 1].push_back(tmp - 1);
        adj[tmp - 1].push_back(tmp1 - 1);
    }

    dfs();
    
    for (int i = 0; i < N; i++) {
        printf("%d ", ans[i]);
    }
}