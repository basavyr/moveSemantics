#include <vector>
#include <utility>
#include <iostream>

inline void line()
{
    std::cout << '\n';
}

//* move semantics from YT video:   https://www.youtube.com/watch?v=dcgqUb1SXPk

//live demo on C++11's move semantics

//create a simple structure

struct My_Struct
{
    My_Struct() = default;
    My_Struct(int p) : p(new int(p)){};
    My_Struct(My_Struct &a_struct)
    {
        if (a_struct.p != nullptr)
        {
            p = new int(*a_struct.p); //copies the resource to another address
        }
    }
    //implement the assignment operator
    My_Struct &operator=(My_Struct const &a_struct) //? this is an l-value reference
    {
        if (a_struct.p != nullptr)
        {
            p = new int(*a_struct.p); //makes a second heap allocation for assignment
        }
        return *this;
    }
    My_Struct &operator=(My_Struct &a_struct)
    {
        if (a_struct.p != nullptr)
        {
            // p = new int(*a_struct.p); //! avoids making a copy of a_struct
            p = a_struct.p;       //? it points to a_struct
            a_struct.p = nullptr; //steal the ownership
        }
        return *this;
    }
    My_Struct &operator=(My_Struct &&a_struct) //?r-value reference
    {
        if (a_struct.p != nullptr)
        {
            // p = new int(*a_struct.p); //! avoids making a copy of a_struct
            p = a_struct.p;       //? it points to a_struct
            a_struct.p = nullptr; //steal the ownership
        }
        return *this;
    }
    ~My_Struct() //destructor
    {
        if (p != nullptr)
        {
            delete p;
            p = nullptr;
        }
    }
    int *p = nullptr;
};

void FunctionByValue(My_Struct value);          //value semantics -> copy
void FunctionByReference(My_Struct &ref_value); //reference semantics

static int my_number = 69;

//a function that return a prvalue
int returnrpv()
{
    return 33;
}

//*part 1 of tutorial
// int main()
// {
//     int prv = returnrpv(); //?prvalue
//     int another_prv = 69;  //prvalue
//     My_Struct s1;
//     {
//         // s1.p = new int(41); //this is doing heap allocation -> ! expensive
//         // My_Struct s2(s1); //this is a temporary work

//         // My_Struct s2; //temporary object
//         // s2.p = new int(my_number);
//         // s1 = std::move(s2); //!problem here: two heap allocation    first and second is in assignment operator <------ x value
//         // //? s1 becomes a copy of s2, s2 being a temp object

//         //*prvalue
//         s1 = My_Struct(69);//ravlue reference //? prvalue: it is a temporary
//         std::cout << *s1.p;
//     }
//     line();
// }

//?part 2 of tutorial

struct Another_Struct
{
    std::vector<int> __v;
    //other data
    // Another_Struct(std::vector<int> &&v) : __v(v)
    // {
    //     //possible to use v.push_back()
    //     //working with v is safe
    // } //v is actually in lvalue inside the scope of this function
    //! even though v is passed as an rvalue referece, the vector __v must be constructed with std::move(v) in order for proper resource stealing
    //? the optimal way
    Another_Struct(std::vector<int> &&v) : __v(std::move(v))
    {
        //some operations
    }
};

void FillVector(std::vector<int> &v)
{
    //conditionally fill the vector
}

int main()
{
    // std::vector<int> v;
    // {
    //     std::vector<int> v2 = {1, 2, 3};
    //     // v=v2 //! allocates a second set of resources on the heap for generating v1 by copying v2 into it
    //     v = std::move(v2); //*avoids the extra copying on the heap of v2
    // }
    std::vector<int> v;
    FillVector(v);
    //if v is not empty, fill a Another_Struct vector
    if (!v.empty())
    {
        Another_Struct v1(std::move(v)); //v1 steals resources of v
        //v will be in a valid bun unspecified v
        //cannot use v
        v.clear(); //works (it doesn't depend on the state)
    }
}