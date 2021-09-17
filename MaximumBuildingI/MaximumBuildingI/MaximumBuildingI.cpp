// MaximumBuildingI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n, m, count;
    int maximum = 0;
    string tmp;
    pair<int, int> store;
    vector <vector <int>> trees;
    vector <int> heights;
    stack<pair<int,int>> temp;
    
    cin >> n >> m;
    count = 0;
    for (int i = 0; i < m; i++) {
        heights.push_back(0);
        trees.push_back({});
    }

    for (int i = 0; i < n; i++) {
        cin >> tmp;
        for (char x : tmp) {
            if (x == 42) {
                trees[count].push_back(n-i-1);
            }
            count++;
        }
        count = 0;
    }


    for (int i = 0; i < n; i++) {
        while (!temp.empty()) {
            temp.pop();
        }
        for (int j = 0; j < m; j++) {
            if (trees[j].empty()) {
                heights[j] = n - i;
                continue;
            }
            if (i > trees[j].back()) {
                trees[j].pop_back();
            }
            if (trees[j].empty()) {
                heights[j] = n - i;
                continue;
            }
            heights[j] = trees[j].back() - i;
        }
        

        store.first = heights[0];
        store.second = 0;
        temp.push(store);
        for (int j = 1; j < m; j++) {
            store.second = j;
            while (temp.top().first > heights[j]) {
                store = temp.top();
                temp.pop();
                maximum = max(maximum, store.first * (j - store.second));
                if (temp.empty()) {
                    break;
                }
            }
            store.first = heights[j];
            temp.push(store);
        }
        while (!temp.empty()) {
            store = temp.top();
            temp.pop();
            maximum = max(maximum, store.first * (m - store.second));
        }
    }
    cout << maximum;
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
