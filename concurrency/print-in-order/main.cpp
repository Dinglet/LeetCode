#include <iostream>
#include <thread>
#include "Solution.hpp"

using namespace std;

void printFirst() { cout << "first"; }
void printSecond() { cout << "second"; }
void printThird() { cout << "third"; }
int main()
{
    Foo foo;
    thread t1([&]()
              { foo.first(printFirst); });
    thread t3([&]()
              { foo.third(printThird); });
    thread t2([&]()
              { foo.second(printSecond); });

    t1.join();
    t2.join();
    t3.join();

    return 0;
}