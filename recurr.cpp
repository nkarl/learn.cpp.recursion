#include <iostream>
#include <unordered_map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::unordered_map;
static unordered_map<string, string> generic(
        {
            {"greeting", "Hello, world!\n"},
            {"getInteger", "Please enter a number: "},
            {"printResult", "The final result is: "}
        });

int fib (const int);
int fibo (const int, const int, const int);

int main() {
    cout << generic["greeting"];
    cout << generic["getInteger"];
    int input;
    cin >> input;

    auto result = fib(input);
    cout << generic["printResult"];
    cout << result << endl;

    return 0;
}


int fib (const int n) {
    return fibo(n, 0, 1);
    //return  (n == 0) ? 0 :
            //(n == 1) ? 1 : fib(n-1) + fib(n-2);
}

int fibo (const int n, const int pre, const int cur) {
    cout << n << "\t: " << pre << endl;
    if (n == 0) return cur;
    return fibo(n-1, cur, pre+cur);
}

