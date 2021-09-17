//#pragma warning( disable : 4996 )
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int N, Q, tmp, tmp1;
const int MAX = 1e5 + 5;
int startingtimes[MAX], endingtimes[MAX], nodevals[MAX], depths[MAX];
vector<int> adj[MAX], sortednodes;
long long int fenwick[MAX];
int timer = 0;
unordered_map<int, int> positions;
vector<pair<int, int>> LCA;
vector<pair<int,int>> RMQ[2 * MAX];
unordered_map<int, int> positionsLCA;
bool visited[MAX];

void upd(int i, int v) {
    for (; i <= N; i += i & (-i)) fenwick[i] = fenwick[i] ^ v;
}

long long int qry(int i) {
    long long int sum = 0;
    for (; i > 0; i -= i & (-i)) sum = sum ^ fenwick[i];
    return sum;
}

void dfs(int node = 0, int parent = -1) {
    sortednodes.push_back(node);
    positions[node] = timer;
    startingtimes[node] = timer++;
    for (int i : adj[node]) {
        if (i != parent) {
            dfs(i, node);
            depths[i] = depths[node] + 1;
        }
    }
    endingtimes[node] = timer - 1;
}

void dfsLCA(int node = 0) {
    visited[node] = true;
    LCA.push_back({ depths[node], node });
    positionsLCA[node] = LCA.size() - 1;
    for (int i : adj[node]) {
        if (!visited[i]) {
            dfsLCA(i);
            LCA.push_back({ depths[node], node });
        }
    }
}

void precomputeRMQ() {
    for (int i = 0; i < 2 * N - 1; i++) {
        RMQ[i].push_back(LCA[i]);
    }
    int i = 2;
    while (i < 2 * N) {
        for (int j = 0; j < 2 * N - i; j++) {
            RMQ[j].push_back(min(RMQ[j].back(), RMQ[j + i / 2].back()));
        }
        i *= 2;
    }
}

int computeLCA(int node1, int node2) {
    if (positionsLCA[node1] > positionsLCA[node2]) {
        swap(node1, node2);
    }

    int k = floor(log2(positionsLCA[node2] - positionsLCA[node1] + 1));

    return min(RMQ[positionsLCA[node1]][k], RMQ[positionsLCA[node2] + 1 - int(pow(2,k))][k]).second;
}

int main()
{
    
    string problemName = "cowland";
    ifstream fin(problemName + ".in");
    ofstream fout(problemName + ".out");
    
    fin >> N >> Q;

    for (int i = 0; i < N; i++) {
        fin >> nodevals[i];
    }

    for (int i = 0; i < N - 1; i++) {
        fin >> tmp >> tmp1;
        adj[tmp - 1].push_back(tmp1 - 1);
        adj[tmp1 - 1].push_back(tmp - 1);
    }

    dfs();

    upd(1, nodevals[0]);
    for (int i = 1; i < N; i++) {
        upd(i + 1, nodevals[sortednodes[i]]);
        upd(i + 2 + endingtimes[sortednodes[i]] - startingtimes[sortednodes[i]], nodevals[sortednodes[i]]);
    }

    dfsLCA();
    precomputeRMQ();
    for (int i = 0; i < Q; i++) {
        fin >> tmp;
        if (tmp == 1) {
            fin >> tmp >> tmp1;
            upd(positions[tmp - 1] + 1, nodevals[tmp - 1] ^ tmp1);
            upd(positions[tmp - 1] + 2 + endingtimes[tmp - 1] - startingtimes[tmp - 1], nodevals[tmp - 1] ^ tmp1);
            nodevals[tmp - 1] = tmp1;
        }
        else {
            fin >> tmp >> tmp1;
            fout << ((qry(positions[tmp - 1] + 1)) ^ (qry(positions[tmp1 - 1] + 1)) ^ nodevals[computeLCA(tmp - 1, tmp1- 1)]) << "\n";
        }
    }
}