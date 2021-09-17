//#pragma warning( disable : 4996 )
#include <bits/stdc++.h>

//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")

using namespace std;

int N, K, temp1, temp2;
char tmp1, tmp2;
const long long int INTMAX = 1e18 + 4;

int main() {
    /*
    string problemName = "";
    ifstream fin(problemName + ".in");
    ofstream fout(problemName + ".out");
    */

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> K >> N;
    bool changedr = false;
    long long int oldlmedian = 0;
    long long int sum = 0;
    multiset<int>::iterator lmedian;
    multiset<int>::iterator rmedian;
    long long int cursumleft = 0;
    long long int cursumright = 0;
    long long int curmin = INTMAX;
    int intervalnum = 0;
    vector<pair<int, pair<int, int>>> intervals;
    multiset<int> significantleft;
    multiset<int> significantright;
    for (int i = 0; i < N; i++) {
        cin >> tmp1 >> temp1 >> tmp2 >> temp2;
        if (tmp1 == tmp2) sum += abs(temp2 - temp1);
        else {
            sum++;
            intervalnum++;
            if (temp1 > temp2) swap(temp1, temp2);
            intervals.push_back({ temp1 + temp2, { temp1, temp2 } });
            significantright.insert(temp1);
            significantright.insert(temp2);
        }
    }
    if (intervals.size()) {
        sort(intervals.begin(), intervals.end());
        rmedian = next(significantright.begin(), intervalnum);
        for (const int& i : significantright) {
            cursumright += abs(i - *rmedian);
        }
        curmin = cursumright;
        if (K == 1) cout << curmin + sum;
        else {
            temp1 = intervals[0].second.first;
            temp2 = intervals[0].second.second;
            significantleft.insert(temp1);
            significantleft.insert(temp2);
            if (significantright.lower_bound(temp2) == rmedian) {
                changedr = true;
                rmedian++;
            }
            significantright.erase(significantright.lower_bound(temp1));
            significantright.erase(significantright.lower_bound(temp2));

            lmedian = next(significantleft.begin(), 1);
            cursumleft += (temp2 - temp1);
            cursumright -= (abs(*rmedian - temp2) + abs(*rmedian - temp1));
            if (temp2 <= *rmedian && !changedr) rmedian++;
            curmin = min(curmin, cursumleft + cursumright);

            for (int i = 1; i < intervalnum-1; i++) {
                changedr = false;
                temp1 = intervals[i].second.first;
                temp2 = intervals[i].second.second;
                significantleft.insert(temp1);
                significantleft.insert(temp2);
                if (significantright.lower_bound(temp2) == rmedian) {
                    changedr = true;
                    rmedian++;
                }
                significantright.erase(significantright.lower_bound(temp1));
                significantright.erase(significantright.lower_bound(temp2));
                
                cursumleft += (abs(*lmedian - temp2) + abs(*lmedian - temp1));
                if (temp1 >= *lmedian) {
                    lmedian++;
                }
                else if (temp2 < *lmedian) {
                    oldlmedian = *lmedian;
                    lmedian--;
                    cursumleft -= (2 * abs(oldlmedian - *lmedian));
                }
                
                if (changedr) cursumright -= (temp2 - temp1);
                else cursumright -= (abs(*rmedian - temp2) + abs(*rmedian - temp1));
                if (temp2 <= *rmedian && !changedr) rmedian++;
                curmin = min(curmin, cursumleft + cursumright);
            }
            cout << curmin + sum;
        }
    }
    else { cout << sum; }
}