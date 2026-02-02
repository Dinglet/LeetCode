#include <iostream>
#include <thread>
#include "Solution.hpp"

using namespace std;

void printFoo()
{
    cout << "foo";
}

void printBar()
{
    cout << "bar";
}

int main()
{
    int n = 0;
    while (cin >> n)
    {
        FooBar foobar(n);
        thread t1(&FooBar::foo, &foobar, printFoo);
        thread t2(&FooBar::bar, &foobar, printBar);
        t1.join();
        t2.join();
    }

    return 0;
}