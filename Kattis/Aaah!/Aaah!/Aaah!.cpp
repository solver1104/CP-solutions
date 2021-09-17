// Aaah!.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

vector<long long> extended_euclid_gcd(long long a, long long b) {
    long long s = 0; long long old_s = 1;
    long long t = 1; long long old_t = 0;
    long long r = b; long long old_r = a;

    while (r != 0) {
        long long quotient = old_r / r;
        long long temp = r;
        r = old_r - quotient * r;
        old_r = temp;
        temp = s;
        s = old_s - quotient * s;
        old_s = temp;

        temp = t;
        t = old_t - quotient * t;
        old_t = temp;
    }
    vector<long long> result;
    result.push_back(old_r);
    result.push_back(old_s);
    result.push_back(old_t);
    return result;
}

long long modulo_multiplicative_inverse(long long A, long long M) {
    vector<long long> v = extended_euclid_gcd(A, M);
    long long gcd = v[0];
    long long x = v[1];
    long long y = v[2]; 
    if (x < 0) {
        x += M;
    }
    return x;
}

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a == b)
        return a;
    if (a > b)
        return gcd(a - b, b);
    return gcd(a, b - a);
}


int main()
{
	long long int t1, t2, p1, p2, tmp1, tmp2, tmp3;
	char tmp;
	cin >> tmp1 >> tmp >> tmp2;
	t1 = tmp1 * 60 + tmp2;
	cin >> tmp1 >> tmp >> tmp2;
	t2 = tmp1 * 60 + tmp2;
	cin >> tmp1 >> tmp >> tmp2;
	p1 = tmp1 * 60 + tmp2;
	cin >> tmp1 >> tmp >> tmp2;
	p2 = tmp1 * 60 + tmp2;

	tmp3 = gcd(gcd(gcd(t1, t2), p1), p2);
	t2 = t2 / tmp3;
	t1 = t1 / tmp3;
	p1 = p1 / tmp3;
	p2 = p2 / tmp3;

	if ((t1 - t2) % gcd(p1,p2) || p1 == p2) {
		cout << "Never";
	}
	else {
        tmp2 = ((t1 - t2) * modulo_multiplicative_inverse(p2 % p1, p1)) % p1;
        if (tmp2 < 0) {
            tmp2 += p1;
        }
		tmp1 = (t2 + p2 * (tmp2))*tmp3;
        tmp1 = tmp1 % 10080;

        if (tmp1 < 1440) {
            cout << "Saturday" << "\n";
            cout << std::setfill('0') << std::setw(2) << tmp1 / 60;
            cout << ":";
            cout << std::setfill('0') << std::setw(2) << tmp1 % 60;
        }
        else if (tmp1 < 2880) {
            cout << "Sunday" << "\n";
            cout << std::setfill('0') << std::setw(2) << (tmp1 - 1440) / 60;
            cout << ":";
            cout << std::setfill('0') << std::setw(2) << (tmp1 - 1440) % 60;
        }
        else if (tmp1 < 4320){
            cout << "Monday" << "\n";
            cout << std::setfill('0') << std::setw(2) << (tmp1 - 2880) / 60;
            cout << ":";
            cout << std::setfill('0') << std::setw(2) << (tmp1 - 2880) % 60;
        }
        else if (tmp1 < 5760) {
            cout << "Tuesday" << "\n";
            cout << std::setfill('0') << std::setw(2) << (tmp1 - 4320) / 60;
            cout << ":";
            cout << std::setfill('0') << std::setw(2) << (tmp1 - 4320) % 60;
        }
        else if (tmp1 < 7200) {
            cout << "Wednesday" << "\n";
            cout << std::setfill('0') << std::setw(2) << (tmp1-5760) / 60;
            cout << ":";
            cout << std::setfill('0') << std::setw(2) << (tmp1-5760) % 60;
        }
        else if (tmp1 < 8640) {
            cout << "Thursday" << "\n";
            cout << std::setfill('0') << std::setw(2) << (tmp1-7200) / 60;
            cout << ":";
            cout << std::setfill('0') << std::setw(2) << (tmp1-7200) % 60;
        }
        else {
            cout << "Friday" << "\n";
            cout << std::setfill('0') << std::setw(2) << (tmp1-8640) / 60;
            cout << ":";
            cout << std::setfill('0') << std::setw(2) << (tmp1-8640) % 60;
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
