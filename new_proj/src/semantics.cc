#include "../include/semantics.hh"
#include <utility>
#include <cstring>
#include <vector>

inline void line() { std::cout << "\n"; }

template <typename T>
static void show_vector(std::vector<T> &v)
{
    for (auto &&n : v)
    {
        std::cout << n << " ";
    }
    line();
}

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

std::string returnString() { return "returned string!"; }

//create a function that return a vector without copying each element
std::vector<int> make_vector(size_t n)
{
    std::vector<int> v(n);
    v.at(static_cast<int>(n / 2)) = 69;
    //avoids copying n elements in this function
    //usually returning by value will copy v;
    return std::move(v);
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
    // int &ry2 = returnValue(); does not work hence the const missing
    //rvalue references
    int &&rvalue = returnValue(); //this  binds to r-values and l-values
    //  int &&new_rvalue = cx; ! Doesn't work since rvalue references only bind to rvalues

    //! STD::MOVE

    std::string s("Darwin");

    std::string s_copy(s); //copies the string s using a standard copy constructor

    std::string extra(returnString()); //optimizations can make this work in C++98 or NOT
    //!*in c++11 this will always be a move
    //the returnString is never constructed on the heap, then copied, then destroyed. the string extra directly "seals" its resources.

    //! create a move constructor that leaves the temporary object in a VALID state
    // delete constructor can delete a pointer to some "garbage" address if move constructor is not allocated with a proper 0 size and nullptr vector

    //*std::move impl

    std::vector<int> v1(1000);
    std::cout << &v1;
    line();
    std::cout << v1.size();
    line();
    show_vector<int>(v1);
    line();

    //...

    // one wants to move the vector v1 to another place (a new vector)

    std::vector<int> new_vector(v1);
    //!if this is the last tie we want to use the initial vector v1, it is OK to use the move constructor
    std::cout << "after move";
    line();
    std::vector<int> v1_reborn(std::move(v1));

    //never refer to v1 after it is moved!

    std::cout << v1.size();
    line();
    std::cout << &v1;
    line();

    //rvalue references NEVER bind to lvalue references (lvalues)

    //* in this case, v1 keeps the same address but it changes the size of the array
    show_vector<int>(v1);
    line();
    // show_vector<int>(new_vector);

    std::cout << extra;
    line();
}