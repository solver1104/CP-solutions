// Portals.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class UF {
public:
    long long int connectednum;
    vector < pair < int, int >> nodes;
    UF(int num) {
        for (int i = 0; i < num; i++) {
            nodes.push_back({i,1});
        }
        connectednum = num;
    }
    bool find(int a, int b) {
        if (findroot(a) == findroot(b)) {
            return true;
        }
        return false;
    }
    void join(int a, int b) {
        if (find(a, b)) {
            return;
        }
        else {
            if (nodes[findroot(a)].second > nodes[findroot(b)].second) {
                nodes[findroot(b)].first = findroot(a);
                nodes[findroot(a)].second = max(nodes[findroot(b)].second + 1, nodes[findroot(a)].second);
            }
            else {
                nodes[findroot(a)].first = findroot(b);
                nodes[findroot(b)].second = max(nodes[findroot(a)].second + 1, nodes[findroot(b)].second);
            }
            connectednum--;
        }
    }
    int findroot(int a) {
        if (a == nodes[a].first) {
            return a;
        }
        return findroot(nodes[a].first);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, tmp1, tmp2, tmp3, tmp4, tmp5;
    long long int total = 0;
    vector<int> temp;
    vector<pair<int, int>> connections;
    vector<vector<int>> costs;
    cin >> N;

    for (int i = 0; i < 2*N; i++) {
        connections.push_back({ -1,-1 });
    }

    for (int i = 0; i < N; i++) {
        temp.clear();
        cin >> tmp1 >> tmp2 >> tmp3 >> tmp4 >> tmp5;
        if (connections[tmp2-1].first == -1) {
            connections[tmp2-1].first = 2 * i;
        }
        else {
            connections[tmp2-1].second = 2 * i;
        }
        if (connections[tmp3-1].first == -1) {
            connections[tmp3-1].first = 2 * i;
        }
        else {
            connections[tmp3-1].second = 2 * i;
        }
        if (connections[tmp4-1].first == -1) {
            connections[tmp4-1].first = 2 * i + 1;
        }
        else {
            connections[tmp4-1].second = 2 * i + 1;
        }
        if (connections[tmp5-1].first == -1) {
            connections[tmp5-1].first = 2 * i + 1;
        }
        else {
            connections[tmp5-1].second = 2 * i + 1;
        }
        temp.push_back(tmp1);
        temp.push_back(i);
        costs.push_back(temp);
    }

    sort(costs.begin(), costs.end());
    UF graph(2*N);

    for (pair<int, int> x : connections) {
        graph.join(x.first, x.second);
    }

    for (int i = 0; i < N; i++) {
        if (graph.connectednum == 1) {
            break;
        }
        if (!graph.find(2 * costs[i][1], 2 * costs[i][1] + 1)) {
            total += costs[i][0];
            graph.join(2 * costs[i][1], 2 * costs[i][1] + 1);
        }
    }

    cout << total;
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
