// CommonDivisors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int num, tmp;
    cin >> num;
    int maximum = 0;
    int maxnum = 0;
    
    vector<int> divisors(1000000,0);

    for (int i = 0; i < num; i++) {
        cin >> tmp;
        divisors[tmp] ++;
        maxnum = max(maxnum, tmp);
    }

    for (int i = maxnum; i > 0; i--) {
        tmp = 0;
        for (int j = 1; j <= maxnum / i; j++) {
            tmp += divisors[i * j];
        }
        if (tmp > 1) {
            cout << i;
            break;
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
