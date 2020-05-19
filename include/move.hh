#ifndef MOVE_HH
#define MOVE_HH

#include <chrono>
#include <string>
#include <ctime>
#include <iostream>
#include <utility>
#include <vector>

class move
{
public:
    struct params
    {
        int integervalue;
        double doublevalue;
        int castedvalue;
        /* data */
    };

public:
    int intValue;
    double dbValue;
    int castedVariable;

public:
    move();
    template <typename T>
    move(T &&);

public:
    static void time();
    params showClass();
};

//Shows the current date and time in human readable format.
void move::time()
{
    auto now = std::chrono::system_clock::now();
    std::time_t unixdate = std::chrono::system_clock::to_time_t(now);
    std::cout << std::ctime(&unixdate) << "\n";
}

move::move()
{
    this->intValue = 69;
    this->dbValue = 69.69;
}

template <typename T>
move::move(T &&arg)
{
    // move();
    this->intValue = 69;
    this->dbValue = 69.69;
    this->castedVariable = std::move(arg);
    move()
    {
        this->intValue = 69;
        this->dbValue = 69.69;
        this->castedVariable = std::move(arg);
    }
}

move::params move::showClass()
{
    std::cout << "The move class containes the following values"
              << "\n";
    std::cout << this->intValue << " " << this->dbValue << " and the casted value: " << this->castedVariable;
    std::cout << "\n";
    params result();
    return result;
}
#endif // MOVE_HH
