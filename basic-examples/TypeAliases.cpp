#include <iostream>

using namespace std;

/* THIS PIECE IS TAKEN FROM STACKOVERFLOW TO PRINT TYPES */
#include <type_traits>
#include <typeinfo>
#ifndef _MSC_VER
#   include <cxxabi.h>
#endif
#include <memory>
#include <string>
#include <cstdlib>

template <class T>
std::string
type_name()
{
    typedef typename std::remove_reference<T>::type TR;
    std::unique_ptr<char, void(*)(void*)> own
           (
#ifndef _MSC_VER
                abi::__cxa_demangle(typeid(TR).name(), nullptr,
                                           nullptr, nullptr),
#else
                nullptr,
#endif
                std::free
           );
    std::string r = own != nullptr ? own.get() : typeid(TR).name();
    if (std::is_const<TR>::value)
        r += " const";
    if (std::is_volatile<TR>::value)
        r += " volatile";
    if (std::is_lvalue_reference<T>::value)
        r += "&";
    else if (std::is_rvalue_reference<T>::value)
        r += "&&";
    return r;
}
/* ------------------------------------------------------------ */

void constAndTypeAliases();

// Old way (still valid)
typedef double wages; // wages is a synonym of double now.
typedef wages base, *wage_p; // base also now is a synonym of wages, and wage_p is a wages*

// From C++ 11 on
using euro = int;


int main() {
    double d;
    wages w;
    base b;
    wage_p pointer;

    cout << type_name<decltype(d)>() << endl;
    cout << type_name<decltype(w)>() << endl;
    cout << type_name<decltype(b)>() << endl;
    cout << type_name<decltype(pointer)>() << endl;

    constAndTypeAliases();

    return 0; 
}

/**
 * @brief To be remembered: it is not possible to just substitute the alias with the original one
 * Because there is the compiler that checks stuff.
 * 
 * @return int 
 */
void constAndTypeAliases() {
    
    wages content = 42;
    wages anotherContent = 30;
    // this is the declaration of a constant pointer, not a pointer to const.
    const wage_p pointer = &content; 
    // not legal to do: pointer = &anotherContent;
    
    // this is a pointer to a const pointer
    const wage_p *pointerToPointer;

}
