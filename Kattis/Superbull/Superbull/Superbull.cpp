// Superbull.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma warning( disable : 4996 )
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using vi = vector<int>;

class UF {
    public:
        vector<pair<int, int>> nodes;
        UF(int num) {
            for (int i = 0; i < num; i++) {
                nodes.push_back({ i, 1 });
            }
        }
        bool find(int a, int b) {
            if (findroot(a) == findroot(b)) {
                return true;
            }
            return false;
        }
        void join (int a, int b) {
            if (find(a, b)) {
                return;
            }
            else {
                if (nodes[findroot(a)].second > nodes[findroot(b)].second) {
                    nodes[findroot(b)].first = findroot(a);
                    nodes[findroot(a)].second = max(nodes[findroot(b)].second+1,nodes[findroot(a)].second);
                }
                else {
                    nodes[findroot(a)].first = findroot(b);
                    nodes[findroot(b)].second = max(nodes[findroot(a)].second + 1, nodes[findroot(b)].second);
                }
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
    freopen("superbull.in", "r", stdin);
    freopen("superbull.out", "w", stdout);
    int N, tmp;
    long long int total = 0;
    int edgescounted = 0;
    pair<int, pair<int, int>> tmppair;
    cin >> N;

    vi IDs;
    vector<pair<int, pair<int, int>>> e;

    for (int i = 0; i < N; i++) {
        cin >> tmp;
        IDs.push_back(tmp);
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            tmppair.first = IDs[i] ^ IDs[j];
            tmppair.second.first = i;
            tmppair.second.second = j;
            e.push_back(tmppair);
        }
    }

    sort(e.begin(), e.end(), [](pair<int,pair<int,int>> a, pair<int, pair<int, int>> b) {
        return a.first > b.first;
        });
    UF graph(N);

    for (pair<int, pair<int, int>> i : e) {
        if (edgescounted > N - 2) {
            break;
        }
        else {
            if (!graph.find(i.second.first, i.second.second)) {
                graph.join(i.second.first, i.second.second);
                edgescounted++;
                total += i.first;
            }
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
