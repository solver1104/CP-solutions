//#pragma warning( disable : 4996 )
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e5 + 5;
int N, M, tmp1, tmp2;
vector<long long int> adj[MAX], prefixes[MAX], suffixes[MAX];
long long int root[MAX], rootparent[MAX], notroot[MAX], notrootnext[MAX];

void dfs(int node = 0, int parent = -1) {
    prefixes[node].push_back(1);
    suffixes[node].push_back(1);
    int cnt = 0;
    for (int i : adj[node]) {
        if (i != parent) {
            dfs(i, node);
            root[node] *= (root[i] + 1);
            root[node] %= M;
            prefixes[node].push_back((prefixes[node][cnt] * (root[i] + 1))%M);
            cnt++;
        }
    }
    cnt = 0;
    reverse(adj[node].begin(), adj[node].end());
    for (int i : adj[node]) {
        if (i != parent) {
            suffixes[node].push_back((suffixes[node][cnt] * (root[i] + 1))%M);
            cnt++;
        }
    }
    cnt = 0;

    for (int i : adj[node]) {
        if (i != parent) {
            if (node == 0) {
                rootparent[i] = (prefixes[node][adj[node].size() - cnt - 1] * suffixes[node][cnt]) % M;
            }
            else {
                rootparent[i] = (prefixes[node][adj[node].size() - cnt - 2] * suffixes[node][cnt]) % M;
            }
            cnt++;
        }
    }
}

void dfs1(int node = 0, int parent = -1) {
    for (int i : adj[node]) {
        if (i != parent) {
            notrootnext[i] = (notrootnext[node] + 1) * rootparent[i];
            notrootnext[i] %= M;
            notroot[i] = (root[i] * notrootnext[i]) % M;
            dfs1(i, node);
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

    cin >> N >> M;
    for (int i = 0; i < N - 1; i++) {
        cin >> tmp1 >> tmp2;
        tmp1--;
        tmp2--;
        adj[tmp1].push_back(tmp2);
        adj[tmp2].push_back(tmp1);
    }

    fill(root, root + MAX, 1);
    fill(rootparent, rootparent + MAX, 1);
    dfs();
    dfs1();

    for (int i = 0; i < N; i++) {
        cout << (root[i] + notroot[i]) % M << "\n";
    }
}