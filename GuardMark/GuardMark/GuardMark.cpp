// GuardMark.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <bitset>
#include <math.h>

#pragma warning (disable : 4996)

using namespace std;

int bitcount(int n) {
	int count = 0;
	while (n > 0) {
		count++;
		n = n & (n - 1);
	}
	return count;
}

int main()
{
	freopen("guard.in", "r", stdin);
	freopen("guard.out", "w", stdout);

	int n, h, tmp1, tmp2, tmp3;
	cin >> n >> h;
	int maximum = -1;
	vector<int> height, weight, strength;
	vector<pair<int,int>> dp;

	for (int i = 0; i < n; i++) {
		cin >> tmp1 >> tmp2 >> tmp3;
		height.push_back(tmp1);
		weight.push_back(tmp2);
		strength.push_back(tmp3);
	}

	for (int i = 0; i < 1 << n; i++) {
		dp.push_back({0,-1});
	}

	dp[0] = { 0, 2147483647 };

	for (int i = 1; i < 1 << n; i++) {
		if (bitcount(i) == 1) {
			dp[i] = { height[log2(i)], strength[log2(i)] };
			if (dp[i].first >= h) {
				maximum = max(dp[i].second, maximum);
			}
			continue;
		}
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				if (dp[i ^ (1 << j)].second >= weight[j] && dp[i].second < min(dp[i ^ (1 << j)].second - weight[j], strength[j])) {
					dp[i].first = dp[i ^ (1 << j)].first + height[j];
					dp[i].second = min(dp[i ^ (1 << j)].second - weight[j], strength[j]);
					if (dp[i].first >= h) {
						maximum = max(dp[i].second, maximum);
					}
				}
			}
		}
	}
	if (maximum == -1) {
		cout << "Mark is too tall";
	}
	else {
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
