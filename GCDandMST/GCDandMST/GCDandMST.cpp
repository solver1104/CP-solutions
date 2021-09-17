// GCDandMST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector <int> vi;

class UF {
public:
    long long int connectednum;
    vector <pair<int, int>> nodes;
    UF(int num) {
        for (int i = 0; i < num; i++) {
            nodes.push_back({ i, 1 });
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, tmp, lb, hb;
    long long int total = 0;
    long long int p;
    pair <int, int> temp;
    vi a, covered;
    vector <pair<int, int>> ordered;
    cin >> t;
    for (int testcase = 0; testcase < t; testcase++) {
        a.clear();
        ordered.clear();
        covered.clear();
        total = 0;
        cin >> n >> p;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            temp.first = tmp;
            temp.second = i;
            a.push_back(tmp);
            ordered.push_back(temp);
            covered.push_back(0);
        }

        sort(ordered.begin(), ordered.end());
        UF graph(n);

        for (int i = 0; i < n; i++) {
            if (ordered[i].first >= p) {
                break;
            }
            if (covered[ordered[i].second] == 1) {
                continue;
            }
            lb = ordered[i].second;
            hb = ordered[i].second;
            covered[ordered[i].second] = 1;
            for (int j = ordered[i].second - 1; j >= 0; j--) {
                if (a[j] % ordered[i].first != 0) {
                    break;
                }
                lb = j;
                covered[j] = 1;
            }
            for (int j = ordered[i].second + 1; j < n; j++) {
                if (a[j] % ordered[i].first != 0) {
                    break;
                }
                hb = j;
                covered[j] = 1;
            }
            for (int x = lb; x <= hb; x++) {
                if (graph.connectednum == 1) {
                    break;
                }
                if (!graph.find(x, ordered[i].second)) {
                    graph.join(x, ordered[i].second);
                    total += ordered[i].first;
                }
            }
            if (graph.connectednum == 1) {
                break;
            }
        }
        cout << p * (graph.connectednum - 1) + total << "\n";
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