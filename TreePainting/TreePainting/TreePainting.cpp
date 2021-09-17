#pragma warning( disable : 4996 )
#include <bits/stdc++.h>

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;

const int MAX = 2e5 + 5;
int n, tmp1, tmp2;
vector<int> adj[MAX];
int subtreesums[MAX];
long long int maxsum = 0;
long long int cursum = 0;

void calcsubtreesums(int node = 0, int parent = -1) {
    for (int i : adj[node]) {
        if (i != parent) {
            calcsubtreesums(i, node);
            subtreesums[node] += subtreesums[i];
        }
    }
}

void dfs(int node = 0, int parent = -1, long long int sum = cursum) {
    for (int i : adj[node]) {
        if (i != parent) {
            maxsum = max(maxsum, sum + (n - 2 * subtreesums[i]));
            dfs(i, node, sum + (n - 2 * subtreesums[i]));
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
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> tmp1 >> tmp2;
        tmp1--;
        tmp2--;
        adj[tmp1].push_back(tmp2);
        adj[tmp2].push_back(tmp1);
    }

    fill(subtreesums, subtreesums + MAX, 1);
    calcsubtreesums();

    for (int i = 0; i < n; i++) {
        cursum += subtreesums[i];
    }
    maxsum = cursum;
    dfs();
    cout << maxsum;
}