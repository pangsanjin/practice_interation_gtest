//
// Created by yanciliu on 2019/8/19.
//
#include <iostream>
#include "../deps/googletest/googletest/include/gtest/gtest.h"

using namespace std;

template<typename T>
class IsClassT {
private:
    typedef char One;
    typedef struct { char a[2]; } Two;
    template<typename C> static One test(int C::*);
    template<typename C> static Two test(...);
public:
    enum { Yes = sizeof(test<T>(0)) == 1 };
    enum { No = !Yes };
};


class MyClass {
};

struct MyStruct {
};

union MyUnion {
};

void myfunc()
{
}

enum E { e1 } e;

// check by passing type as template argument
template <typename T>
void check()
{
    if (IsClassT<T>::Yes) {
        std::cout << " IsClassT " << std::endl;
    }
    else {
        std::cout << " !IsClassT " << std::endl;
    }
}

// check by passing type as function call argument
template <typename T>
void checkT(T)
{
    check<T>();
}

TEST(is_class, t1)
{
    std::cout << "int:     ";
    check<int>();

    std::cout << "MyClass: ";
    check<MyClass>();

    std::cout << "MyStruct:";
    MyStruct s;
    checkT(s);

    std::cout << "MyUnion: ";
    check<MyUnion>();

    std::cout << "enum:    ";
    checkT(e);

    std::cout << "myfunc():";
    checkT(myfunc);
}