// https://leetcode.com/problems/print-in-order/
#pragma once

#include <semaphore>
#include <functional>

using namespace std;

class Foo {
    binary_semaphore first_done{0};
    binary_semaphore second_done{0};
public:
    Foo() {
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        first_done.release();
    }

    void second(function<void()> printSecond) {
        first_done.acquire();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        second_done.release();
    }

    void third(function<void()> printThird) {
        second_done.acquire();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};