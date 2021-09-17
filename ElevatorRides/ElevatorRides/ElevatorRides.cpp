// ElevatorRides.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int main()
{
    int n, x, tmp, size;
    int iterations = 0;
    int maximum = 0;
    int curr = 0;
    cin >> n >> x;
    vector<int> weights;

    vector<pair<int, int>> dp;

    for (int i = 0; i < n; i++) {
        cin >> tmp;
        weights.push_back(tmp);
    }
    
    for (int i = 0; i < 1 << n; i++) {
        dp.push_back({ n+1,0 });
    }

    dp[0] = { 1,0 };

    for (int i = 1; i < 1 << n; i++) {
        for (int j = 0; j < n; j++) {
            if ((1 << j) & i) {
                if (weights[j] <= x - dp[i ^ (1 << j)].second) {
                    if (dp[i].first > dp[i ^ (1 << j)].first) {
                        dp[i].first = dp[i ^ (1 << j)].first;
                        dp[i].second = dp[i ^ (1 << j)].second + weights[j];
                    }
                    else if (dp[i].first == dp[i ^ (1 << j)].first) {
                        dp[i].second = min(dp[i ^ (1 << j)].second + weights[j], dp[i].second);
                    }
                }
                else {
                    if (dp[i].first > dp[i ^ (1 << j)].first + 1) {
                        dp[i].first = dp[i ^ (1 << j)].first + 1;
                        dp[i].second = weights[j];
                    }
                    else if (dp[i].first == dp[i ^ (1 << j)].first + 1) {
                        dp[i].second = min(weights[j], dp[i].second);
                    }
                }
            }
        }
    }
    cout << dp[(1 << n) - 1].first;
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
