#include "../include/semantics.hh"

inline void line() { std::cout << "\n"; }

semantics::Semantics::Semantics()
{
    std::cout << "01";
    line();
}

semantics::Semantics::~Semantics()
{
    std::cout << "00";
    line();
}

int main()
{
    semantics::Semantics x = semantics::Semantics();
    // x.~Semantics();
}