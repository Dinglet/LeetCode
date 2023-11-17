#include <set>

using namespace std;

class SeatManager
{
public:
    SeatManager(int n)
    {
        for (int i = 1; i <= n; i++)
            unreservedSeats.insert(i);
    }
    
    int reserve()
    {
        return popUnreservedSeat();
    }
    
    void unreserve(int seatNumber)
    {
        pushUnreservedSeat(seatNumber);
    }
private:
    set<int> unreservedSeats;
    int popUnreservedSeat()
    {
        int seatNumber = *unreservedSeats.begin();
        unreservedSeats.erase(unreservedSeats.begin());
        return seatNumber;
    }
    void pushUnreservedSeat(int seatNumber)
    {
        unreservedSeats.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */