// https://leetcode.com/problems/the-dining-philosophers/
#include <vector>
#include <functional>
#include <semaphore>

using namespace std;

class DiningPhilosophers
{
public:
    DiningPhilosophers()
    {
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork)
    {
        getForks(philosopher, pickLeftFork, pickRightFork);
        eat();
        putForks(philosopher, putLeftFork, putRightFork);
    }

private:
    counting_semaphore<4> eating_queue_{4};
    binary_semaphore forks_[5] = {binary_semaphore(1), binary_semaphore(1), binary_semaphore(1), binary_semaphore(1), binary_semaphore(1)};

    int left(int philosopher)
    {
        return philosopher;
    }

    int right(int philosopher)
    {
        return (philosopher + 1) % 5;
    }

    void getForks(int philosopher, function<void()> pickLeftFork, function<void()> pickRightFork)
    {
        eating_queue_.acquire();
        forks_[left(philosopher)].acquire();
        // why the LeetCode testcase fails if I put `pickLeftFork();` here?
        forks_[right(philosopher)].acquire();
        pickLeftFork();
        pickRightFork();
    }

    void putForks(int philosopher, function<void()> putLeftFork, function<void()> putRightFork)
    {
        putLeftFork();
        putRightFork();
        forks_[left(philosopher)].release();
        // why the LeetCode testcase fails if I put `putRightFork();` here?
        forks_[right(philosopher)].release();
        eating_queue_.release();
    }
};
