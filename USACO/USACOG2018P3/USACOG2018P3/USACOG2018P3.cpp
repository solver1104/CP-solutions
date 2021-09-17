// USACOG2018P3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, x, tmp;
    vector<int> vals;
    vector<int> dp;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        vals.push_back(tmp);
    }
    for (int j = 0; j < x + 1; j++) {
        dp.push_back(2147483647);
    }
    dp[0] = 0;
    for (int i = 0; i < x; i++) {
        for (int value : vals) {
            if (i + value < x + 1) {
                dp[i + value] = min(dp[i + value], dp[i] + 1);
            }
        }
    }

    if (dp[x] != 2147483647){
        cout << dp[x];
    }
    else {
        cout << -1;
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
