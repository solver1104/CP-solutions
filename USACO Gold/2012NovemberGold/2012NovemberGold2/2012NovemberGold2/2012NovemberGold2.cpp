//#pragma warning( disable : 4996 )
#include <bits/stdc++.h>
#include <unordered_map>
#include <chrono>

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

const int MAXK = 10;
const int MAXN = 5e4 + 2;
int N, K, temp, lo, hi, mid, temp1;
int strings[MAXK][MAXN];
string tmp[10];
int RMQ[MAXK][MAXN][16];
int ans;
vector<int> prefixsummultiples[10][MAXN];
unordered_map<int, int, custom_hash> pairs[MAXN];
bool onrun;
int starttmp, cutstart, cutend;
int indext;
int combined[MAXN];

int main()
{

	string problemName = "cbs";
	ifstream cin(problemName + ".in");
	ofstream cout(problemName + ".out");


	ios::sync_with_stdio(0);
	cin.tie(0);

	ans = 0;
	cutstart = 0;
	cutend = 0;

	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		cin >> tmp[i];
	}

	for (int i = 0; i < N; i++) {
		if (tmp[0].substr(i, 1) == "(") {
			combined[i] = 1;
		}
		else {
			combined[i] = -1;
		}
		for (int j = 1; j < K; j++) {
			if (tmp[j].substr(i, 1) == "(") {
				temp = 1;
			}
			else {
				temp = -1;
			}
			if (temp != combined[i]) {
				combined[i] = 0;
			}
		}
	}

	for (int i = 0; i < N - 1; i++) {
		if (combined[i] == 1 && combined[i + 1] == -1) {
			if (!onrun) starttmp = i;
			onrun = true;
			i++;
		}
		else {
			if (onrun) {
				onrun = false;
				if (cutend - cutstart < i - starttmp) {
					cutend = i - 1;
					cutstart = starttmp;
				}
			}
		}
	}
	if (cutend - cutstart < N - 1 - starttmp && onrun) {
		cutend = N - 1;
		cutstart = starttmp;
	}
	if (cutend > cutstart + 25000) {
		for (int i = 0; i < K; i++) {
			if (cutend == N - 1) {
				tmp[i] = tmp[i].substr(0, cutstart + 2);
			}
			else {
				tmp[i] = tmp[i].substr(0, cutstart + 2) + tmp[i].substr(cutend + 1, N - cutend - 1);
			}
		}
		N = N - cutend + cutstart + 1;
	}
	else {
		cutend = 0;
		cutstart = 0;
	}
	for (int i = 0; i < K; i++) {
		indext = 1;
		for (char x : tmp[i]) {
			if (x == '(') {
				strings[i][indext] = strings[i][indext - 1] + 1;
			}
			else {
				strings[i][indext] = strings[i][indext - 1] - 1;
			}
			prefixsummultiples[i][strings[i][indext] + 1000].push_back(indext);
			indext++;
		}
	}

	for (int i = 0; i < K; i++) {
		for (int j = 1; j < N; j *= 2) {
			for (int k = 0; k <= N - j; k++) {
				if (j == 1) {
					RMQ[i][k][0] = strings[i][k];
					continue;
				}
				temp = log2(j);
				RMQ[i][k][temp] = min(RMQ[i][k][temp - 1], RMQ[i][k + j / 2][temp - 1]);
			}
		}
		for (int j = 1; j <= N; j++) {
			lo = j;
			hi = N;

			while (lo != hi) {
				mid = (lo + hi) / 2;
				temp = floor(log2(mid - j + 1));
				temp1 = pow(2, temp);
				if (min(RMQ[i][j][temp], RMQ[i][mid - temp1 + 1][temp]) >= strings[i][j - 1]) {
					lo = mid + 1;
				}
				else {
					hi = mid;
				}
			}

			for (int x : prefixsummultiples[i][strings[i][j - 1] + 1000]) {
				if (x < j) continue;
				if (x > lo) break;
				pairs[j][x] ++;
				if (i == K - 1 && pairs[j][x] == K) {
					temp = (cutend - cutstart + 1) / 2;
					if (j == cutstart || x == cutstart + 1) {
						if (cutend || cutstart) {
							ans += temp;
							continue;
						}
					}
					ans++;
				}
			}

		}
	}

	if (cutend || cutstart) {
		cout << ans - 1 + (((cutend - cutstart + 3) / 2) * ((cutend - cutstart + 1) / 2)) / 2;
	}
	else {
		cout << ans;
	}
}