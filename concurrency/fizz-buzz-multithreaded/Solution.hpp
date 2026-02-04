// https://leetcode.com/problems/fizz-buzz-multithreaded/
#include <functional>
#include <semaphore>

using namespace std;

class FizzBuzz
{
private:
    int n;

public:
    FizzBuzz(int n)
    {
        this->n = n;
        init();
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz)
    {
        for (int i = 3; i <= n; i += 3)
        {
            if (i % 5 == 0)
                continue;
            sem_fizz.acquire();
            printFizz();
            release(i + 1);
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz)
    {
        for (int i = 5; i <= n; i += 5)
        {
            if (i % 3 == 0)
                continue;
            sem_buzz.acquire();
            printBuzz();
            release(i + 1);
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz)
    {
        for (int i = 15; i <= n; i += 15)
        {
            sem_fizzbuzz.acquire();
            printFizzBuzz();
            release(i + 1);
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber)
    {
        for (int i = 1; i <= n; i++)
        {
            if (i % 3 == 0 || i % 5 == 0)
                continue;
            sem_number.acquire();
            printNumber(i);
            release(i + 1);
        }
    }

private:
    binary_semaphore sem_fizz{0};
    binary_semaphore sem_buzz{0};
    binary_semaphore sem_fizzbuzz{0};
    binary_semaphore sem_number{0};

    void init() { release(1); }

    void release(int index)
    {
        if (index <= 0 || index > n)
            return;
        if (index % 15 == 0)
        {
            sem_fizzbuzz.release();
        }
        else if (index % 5 == 0)
        {
            sem_buzz.release();
        }
        else if (index % 3 == 0)
        {
            sem_fizz.release();
        }
        else
        {
            sem_number.release();
        }
    }
};