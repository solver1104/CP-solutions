//#pragma warning( disable : 4996 )
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int N, Q, tmp, tmp1;
const int MAX = 2e5 + 5;
int startingtimes[MAX], endingtimes[MAX], nodevals[MAX];
vector<int> adj[MAX], sortednodes;
long long int fenwick[MAX];
int timer = 0;
unordered_map<int, int> positions;

void upd(int i, int v) {
    for (; i <= N; i += i & (-i)) fenwick[i] += v;
}

long long int qry(int i) {
    long long int sum = 0;
    for (; i > 0; i -= i & (-i)) sum += fenwick[i];
    return sum;
}

void dfs(int node = 0, int parent = -1) {
    sortednodes.push_back(node);
    positions[node] = timer;
    startingtimes[node] = timer++;
    for (int i : adj[node]) {
        if (i != parent) {
            dfs(i, node);
        }
    }
    endingtimes[node] = timer - 1;
}

int main()
{
    /*
    string problemName = "";
    ifstream fin(problemName + ".in");
    ofstream fout(problemName + ".out");
    */

    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        cin >> nodevals[i];
    }

    for (int i = 0; i < N - 1; i++) {
        cin >> tmp >> tmp1;
        adj[tmp - 1].push_back(tmp1 - 1);
        adj[tmp1 - 1].push_back(tmp - 1);
    }

    dfs();

    upd(1, nodevals[0]);
    for (int i = 1; i < N; i++) {
        upd(i + 1, nodevals[sortednodes[i]]);
        upd(i + 2 + endingtimes[sortednodes[i]] - startingtimes[sortednodes[i]], -nodevals[sortednodes[i]]);
    }

    for (int i = 0; i < Q; i++) {
        cin >> tmp;
        if (tmp == 2) {
            cin >> tmp;
            cout << qry(positions[tmp - 1] + 1) << "\n";
        }
        else {
            cin >> tmp >> tmp1;
            upd(positions[tmp - 1] + 1, tmp1 - nodevals[tmp-1]);
            if (tmp != 1) {
                upd(positions[tmp - 1] + 2 + endingtimes[tmp - 1] - startingtimes[tmp - 1], -(tmp1 - nodevals[tmp - 1]));
            }
            nodevals[tmp - 1] = tmp1;
        }
    }
}