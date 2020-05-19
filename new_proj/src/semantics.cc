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

int returnValue()
{
    return 5;
}

int main()
{
    // semantics::Semantics x = semantics::Semantics();
    int x; //lvalue
    x = 1;
    const int cx = 1;
    // int&y=returnValue(); //doesn't work since y is an l-value reference and it only binds to lvalues

    const int &ry = returnValue(); //it works since const references can bind to both lvalues and rvalues
    //it extends the life-time of @returnValue until the next scope.
    //! no modification on this rvalue can be further executed

    //rvalue references
    int &&rvalue = returnValue(); //this only binds to r-values
    //  int &&new_rvalue = cx; ! Doesn't work since rvalue references only bind to rvalues

    rvalue = ry;
    std::cout << rvalue;
    std::cout << std::endl;
}