// NoctemVirtual.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

#pragma warning( disable : 4996 )

int main()
{
	ios::sync_with_stdio(0);
	freopen("whitejack.in", "r", stdin);
	freopen("whitejack.out", "w", stdout);

	int N, M, K, Q, tmp, tmp1;
	cin >> N >> M >> K >> Q;

	vector<int> n;
	vector<int> working;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		n.push_back(tmp);
	}

	unordered_map<int, vector<int>> m;

	for (int i = 0; i < M; i++) {
		cin >> tmp;
		m[tmp].push_back(i);
	}

	for (int x : n) {
		for (int y : m[K - x]) {
			working.push_back(y);
		}
	}
	sort(working.begin(), working.end());
	for (int i = 1; i < working.size(); i++) {
		if (working[i] == working[i - 1]) {
			working.erase(working.begin() + i);
			i--;
		}
	}
	working.push_back(M);
	for (int i = 0; i < Q; i++) {
		cin >> tmp >> tmp1;
		tmp--;
		tmp1--;
		if (lower_bound(working.begin(), working.end(), tmp) - working.begin() != lower_bound(working.begin(), working.end(), tmp1) - working.begin()) {
			cout << "YES" << "\n";
		}
		else {
			if (working[lower_bound(working.begin(), working.end(), tmp1) - working.begin()] == tmp1) {
				cout << "YES" << "\n";
			}
			else {
				cout << "NO" << "\n";
			}
		}
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
