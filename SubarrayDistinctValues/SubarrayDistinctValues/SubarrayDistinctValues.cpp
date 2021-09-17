//#pragma warning( disable : 4996 )
#include <bits/stdc++.h>
#include <unordered_map>

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;

struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

int n, k;
vector<int> numbers;
unordered_map<int, int, custom_hash> distinct;
int cursize = 0;
int lindex = 0;

long long int total = 0;


int main()
{
	/*
	string problemName = "";
	ifstream fin(problemName + ".in");
	ofstream fout(problemName + ".out");
	*/

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		numbers.push_back(0);
		cin >> numbers[i];
	}

	for (int r = 0; r < n; r++) {
		distinct[numbers[r]] ++;
		cursize++;

		while (distinct.size() > k) {
			if (distinct[numbers[lindex]] == 1) {
				distinct.erase(numbers[lindex]);
			}
			else {
				distinct[numbers[lindex]] --;
			}
			lindex++;
			cursize--;
		}
		total += cursize;
	}

	cout << total;
}