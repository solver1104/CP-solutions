//#pragma warning( disable : 4996 )
#include <bits/stdc++.h>

using namespace std;

int N, K, tmp1, tmp2;
const int MAX = 3e5 + 5;
const int MAXINT = 2147483647;
int beauty[MAX];
vector<pair<int, int>> insubtree, successor, insubtreesecondary, successor2;
vector<int> adj[MAX];
vector<int> cycle, cycle1;

void dfs(int node = 0, int parent = -1) {
    for (int i : adj[node]) {
        if (i != parent) {
            dfs(i, node);
            bool switched = false;
            if (insubtree[node].first < beauty[i] - 1) {
                switched = true;
                insubtreesecondary[node] = insubtree[node];
                insubtree[node].first = beauty[i] - 1;
                insubtree[node].second = i;
            }
            else if (insubtree[node].first == beauty[i] - 1) {
                if (i < insubtree[node].second) {
                    switched = true;
                    insubtreesecondary[node] = insubtree[node];
                    insubtree[node].second = i;
                }
            }
            if (insubtree[node].first < insubtree[i].first - 1) {
                switched = true;
                insubtreesecondary[node] = insubtree[node];
                insubtree[node].first = insubtree[i].first - 1;
                insubtree[node].second = insubtree[i].second;
            }
            else if (insubtree[node].first == insubtree[i].first - 1) {
                if (insubtree[i].second < insubtree[node].second) {
                    switched = true;
                    insubtreesecondary[node] = insubtree[node];
                    insubtree[node].second = insubtree[i].second;
                }
            }
            if (!switched) {
                if (insubtreesecondary[node].first < beauty[i] - 1) {
                    insubtreesecondary[node].first = beauty[i] - 1;
                    insubtreesecondary[node].second = i;
                }
                else if (insubtreesecondary[node].first == beauty[i] - 1) {
                    if (i < insubtreesecondary[node].second) {
                        insubtreesecondary[node].second = i;
                    }
                }
                if (insubtreesecondary[node].first < insubtree[i].first - 1) {
                    insubtreesecondary[node].first = insubtree[i].first - 1;
                    insubtreesecondary[node].second = insubtree[i].second;
                }
                else if (insubtreesecondary[node].first == insubtree[i].first - 1) {
                    if (insubtreesecondary[i].second < insubtree[node].second) {
                        insubtreesecondary[node].second = insubtree[i].second;
                    }
                }
            }
        }
    }
}

void dfs1(int node = 0, int parent = -1) {
    bool used1 = false;
    if (successor[node].first < insubtree[node].first) {
        successor[node] = insubtree[node];
        used1 = true;
    }
    else if (successor[node].first == insubtree[node].first) {
        if (insubtree[node].second < successor[node].second) {
            successor[node] = insubtree[node];
            used1 = true;
        }
    }
    else {
        if (successor2[node].first < insubtree[node].first) {
            successor2[node] = insubtree[node];
        }
        else if (successor2[node].first == insubtree[node].first) {
            successor2[node].second = min(successor2[node].second, insubtree[node].second);
        }
    }
    if (successor2[node].first < insubtree[node].first && !used1) {
        successor2[node] = insubtree[node];
    }
    else if (successor2[node].first == insubtree[node].first && !used1) {
        successor2[node].second = min(insubtree[node].second, successor2[node].second);
    }
    if (successor2[node].first < insubtreesecondary[node].first) {
        successor2[node] = insubtreesecondary[node];
    }
    else if (successor2[node].first == insubtreesecondary[node].first) {
        successor2[node].second = min(insubtreesecondary[node].second, successor2[node].second);
    }
    for (int i : adj[node]) {
        if (i != parent) {
            if (successor[node].second != i) {
                successor[i] = { successor[node].first - 1, successor[node].second };
                if (successor2[i].second != i) {
                    successor2[i] = { successor2[node].first - 1, successor2[node].second };
                }
            }
            else {
                successor[i] = { successor2[node].first - 1, successor2[node].second };
            }
            if (successor[i].first < beauty[node] - 1) {
                successor[i] = { beauty[node] - 1, node };
                successor2[i] = successor[i];
            }
            else if (successor[i].first == beauty[node] - 1) {
                if (successor[i].second > node) {
                    successor[i] = { beauty[node] - 1, node };
                    successor2[i] = successor[i];
                }
                else if (successor2[i].first < beauty[node] - 1) {
                    successor2[i] = { beauty[node] - 1, node };
                }
                else if (successor2[i].first == beauty[node] - 1) {
                    successor2[i].second = min(successor2[i].second, node);
                }
            }
            else {
                if (successor2[i].first < beauty[node] - 1) {
                    successor2[i] = { beauty[node] - 1, node };
                }
                else if (successor2[i].first == beauty[node] - 1) {
                    successor2[i].second = min(successor2[i].second, node);
                }
            }
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

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> beauty[i];
        insubtree.push_back({ -MAXINT, MAXINT });
        insubtreesecondary.push_back({ -MAXINT, MAXINT });
        successor.push_back({ -MAXINT, MAXINT });
        successor2.push_back({ -MAXINT, MAXINT });
    }

    for (int i = 0; i < N - 1; i++) {
        cin >> tmp1 >> tmp2;
        tmp1--;
        tmp2--;
        adj[tmp1].push_back(tmp2);
        adj[tmp2].push_back(tmp1);
    }

    dfs();
    dfs1();

    int a = successor[0].second;
    int b = successor[successor[0].second].second;
    cycle.push_back(0);
    cycle.push_back(a);
    while (a != b) {
        a = successor[a].second;
        b = successor[successor[b].second].second;
        cycle.push_back(a);
    }
    int length = 1;
    b = successor[a].second;
    cycle1.push_back(a);
    cycle1.push_back(b);
    while (b != a) {
        b = successor[b].second;
        length++;
        cycle1.push_back(b);
    }

    if (K <= cycle.size()) {
        cout << cycle[K - 1] + 1;
    }

    else {
        cout << cycle1[(K - cycle.size()) % length + 1] + 1;
    }
}