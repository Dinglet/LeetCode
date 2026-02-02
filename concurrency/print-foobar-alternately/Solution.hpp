// https://leetcode.com/problems/print-foobar-alternately/

#include <semaphore>
#include <functional>

using namespace std;

class FooBar {
private:
    int n;
    binary_semaphore bar_done{1};
    binary_semaphore foo_done{0};

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {

        for (int i = 0; i < n; i++) {
            bar_done.acquire();
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            foo_done.release();
        }
    }

    void bar(function<void()> printBar) {

        for (int i = 0; i < n; i++) {
            foo_done.acquire();
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            bar_done.release();
        }
    }
};