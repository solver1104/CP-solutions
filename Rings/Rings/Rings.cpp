//#pragma warning( disable : 4996 )
#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e4 + 5;

int main()
{
    /*
    string problemName = "";
    ifstream fin(problemName + ".in");
    ofstream fout(problemName + ".out");
    */
    int t, length;
    char tmp;
    cin >> t;
    bool haszero, hasany;
    int zeroindex = 0;
    int str[MAX];
    for (int i = 0; i < t; i++) {
        cin >> length;
        haszero = false;
        hasany = false;
        for (int i = 0; i < length; i++) {
            cin >> tmp;
            if (tmp - '0') {
                str[i] = 1;
            }
            else {
                if (i >= floor(length / 2)) {
                    haszero = true;
                }
                hasany = true;
                zeroindex = i;
                str[i] = 0;
            }
        }
        if (haszero) {
            cout << 1 << " " << zeroindex + 1 << " " << 1 << " " << zeroindex << "\n";
        }
        else {
            if (hasany) {
                cout << zeroindex + 1 << " " << length << " " << zeroindex + 2 << " " << length << "\n";
            }
            else {
                cout << 2 << " " << length << " " << 1 << " " << length - 1 << "\n";
            }
        }
    }
}