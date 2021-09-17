// ModernArt2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    freopen("art2.in", "r", stdin);
    freopen("art2.out", "w", stdout);
    int n, tmp;
    int maximum = 0;
    int m = 0;
    cin >> n;
    int prev = n + 1;
    bool ispainting = true;
    pair<int, int> tmppair;
    
    vector <int> paintingcolors;
    vector <int> colornums;
    vector <bool> firstcolor;
    for (int i = 0; i <= n; i++) {
        colornums.push_back(0);
        firstcolor.push_back(false);
    }
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (prev != tmp) {
            paintingcolors.push_back(tmp);
            colornums[tmp] ++;
            m++;
        }
        prev = tmp;
    }

    stack <pair<int, int>> painting; 
    for (int i = 0; i < m; i++) {
        if (paintingcolors[i] == 0) {
            continue;
        }
        if (firstcolor[paintingcolors[i]]) {
            tmppair = painting.top();
            if (tmppair.first != paintingcolors[i]) {
                cout << -1;
                ispainting = false;
                break;
            }
            painting.pop();
            if (tmppair.second != 1) {
                tmppair.second--;
                painting.push(tmppair);
            }
        }
        else {
            if (colornums[paintingcolors[i]] != 1) {
                tmppair.first = paintingcolors[i];
                tmppair.second = colornums[paintingcolors[i]]-1;
                painting.push(tmppair);
                firstcolor[paintingcolors[i]] = true;
            }
        }
        if (painting.size() + 1 > maximum) {
            maximum = painting.size() + 1;
        }
    }
    if (ispainting) {
        cout << maximum;
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
