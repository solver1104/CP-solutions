//#pragma warning( disable : 4996 )
#include <bits/stdc++.h>
#include <unordered_map>

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;

struct VectorHasher {
	int operator()(const vector<int>& V) const {
		int hash = V.size();
		for (auto& i : V) {
			hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
		}
		return hash;
	}
};

const int MAX = 201;
int N, tmp1, tmp2, tempdist;
int maximum = 0;
pair<int, int> locs[MAX];
int distc[MAX], distcc[MAX], iangles[MAX];
unordered_map <vector<int>, int, VectorHasher> tags;
vector<int> temp;

int main()
{
	
	string problemName = "lightsout";
	ifstream cin(problemName + ".in");
	ofstream cout(problemName + ".out");
	

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp1 >> tmp2;
		locs[i] = { tmp1, tmp2 };
	}

	for (int i = 1; i < N; i++) {
		tmp1 = 0;
		for (int j = i; j > 0; j--) {
			tmp1 += abs(locs[j].first - locs[j - 1].first + locs[j].second - locs[j - 1].second);
		}
		distcc[i] = tmp1;

		tmp1 = 0;
		for (int j = i; j < N - 1; j++) {
			tmp1 += abs(locs[j + 1].first - locs[j].first + locs[j + 1].second - locs[j].second);
		}
		tmp1 += abs(locs[N - 1].first + locs[N - 1].second - locs[0].first - locs[0].second);
		distc[i] = tmp1;
	}

	for (int i = 1; i < N - 1; i++) {
		if (locs[i - 1].first == locs[i].first) {
			if (locs[i - 1].second > locs[i].second) {
				if (locs[(i + 1) % N].first > locs[i].first) iangles[i] = 1;
				else iangles[i] = 0;
			}
			else {
				if (locs[(i + 1) % N].first > locs[i].first) iangles[i] = 0;
				else iangles[i] = 1;
			}
		}
		else {
			if (locs[i - 1].first > locs[i].first) { 
				if (locs[(i + 1) % N].second > locs[i].second) iangles[i] = 0;
				else iangles[i] = 1;
			}
			else {
				if (locs[(i + 1) % N].second > locs[i].second) iangles[i] = 1;
				else iangles[i] = 0;
			}
		}
	}

	for (int i = 1; i < N; i++) {
		temp.clear();
		temp.push_back(iangles[i]);
		tags[temp] ++;
		for (int j = 0; j < N - i - 1; j++) {
			temp.push_back(abs((locs[i + j + 1].first - locs[i + j].first) + (locs[i + j + 1].second - locs[i + j].second)));
			temp.push_back(iangles[i + j + 1]);
			tags[temp] ++;
		}
	}

	for (int i = 1; i < N; i++) {
		tempdist = 0;
		temp.clear();
		temp.push_back(iangles[i]);
		if (tags[temp] == 1) {
			continue;
		}
		for (int j = 0; j < N - i - 1; j++) {
			temp.push_back(abs((locs[i + j + 1].first - locs[i + j].first) + (locs[i + j + 1].second - locs[i + j].second)));
			temp.push_back(iangles[i + j + 1]);
			tempdist += abs((locs[i + j + 1].first - locs[i + j].first) + (locs[i + j + 1].second - locs[i + j].second));
			if (tags[temp] == 1) {
				maximum = max(maximum, tempdist + min (distc[i + j + 1], distcc[i + j + 1]) - min (distc[i], distcc[i]));
				break;
			}
		}
		
	}

	cout << maximum;
}