#include <iostream>
#include <vector>
#include <string>

inline void line() { std::cout << '\n'; }

std::string giveText()
{
    return "This is an r-value"; //this is stored in memory only in the actual line of code
}

void printer(const std::string &s)
{
    std::cout << s;
    line();
}

void DoSomething(int &a)
{
    std::cout << "In L-value reference.";
    line();
}

void DoSomething(int &&a)
{
    std::cout << "In R-Value reference.";
    line();
}

int main()
{
    std::string s = giveText();
    int v = 1;
    std::cout << v;
    line();
    DoSomething(std::move(v));
    std::cout << v;
    line();
    // printer(s);
}
