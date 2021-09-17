//#pragma warning( disable : 4996 )
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

const int MAX = 5e4 + 5;
const int MAXK = 505;
int N, K, tmp1, tmp2;
long long int ans = 0;
vector<int> adj[MAX];
int distances[MAX][MAXK];

void dfs(int node = 0, int parent = -1) {
    for (int i : adj[node]) {
        if (i != parent) {
            dfs(i, node);
            for (int x = 0; x < K; x ++) {
                ans += (distances[i][x] * distances[node][K - 1 - x]);
            }

            for (int x = 0; x < K; x ++) {
                distances[node][x + 1] += distances[i][x];
            }
        }
    }
}

int main()
{
    /*
    string problemName = "";
    ifstream fin(problemName + ".in");
    ofstream fout(problemName + ".out");
    */

    ios::sync_with_stdio(0);

    cin >> N >> K;
    for (int i = 0; i < N - 1; i++) {
        cin >> tmp1 >> tmp2;
        tmp1--;
        tmp2--;
        adj[tmp1].push_back(tmp2);
        adj[tmp2].push_back(tmp1);
        distances[i][0] ++;
    }
    distances[N - 1][0] ++;

    dfs();
    cout << ans;
}