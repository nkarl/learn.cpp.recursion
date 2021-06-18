#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::vector;
using std::string;

int main(int argc, char *argv[]) {
    vector<string> *args = new vector<string>();

    //*args = { "aaa", "bbb", "ccc" };
    
    for (auto i = 0; i < argc; ++i) {
        string word = argv[i];
        args->push_back(word);
    }

    for (auto a : *args) {
        cout << a << " ";
    }

    return 0;
}
