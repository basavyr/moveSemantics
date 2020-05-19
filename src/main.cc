#include "../include/move.hh"
#include <bits/stdc++.h> 
#include <iostream>

int main()
{
    move::time();
    double var = 3.33;
    std::cout << "the value of the local variable BEFORE the move operator " << var << "\n";
    move f1(var);
    std::cout << "the value of the local variable AFTER the move operator " << var << "\n";

    std::vector<int> v {1, 2, 3};
    std::cout << v.size() << "\n";
    std::vector<int> v0;
    v0 = std::move(v);
    std::cout << v.size() << "\n";

    double x = 1;
    std::string name = "robert";
    std::cout << "x 0 " << name << "\n";
    auto moved = std::move(x);
    std::cout << "x 0 " << name << "\n";
    std::cout << moved << " " << x << "\n";
    f1.showClass();
}
