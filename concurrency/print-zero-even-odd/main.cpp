#include <iostream>
#include <thread>
#include "Solution.hpp"

using namespace std;

void printNumber(int x)
{
    cout << x;
}

int main()
{
    int n = 0;
    while (cin >> n)
    {
        if (n <= 0)
            break;
        ZeroEvenOdd zeo(n);
        thread t1(&ZeroEvenOdd::zero, &zeo, printNumber);
        thread t2(&ZeroEvenOdd::even, &zeo, printNumber);
        thread t3(&ZeroEvenOdd::odd, &zeo, printNumber);
        t1.join();
        t2.join();
        t3.join();

        cout << endl;
    }

    return 0;
}