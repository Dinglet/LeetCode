#include <iostream>
#include <thread>
#include "Solution.hpp"

using namespace std;

void pickLeftFork() {}
void pickRightFork() {}
void eat() {}
void putLeftFork() {}
void putRightFork() {}

int main()
{
    int n = 0;
    cin >> n;
    if (n <= 0)
    {
        return 0;
    }
    DiningPhilosophers dp;
    vector<thread> threads;
    while (n--)
    {
        for (int i = 0; i < 5; ++i)
        {
            threads.emplace_back(&DiningPhilosophers::wantsToEat,
                                    &dp,
                                    i,
                                    pickLeftFork,
                                    pickRightFork,
                                    eat,
                                    putLeftFork,
                                    putRightFork);
        }
    }
    for (auto &t : threads)
    {
        t.join();
    }
    return 0;
}