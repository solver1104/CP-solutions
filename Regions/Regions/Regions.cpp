//#pragma warning( disable : 4996 )
#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5 + 5;
const int MAX2 = 25000;
int N, R, Q, tmp, tmp1;
int startingtimes[MAX], endingtimes[MAX], home[MAX];
vector<int> adj[MAX];
map<int, int> homeregions[MAX];
map<int, int> monitored[MAX2];

void dfs(int node = 0, int parent = -1) {
    for (int i : adj[node]) {
        if (i != parent) {
            dfs(i, node);
            if (homeregions[i].size() > homeregions[node].size()) {
                swap(homeregions[i], homeregions[node]);
            }

            for (auto x : homeregions[i]) {
                homeregions[node][x.first] += x.second;
            }
            homeregions[i].clear();
        }
    }
    for (auto i : homeregions[node]) {
        monitored[home[node]][i.first] += i.second;
    }
}

int main()
{
    /*
    string problemName = "";
    ifstream fin(problemName + ".in");
    ofstream fout(problemName + ".out");
    */

    cin >> N >> R >> Q;
    cin >> tmp;
    homeregions[0][tmp] ++;
    home[0] = tmp;

    for (int i = 1; i < N; i++) {
        cin >> tmp >> tmp1;
        adj[i].push_back(tmp - 1);
        adj[tmp - 1].push_back(i);
        homeregions[i][tmp1] ++;
        home[i] = tmp1;
    }
    dfs();

    for (int i = 0; i < Q; i++) {
        cin >> tmp >> tmp1;
        cout << monitored[tmp][tmp1] << "\n";
    }
}