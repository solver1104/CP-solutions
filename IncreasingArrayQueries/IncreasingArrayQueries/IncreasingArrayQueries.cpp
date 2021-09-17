// IncreasingArrayQueries.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int n, q, tmp, r1, r2;
    int tempcount = 0;
    cin >> n >> q;

    vector<int> numbers;
    vector<int> nearest;
    vector<int> increased;
    stack<pair<int, int>> s;

    for (int i = 0; i < n; i++) {
        cin >> tmp;
        numbers.push_back(tmp);
        nearest.push_back(n);
    }

    s.push({ numbers[0], 0 });
    for (int i = 1; i < n; i++) {
        while (s.top().first <= numbers[i]) {
            s.pop();
            if (s.empty()) {
                break;
            }
        }

        if (!s.empty()) {
            nearest[i] = s.top().second;
        }
        s.push({ numbers[i], i });
    }

    for (int i = 0; i < q; i++) {
        increased.clear();
        tempcount = 0;
        cin >> r1 >> r2;
        r1--;
        r2--;
        for (int i = r1; i <= r2; i++) {
            if (nearest[i] != n && nearest[i] >= r1) {
                increased.push_back(increased[nearest[i] - r1] + numbers[nearest[i]] - numbers[i]);
                tempcount += increased.back();
            }
            else {
                increased.push_back(0);
            }
        }
        cout << tempcount << "\n";
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
