// https://leetcode.com/problems/design-circular-queue/

#include <memory>

using namespace std;

class MyCircularQueue
{
public:
    MyCircularQueue(int k) : queue_(new int[k])
    {
        if (queue_ != nullptr)
            capacity_ = k;
    }

    bool enQueue(int value)
    {
        if (isFull())
            return false;
        ++size_;
        queue_[end_] = value;
        if (++end_ == capacity_)
            end_ = 0;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
            return false;
        --size_;
        if (++begin_ == capacity_)
            begin_ = 0;
        return true;
    }

    int Front()
    {
        if (isEmpty())
            return -1;
        return queue_[begin_];
    }

    int Rear()
    {
        if (isEmpty())
            return -1;
        return queue_[(end_ ? end_ : capacity_) - 1];
    }

    bool isEmpty() { return size_ == 0; }

    bool isFull() { return size_ == capacity_; }

private:
    unique_ptr<int[]> queue_ = nullptr;
    int capacity_ = 0;
    int size_ = 0;
    int begin_ = 0, end_ = 0;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */