// MilkingOrder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#include <queue>

using namespace std;

vector<vector<int>> restrictions;
vector<set<int>> edges;
vector <int> indegrees;
vector <bool> visited;
vector <bool> finished;
vector <int> sorted;
priority_queue<int, vector<int>, greater<int> > indegreezero;
int N, M, tmp, tmp1, tmpnodekahn;
bool hascycle = false;

void dfs(int node) {
    visited[node] = true;
    for (int i : edges[node]) {
        if (visited[i] & !finished[i]) {
            hascycle = true;
        }
        if (!visited[i]) {
            dfs(i);
        }
    }
    sorted.push_back(node);
    finished[node] = true;
}

bool check(int n) {
    if (n < 0) {
        return true;
    }
    else {
        hascycle = false;
        sorted.clear();
        for (int i = 0; i < N; i ++) {
            edges[i] = {};
        }
        for (int i = 0; i < N; i++) {
            visited[i] = false;
            finished[i] = false;
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < restrictions[i].size() - 1; j++) {
                edges[restrictions[i][j]].insert(restrictions[i][j + 1]);
            }
        }
        for (int i = N-1; i >= 0; i--) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        return !hascycle;
    }
}

int main()
{
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        edges.push_back({});
        visited.push_back(false);
        finished.push_back(false);
        indegrees.push_back(0);
    }
    for (int i = 0; i < M; i++) {
        restrictions.push_back({});
        cin >> tmp;
        for (int j = 0; j < tmp; j++) {
            cin >> tmp1;
            restrictions[i].push_back(tmp1-1);
        }
    }
    
    int low = -1;
    int high = M-1;
    int mid = (low + high) / 2;
    while (high - low > 1) {
        mid = (low + high) / 2;
        if (check(mid)) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    if (check(high)) {
        sorted.clear();       
    }
    else {
        check(low);
        sorted.clear();
    }
    for (int i = 0; i < N; i++) {
        for (int j : edges[i]) {
            indegrees[j] ++;
        }
    }
    for (int i = 0; i < N; i++) {
        if (indegrees[i] == 0) {
            indegreezero.push(i);
        }
    }
    while (indegreezero.size() != 0) {
        tmpnodekahn = indegreezero.top();
        indegreezero.pop();
        sorted.push_back(tmpnodekahn + 1);
        for (int i : edges[tmpnodekahn]) {
            indegrees[i] --;
            if (indegrees[i] == 0) {
                indegreezero.push(i);
            }
        }
    }
    for (int i = 0; i < N - 1; i++) {
        cout << sorted[i] << " ";
    }
    cout << sorted[N - 1];
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
