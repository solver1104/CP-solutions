//#pragma warning( disable : 4996 )
#include <bits/stdc++.h>

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;

int t, n, m, k, sameindex;
vector<int> v;
vector<int> h;
vector<pair<int,int>> vp;
vector<pair<int, int>> hp;
vector<int> hpp, vpp;
long long int ans, tmp, tmp1;

int main()
{
	/*
	string problemName = "";
	ifstream fin(problemName + ".in");
	ofstream fout(problemName + ".out");
	*/

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	for (int i = 0; i < t; i++) {
		ans = 0;
		v.clear();
		h.clear();
		vp.clear();
		hp.clear();
		hpp.clear();
		vpp.clear();
		cin >> n >> m >> k;

		for (int j = 0; j < n; j++) {
			cin >> tmp;
			v.push_back(tmp);
		}
		for (int j = 0; j < m; j++) {
			cin >> tmp;
			h.push_back(tmp);
		}

		for (int j = 0; j < k; j++) {
			cin >> tmp >> tmp1;
			if (*lower_bound(v.begin(), v.end(), tmp) == tmp) {
				if (*lower_bound(v.begin(), v.end(), tmp1) != tmp1) {
					vp.push_back({ tmp1, tmp });
					vpp.push_back(tmp1);
				}
			}
			else {
				hp.push_back({ tmp, tmp1 });
				hpp.push_back(tmp);
			}
		}

		sort(vp.begin(), vp.end());
		sort(hp.begin(), hp.end());
		
		for (int x : h) {
			tmp = upper_bound(vpp.begin(), vpp.end(), x) - vpp.begin();
			tmp1 = upper_bound(vpp.begin(), vpp.end(), x) - vpp.begin() - 1;

			ans += (((tmp1 - tmp) * (tmp1 - tmp + 1)) / 2);
			for (int y = tmp; y <= tmp1; y++) {
				if (y == 0) {
					sameindex++;
					continue;
				}
				if (vp[y].second != vp[y - 1].second) {
					ans -= ((sameindex - 1) * sameindex) / 2;
					sameindex = 0;
				}
				sameindex++;
			}
		}

		for (int x : v) {
			tmp = upper_bound(hpp.begin(), hpp.end(), x) - hpp.begin();
			tmp1 = upper_bound(hpp.begin(), hpp.end(), x) - hpp.begin() - 1;

			ans += (((tmp1 - tmp) * (tmp1 - tmp + 1)) / 2);
			for (int y = tmp; y <= tmp1; y++) {
				if (y == 0) {
					sameindex++;
					continue;
				}
				if (hp[y].second != hp[y - 1].second) {
					ans -= ((sameindex - 1) * sameindex) / 2;
					sameindex = 0;
				}
				sameindex++;
			}
		}

		cout << ans << "\n";
	}
}