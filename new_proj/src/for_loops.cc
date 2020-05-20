#include <iostream>
#include <vector>
#include <string>
#include <map>
inline void line() { std::cout << '\n'; }

//? based on the tutorial: https://www.youtube.com/watch?v=RfoCIuyrfWs

// C-array
static int c_arr[] = {1, 2, 3, 4};
//in functions, arrays are passed as pointers
// iterate with an index through the array: for(int i)
// iterate with the help of a pointer

//C++98 containers
std::vector<int> my_vector{1, 2, 3, 4};
//dynamically allocated array
//implements iterators (same concept as C-like pointer iterator)

void show_element(int &elem)
{
    std::cout << std::move(elem);
    line();
}

int main()
{
    // int *p = c_arr;
    // std::cout << *p;
    // line();
    // c_arr[0] = 0;
    // std::cout << *p;
    // line();

    for (std::vector<int>::iterator it = my_vector.begin(); it != my_vector.end(); ++it)
    {
        // std::cout << *(it);
        // line();
    }

    for (uint8_t id = 0; id < my_vector.size(); ++id)
    {
        int c_v = my_vector.at(id);
        // show_element(c_v);
        // std::cout << c_v;
        // line();
    }

    for (std::vector<int>::iterator it = my_vector.begin(); it != my_vector.end(); ++it)
    {
        // std::cout << *(it);
        // line();
    }

    //!range based for loops
    //C++11

    for (int i : my_vector)
    {
        // show_element(static_cast<int &&>(i)); // this works since a cast to an rvalue will bind to the rvalue reference which is required for the show function
    }
    //string vector
    std::vector<std::string> strings = {"x", "y", "robert"};

    // for (auto s : strings) //works (copying each element from strings into scope{})
    for (const auto &s : strings) //works (taking s by reference)
    // for (auto &&s : strings) //works (taking by rvalue reference)
    // for (const auto &&s : strings) //!doesnt work, since cannot bind an lvalue to an rvalue reference
    {
        // s += "2"; cannot modify const references
        std::cout << s << ' ';
    }

    std::map<int, std::string> a_map{std::make_pair(1, "S")};

    // for (auto &&a_pair : a_map)
    // for (const std::pair<int, std::string> &a_pair : a_map)
    // for (std::pair<const int, std::string> &a_pair : a_map)//?works since the int is taken a const  ref
    for (std::pair<int, std::string> a_pair : a_map) //!doesn't work since  (not const-qualified) cannot be initialized with a value of type "std::__1::pair<const int, std::__1::string>"
    //pair has both as const
    {
        std::cout << a_pair.first << " " << a_pair.second;
    }

    line();
}