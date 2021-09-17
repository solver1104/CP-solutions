//#pragma warning( disable : 4996 )
#include <bits/stdc++.h>

using namespace std;

int main()
{
    /*
    string problemName = "";
    ifstream fin(problemName + ".in");
    ofstream fout(problemName + ".out");
    */
    int t, l, r;

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> l >> r;
        if (r % 2 == 1) {
            if ((r + 1) / 2 >= l) {
                cout << (r+1)/2 - 1 << "\n";
            }
            else {
                cout << r - l << "\n";
            }
        }
        else {
            if (r/2 >= l) {
                cout << r/2 - 1 << "\n";
            }
            else {
                cout << r - l << "\n";
            }
        }
    }
}