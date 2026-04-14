#include<iostream>

using namespace std;


//  Cin  - console input    
//  Cout - console output
//  both are header - iostream , C++ streams


int main(){


    cout<< "Hello World! "<< endl;
    /*
        cout - object of class ostream
        << is overloaded - output insertion operator.
        send data - standard output stream .
        endl - insert newline , flushes buffer.
    */


    int age ;
    cin >> age;
    /*
        cin - object of class instream
            operator >> -  overloaded - input extraction 
            reads - standard input 
            skips whitespaces - basic types
            buffering, formatting, and synchronization with stdout
            perform - stream synchronization - compatible , scanf / printf ( Disabled - ios :: sync_with_stdio(false))
            handles formatting rules , locale , exceptions , etc.
            all - make - robust but slightly slower.
    */

    // cin / cout  -- (type -safe  and  function overloading ) --  slower than scanf() / printf  (faster , but less safe )

    // Default:- 
    // ios :: sync_with_stdio(true);  -  synchronizes C++ and C streams    - slower 
    //                       (false); -  No sync - allows faster cin       - faster 

    // Disable Sync for speed :-
    // 




    // getline - read entire lines (includes spaces)

    // manipulators 
        // setw(n)          - set width 
        // setfill('x')     - Fill character
        // fixed            - Fixed-point notation
        // setprecision(n)  - Decimal precision
    
    // 
    return 0;
}