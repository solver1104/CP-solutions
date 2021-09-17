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

    int t, length, threecount, sevencount, twocount, fivecount;
    cin >> t;
    char num[50];
    bool exitloop = false;

    for (int i = 0; i < t; i++) {
        threecount = 0; 
        sevencount = 0;
        twocount = 0; 
        fivecount = 0;
        exitloop = false;
        cin >> length;
        for (int j = 0; j < length; j++) {
            cin >> num[j];
            if (num[j] - '0' == 1 || num[j] - '0' == 4 || num[j] - '0' == 6 || num[j] - '0' == 8 || num[j] - '0' == 9) {
                if (!exitloop) {
                    cout << 1 << "\n" << num[j] - '0' << "\n";
                    exitloop = true;
                }
            }
            if (num[j] - '0' == 3) {
                threecount++;
            }
            if (num[j] - '0' == 7) {
                sevencount++;
            }
            if (num[j] - '0' == 2 && j != 0) {
                twocount++;
            }
            if (num[j] - '0' == 5 && j != 0) {
                fivecount++;
            }
        }
        if (exitloop) continue;

        if (threecount > 1) {
            cout << 2 << "\n" << 33 << "\n";
            continue;
        }
        if (sevencount > 1) {
            cout << 2 << "\n" << 77 << "\n";
            continue;
        }
        if (twocount) {
            cout << 2 << "\n" << num[0] << 2 << "\n";
            continue;
        }
        if (fivecount) {
            cout << 2 << "\n" << num[0] << 5 << "\n";
            continue;
        }
        if (num[0] - '0' == 2) {
            cout << 2 << "\n" << 27 << "\n";
        }
        else {
            cout << 2 << "\n" << 57 << "\n";
        }
    }
}