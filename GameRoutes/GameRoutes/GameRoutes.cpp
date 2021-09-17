// GameRoutes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> sorted;
vector <vector <int>> edges;
vector<bool> toposortvisited;
vector <int> dp;

void dfs(int node) {
    toposortvisited[node] = true;
    for (auto next : edges[node]) {
        if (toposortvisited[next] == false) {
            dfs(next);
        }
    }
    sorted.push_back(node);
}

int main()
{
    int N, M, tmp1, tmp2;
    cin >> N >> M;



    for (int i = 0; i < N; i++) {
        edges.push_back({});
        toposortvisited.push_back(false);
        dp.push_back(0);
    }
    for (int i = 0; i < M; i++) {
        cin >> tmp1 >> tmp2;
        edges[tmp1 - 1].push_back(tmp2 - 1);
    }

    for (int i = 0; i < N; i++) {
        if (toposortvisited[i] == false) {
            dfs(i);
        }
    }
    reverse(sorted.begin(), sorted.end());

    dp[0] = 1;
    for (int i = 0; i < N-1; i++) {
        for (auto x : edges[sorted[i]]) {
            dp[x] += dp[sorted[i]];
            dp[x] = dp[x] % (1000000007);
        }
    }
    cout << dp[N - 1];
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
