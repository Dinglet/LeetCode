#include <iostream>
#include <thread>
#include "Solution.hpp"

using namespace std;

void releaseCarbon()
{
    cout << "C" << flush;
}

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
    int c_counter = 0;
    int h_counter = 0;
    int o_counter = 0;
    for (char c : input)
    {
        switch (c) {
        case 'C':
            c_counter++;
            break;
        case 'H':
            h_counter++;
            break;
        case 'O':
            o_counter++;
            break;
        default:
            break;
        }
    }
    return (h_counter == 4 * c_counter) && (o_counter == c_counter);
}

int main()
{
    string input;
    while (cin >> input)
    {
        if (!validateInput(input))
        {
            cout << "Invalid input." << endl;
            continue;
        }

        CH3OH compound;
        vector<thread> threads;
        for (char c : input)
        {
            switch (c) {
            case 'C':
                threads.emplace_back(&CH3OH::carbon, &compound, releaseCarbon);
                break;
            case 'H':
                threads.emplace_back(&CH3OH::hydrogen, &compound, releaseHydrogen);
                break;
            case 'O':
                threads.emplace_back(&CH3OH::oxygen, &compound, releaseOxygen);
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