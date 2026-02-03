// a variation of https://leetcode.com/problems/building-h2o/
#pragma once

#include <functional>
#include <semaphore>
#include <barrier>

using namespace std;

class CH3OH
{
public:
    CH3OH()
    {
    }

    void carbon(function<void()> releaseCarbon)
    {
        bool owns_mutex = false;
        mutex_.acquire();
        // only one thread can be here at a time
        carbon_counter_ += 1;
        if (canBoundMolecule())
        {
            // release signals for enough atoms
            releaseAtomsInQueues();
            owns_mutex = true;
        }
        else
        {
            mutex_.release();
        }

        // acquire a signal for enough atoms
        carbon_queue_.acquire();
        releaseCarbon();

        barrier_.arrive_and_wait();
        if (owns_mutex)
            mutex_.release();
    }

    void hydrogen(function<void()> releaseHydrogen)
    {
        bool owns_mutex = false;
        mutex_.acquire();
        // only one thread can be here at a time
        hydrogen_counter_ += 1;
        if (canBoundMolecule())
        {
            // release signals for enough atoms
            releaseAtomsInQueues();
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
        if (canBoundMolecule())
        {
            releaseAtomsInQueues();
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
    binary_semaphore mutex_{1};
    int carbon_counter_ = 0;
    int oxygen_counter_ = 0;
    int hydrogen_counter_ = 0;

    counting_semaphore<1> carbon_queue_{0};
    counting_semaphore<1> oxygen_queue_{0};
    counting_semaphore<4> hydrogen_queue_{0};

    // DO NOT use a complete function to release the mutex here
    // because the complete function runs before all the three threads are unblocked.
    // In this case, the barrier may not be ready for the next phase.
    barrier<> barrier_{6};

    bool canBoundMolecule()
    {
        return (carbon_counter_ >= 1) && (oxygen_counter_ >= 1) && (hydrogen_counter_ >= 4);
    }

    void releaseAtomsInQueues()
    {
        carbon_queue_.release(1);
        carbon_counter_ -= 1;
        oxygen_queue_.release(1);
        oxygen_counter_ -= 1;
        hydrogen_queue_.release(4);
        hydrogen_counter_ -= 4;
    }
};