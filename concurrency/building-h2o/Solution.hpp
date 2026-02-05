// https://leetcode.com/problems/building-h2o/
//
// My solution is based on the content of Section 5.6 of The Little Book of Semaphores.
//
// I think a more clear solution is the one posted by deirh on LeetCode:
// <https://leetcode.com/problems/building-h2o/solutions/5463051/2-semaphores-barrier-finally-a-useful-ap-9yep>
#pragma once

#include <functional>
#include <semaphore>
#include <barrier>

using namespace std;

class H2O
{
public:
    H2O()
    {
    }

    void hydrogen(function<void()> releaseHydrogen)
    {
        bool owns_mutex = false;
        mutex_.acquire();
        // only one thread can be here at a time
        hydrogen_counter_ += 1;
        if (hydrogen_counter_ >= 2 && oxygen_counter_ >= 1)
        {
            // release signals for enough atoms
            hydrogen_queue_.release(2);
            hydrogen_counter_ -= 2;
            oxygen_queue_.release(1);
            oxygen_counter_ -= 1;

            owns_mutex = true;
        }
        else
        {
            mutex_.release();
        }

        // acquire a signal for enough atoms
        hydrogen_queue_.acquire();
        releaseHydrogen();

        barrier_.arrive_and_wait();
        if (owns_mutex)
            mutex_.release();
    }

    void oxygen(function<void()> releaseOxygen)
    {
        bool owns_mutex = false;
        mutex_.acquire();
        // only one thread can be here at a time
        oxygen_counter_ += 1;
        if (hydrogen_counter_ >= 2 && oxygen_counter_ >= 1)
        {
            // release signals for enough atoms
            hydrogen_queue_.release(2);
            hydrogen_counter_ -= 2;
            oxygen_queue_.release(1);
            oxygen_counter_ -= 1;

            owns_mutex = true;
        }
        else
        {
            mutex_.release();
        }

        // wait for the signal of enough atoms
        oxygen_queue_.acquire();
        releaseOxygen();

        barrier_.arrive_and_wait();
        if (owns_mutex)
            mutex_.release();
    }

private:
    // Water building hint, 5.6 Building H2O, The Little Book of Semaphores.
    binary_semaphore mutex_{1};
    int oxygen_counter_ = 0;
    int hydrogen_counter_ = 0;

    counting_semaphore<1> oxygen_queue_{0};
    counting_semaphore<2> hydrogen_queue_{0};

    // DO NOT use a complete function to release the mutex here
    // because the complete function runs before all the three threads are unblocked.
    // In this case, the barrier may not be ready for the next phase,
    // and you will see a data race reported by ThreadSanitizer if you use it.
    // ```bash
    // g++ -std=c++20 -fsanitize=thread -g -O1 -o main main.cpp
    // ``
    barrier<> barrier_{3};
};