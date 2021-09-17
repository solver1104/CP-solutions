// QuantumSuperposition.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;



vector <vector<int>> edges1;
vector<vector<int>> edges2;
vector<bool> visited1;
vector<bool> visited2;
vector<int> sorted1;
vector<int> sorted2;
vector <unordered_set <int>> dp1;
vector <unordered_set <int>> dp2;
unordered_set<int> tmpset;
void dfs1(int node) {
    visited1[node] = true;
    for (auto next : edges1[node]) {
        if (!visited1[next]) {
            dfs1(next);
        }
    }
    sorted1.push_back(node);
}

void dfs2(int node) {
    visited2[node] = true;
    for (auto next : edges2[node]) {
        if (!visited2[next]) {
            dfs2(next);
        }
    }
    sorted2.push_back(node);
}

int main()
{
    int N1, N2, M1, M2, tmp1, tmp2, tests, tmptest;
    cin >> N1 >> N2 >> M1 >> M2;

    for (int i = 0; i < N1; i++) {
        edges1.push_back({});
        dp1.push_back(tmpset);
        visited1.push_back(false);
    }
    for (int i = 0; i < N2; i++) {
        dp2.push_back(tmpset);
        visited2.push_back(false);
        edges2.push_back({});
    }
    dp1[0].insert(0);
    dp2[0].insert(0);
    for (int i = 0; i < M1; i++) {
        cin >> tmp1 >> tmp2;
        edges1[tmp1 - 1].push_back(tmp2 - 1);
    }
    for (int i = 0; i < M2; i++) {
        cin >> tmp1 >> tmp2;
        edges2[tmp1 - 1].push_back(tmp2 - 1);
    }

    for (int i = 0; i < M1; i++) {
        if (!visited1[i]) {
            dfs1(i);
        }
    }
    for (int i = 0; i < M2; i++) {
        if (!visited2[i]) {
            dfs2(i);
        }
    }
    reverse(sorted1.begin(), sorted1.end());
    reverse(sorted2.begin(), sorted2.end());

    for (int i = 0; i < N1-1; i++) {
        for (auto j : edges1[i]) {
            for (auto x = dp1[i].begin(); x != dp1[i].end(); ++x) {
                dp1[j].insert(*x + 1);
            }
        }
    }
    for (int i = 0; i < N2 - 1; i++) {
        for (auto j : edges2[i]) {
            for (auto x = dp2[i].begin(); x != dp2[i].end(); ++x) {
                dp2[j].insert(*x + 1);
            }
        }
    }

    for (auto x = dp1[N1-1].begin(); x != dp1[N1-1].end(); ++x) {
        for (auto y = dp2[N2 - 1].begin(); y != dp2[N2 - 1].end(); ++y) {
            tmpset.insert(*x + *y);
        }
    }

    cin >> tests;
    for (int i = 0; i < tests; i++) {
        cin >> tmptest;
        if (tmpset.find(tmptest) == tmpset.end()) {
            cout << "No";
        }
        else {
            cout << "Yes";
        }
        cout << "\n";
    }
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
