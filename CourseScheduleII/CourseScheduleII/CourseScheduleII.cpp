// CourseScheduleII.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, m, tmp1, tmp2, node;
    int pushed = 0;
    cin >> n >> m;
    vector <vector<int>> edges;
    vector <int> outdegrees;
    priority_queue<int> kahn;
    vector <int> sorted;

    for (int i = 0; i < n; i++) {
        outdegrees.push_back(0);
        edges.push_back({});
        sorted.push_back(0);
    }
    for (int i = 0; i < m; i++) {
        cin >> tmp1 >> tmp2;
        edges[tmp2 - 1].push_back(tmp1 - 1);
        outdegrees[tmp1 - 1] ++;
    }
    for (int i = 0; i < n; i++) {
        if (outdegrees[i] == 0) {
            kahn.push(i);
        }
    }
    while (kahn.size() != 0) {
        node = kahn.top();
        kahn.pop();
        sorted[n-1-pushed] = node + 1;
        pushed++;
        for (int i : edges[node]) {
            outdegrees[i] --;
            if (outdegrees[i] == 0) {
                kahn.push(i);
            }
        }
    }
    for (int i = 0; i < n-1; i++) {
        cout << sorted[i] << " ";
    }
    cout << sorted[n-1];
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
