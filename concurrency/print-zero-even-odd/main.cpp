#include <iostream>
#include <thread>
#include "Solution.hpp"

using namespace std;

string printed;

void clearPrinted()
{
    printed.clear();
}

void printNumber(int x)
{
    printed += to_string(x);
}

bool checkZeroEvenOdd(int n, string &message)
{
    clearPrinted();
    ZeroEvenOdd zeo(n);
    thread t1(&ZeroEvenOdd::zero, &zeo, printNumber);
    thread t2(&ZeroEvenOdd::even, &zeo, printNumber);
    thread t3(&ZeroEvenOdd::odd, &zeo, printNumber);
    t1.join();
    t2.join();
    t3.join();

    string expected;
    for (int i = 1; i <= n; ++i)
    {
        expected += "0" + to_string(i);
    }

    message = "n = " + to_string(n) + "\n";
    message += "printed:  " + printed + "\n";
    message += "expected: " + expected + "\n";
    message += (printed == expected ? "PASS\n" : "FAIL\n");
    return printed == expected;
}

int main()
{
    int n = 0;
    while (cin >> n)
    {
        if (n <= 0)
            break;
        string message;
        bool result = checkZeroEvenOdd(n, message);
        cout << message << endl;
    }

    return 0;
}