#include "List.h"
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

/*
 * FUNCTION SIGNATURES
 */
vector<string> *capture_args(int argc, const char *argv[]);
vector<double> *to_double(vector<string> &args);
vector<int> *   to_int(vector<string> &args);

/*
 * MAIN FUNCTION
 */
int main(int argc, const char *argv[]) {

    vector<string> s_args = *capture_args(argc, argv);
    vector<double> args   = *to_double(s_args);

    List<double> myList = List<double>(args[0]);
    for (int i = 1; i < args.size(); ++i) {
        myList.insert(args[i]);
    }
    myList.show();

    return 0;
}

/*
 * CAPTURE THE CL ARGUMENTS
 */
vector<string> *capture_args(int argc, const char *argv[]) {
    if (argc <= 1) {
        std::cerr << "Error: no arguments passed" << endl;
        exit(EXIT_FAILURE);
    }
    vector<string> *args = new vector<string>();
    for (int i = 1; i < argc; ++i) {
        string word = argv[i];
        args->push_back(word);
    }
    return args;
}

/*
 * CONVERT ARGS TO INT
 */
vector<int> *to_int(vector<string> &args) {
    vector<int> *vec = new vector<int>();
    for (auto a : args) {
        int d = std::stoi(a);
        vec->push_back(d);
    }
    return vec;
}

/*
 * CONVERT ARGS TO DOUBLE
 */
vector<double> *to_double(vector<string> &args) {
    vector<double> *vec = new vector<double>();
    for (auto a : args) {
        double d = std::stod(a);
        vec->push_back(d);
    }
    return vec;
}
