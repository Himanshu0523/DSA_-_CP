#include<iostream>
#include<algorithm>
#include<memory>
#include<string>
using namespace std;


class MyClass {
    int x;
    string s;
    unique_ptr<int> p;

    public:
        // Error - Cannot use copy initialization in number initializer list 
        // MyClass() : x = 10 , s = "Hello" , p = std::make_unique<int>(){};

        // Correct - use direct or uniform initialization 
        MyClass() : x(10) , s("Hello") , p (make_unique<int>(3)){}

        // also correct with uniform initialization for base class constructor
        MyClass(int val) : x{val} , s{"direct"} , p{make_unique<int>(val)}{}
};


// Another example: Can't use copy initialization for base class constructors
class Base{
    int id;
    public:
        Base(int i) : id(i) {}
};

class Derived : public Base {
    public:
        // error
        // Derived() : Base = 100 {}

        // Correct
        Derived() : Base(100){}

        // Correct
        Derived(int x) : Base{x} {}
};

// Cannot use copy initialization in delegating constructors 
class Widget {
    int a , b;
    public:
        Widget(int x , int y) : a(x) , b(y) {}

        // Error
        // Widget() : widget = {1 ,2} {}

        // Correct
        Widget() : Widget(1 , 2) {}

        // Correct  uniform initialization
        Widget(int x) : Widget{x , x} {}
};


class ExplicitClass {
    public:
        int value;

        // Explicit Constructor
        explicit ExplicitClass(int v) : value(v) {
            std:cout << "Explicit Constructor called\n";
        }

        // non - explicit constructor
        ExplicitClass(double v): value(static_cast<int>(v)) {
            cout << "Implicit Constructor called\n";
        }
};


void takeExplicit(ExplicitClass obj){
    cout << "Fuction received: "<< obj.value << "\n";
}



int main() {

    int x1 = 10; // copy initialization
    int y(10); // Direct initialization
    int z{10}; // Uniform/list initialization
    int w = {10}; // Copy list initialization


    // Key Differences and Use cases
        // Copy Initialization (=)
            // creating a copy of an existing object
            //  Cannot used converts (constructor initializer lists)

// make_unique < TYPENAME > value;


    // 1. Implicit Conversions
        ExplicitClass obj1 = 3.14;

        // Explicit Conversion - can't be used with copy init
        // ExplicitClass obj2 = 10;

        ExplicitClass obj3(10); // direct init works with explicit constructor

        ExplicitClass onj4{10}; // uniform inti work with explicit constructor

    // 2. Function arguments
        takeExplicit(3.14); // implicit  conversion from double
        
        // takeExplicit(10); // can't convert int implicitly due to explicit constructor
        takeExplicit(ExplicitClass(3.14));


    // 3. Copy Initialization with narrowing (less strict)
    int x = 3.14; // copy init allows narrowing (truncates to 3)
    int y(3.14);
    // Prevents narrowing

    double d = 3.14;
    int z(d); // direct init allows narrowing

    // 4, Array initialization differences
    int arr1[] = {1 , 2 , 3.14}; // copy inti allows narrowing
    //int arr2[]{1 , 3, 3.14}; // error uniform init prevent narrowing

    // 5. Multiple-step conversions
    struct A {A(int) {}};
    struct B {B(A) {}};

    B objB1 = A(10);    // 2-step implicit conversion
    // B objB2 = 10;    // error - only one user - defined conversion allowed

    // 6. Smart pointers (explicit constructors)
    std::unique_ptr<int> ptr1(new int(5));  // Direct init
    // std::unique_ptr<int> ptr2 = new int(5); // Error - explicit constructor

    // 7. Copy initialization with different types
        std::string s1 = "test"; // implicit conversion from const char
        std::string s2 = s1; // copy constructor

        // std::string s3 = 'A';
        // No implicit conversion from char
        std:: string s4(10 , 'A'); // direct init with multiple args
        // std::string s5 = {10 , 'A'}; // initializer_list vs constructor ambiguity


    return 0;
    // kjftruyuio
}