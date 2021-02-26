#include <iostream>
#include <unordered_map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::unordered_map;

typedef long double BigBoi;

// static map container for generic strings
static unordered_map<string, string> generic(
        {
            {"greeting", "Hello, world!\n"},
            {"getInteger", "Please enter a number: "},
            {"printResult", "The final result is: "}
        });


// function signatures
BigBoi fib (const BigBoi);
BigBoi fibo (const BigBoi, const BigBoi, const BigBoi);


int main() {
    cout << generic["greeting"];
    cout << generic["getInteger"];

    BigBoi input;
    cin >> input;

    cout << generic["printResult"];
    auto result = fib(input);
    cout << result << endl;

    return 0;
}


// wrapper function for the core fibonacci function
BigBoi fib(const BigBoi n) {
    return fibo(n, 0, 1);
    // unoptimized recursive calls
    //return  (n == 0) ? 0 :
            //(n == 1) ? 1 : fib(n-1) + fib(n-2);
}


// recursive function with optimization for tail calls
BigBoi fibo (const BigBoi i, const BigBoi pre, const BigBoi cur) {
    cout << i << "\t: " << pre << endl;
    if (i == 0) return cur;
    return fibo(i-1, cur, pre+cur);
}

