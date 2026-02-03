#include <iostream>
#include <thread>
#include "Solution.hpp"

using namespace std;

void releaseHydrogen()
{
    cout << "H" << flush;
}

void releaseOxygen()
{
    cout << "O" << flush;
}

bool validateInput(const string &input)
{
    int h_counter = 0;
    int o_counter = 0;
    for (char c : input)
    {
        if (c == 'H')
            h_counter++;
        else if (c == 'O')
            o_counter++;
        else
            return false;
    }
    return h_counter == o_counter * 2;
}

int main()
{
    string input;
    while (cin >> input)
    {
        if (!validateInput(input))
        {
            cout << "Invalid input. The number of H must be twice the number of O." << endl;
            continue;
        }

        H2O h2o;
        vector<thread> threads;
        for (char c : input)
        {
            switch (c) {
            case 'H':
                threads.emplace_back(&H2O::hydrogen, &h2o, releaseHydrogen);
                break;
            case 'O':
                threads.emplace_back(&H2O::oxygen, &h2o, releaseOxygen);
                break;
            default:
                break;
            }
        }

        for (auto &&t : threads)
        {
            t.join();
        }

        cout << "\n" << endl;
    }

    return 0;
}