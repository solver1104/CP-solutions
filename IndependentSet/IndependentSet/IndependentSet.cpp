//#pragma warning( disable : 4996 )
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e5 + 5;
const int MOD = 1e9 + 7;
int N, tmp1, tmp2;
long long int black[MAX], white[MAX];
vector<int> adj[MAX];

void dfs(int node = 0, int parent = -1) {
    for (int i : adj[node]) {
        if (i != parent) {
            dfs(i, node);
            black[node] *= white[i];
            black[node] %= MOD;
            white[node] *= (white[i] + black[i]);
            white[node] %= MOD;
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

    cin >> N;
    fill_n(white, MAX, 1);
    fill_n(black, MAX, 1);
    for (int i = 0; i < N - 1; i++) {
        cin >> tmp1 >> tmp2;
        adj[tmp1 - 1].push_back(tmp2 - 1);
        adj[tmp2 - 1].push_back(tmp1 - 1);
    }
    dfs();

    cout << (black[0] + white[0]) % MOD;
}