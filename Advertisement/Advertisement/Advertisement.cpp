// Advertisement.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>

using namespace std;

int main()
{
    long long int n, tmp;
    long long int maximum = 0;
    pair<long long int, long long int> temp, temp1;
    cin >> n;

    stack<pair<long long int, long long int>> x;
    cin >> tmp;
    temp.first = tmp;
    temp.second = 0;
    x.push(temp);
    for (int i = 1; i < n; i++) {
        cin >> tmp;
        while (x.top().first > tmp) {
            temp1 = x.top();
            maximum = max(maximum, temp1.first * (i - temp1.second));
            x.pop();
            if (x.empty()) {
                break;
            }
        }
        temp.second = temp1.second;
        temp.first = tmp;
        x.push(temp);
        temp1.second = i + 1;
    }
    while (!x.empty()) {
        temp1 = x.top();
        maximum = max(maximum, temp1.first * (n - temp1.second));
        x.pop();
    }
    cout << maximum;
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
