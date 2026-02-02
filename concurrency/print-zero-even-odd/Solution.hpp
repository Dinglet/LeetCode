// https://leetcode.com/problems/print-zero-even-odd/
#pragma once

#include <semaphore>
#include <functional>

using namespace std;

class ZeroEvenOdd {
private:
    int n;
    binary_semaphore sem_print_zero{1};
    binary_semaphore sem_print_odd{0};
    binary_semaphore sem_print_even{0};

public:
    ZeroEvenOdd(int n) { this->n = n; }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 1; i <= n; ++i) {
            sem_print_zero.acquire();
            printNumber(0);
            if (i & 1) {
                sem_print_odd.release();
            } else {
                sem_print_even.release();
            }
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            sem_print_odd.acquire();
            printNumber(i);
            sem_print_zero.release();
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            sem_print_even.acquire();
            printNumber(i);
            sem_print_zero.release();
        }
    }
};