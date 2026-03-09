#include <iostream>
#include <string>
#include <cstdint>
#include <cstring>

using namespace std;

float loop_counter;
float loop_bound;

void print_binary (float num);

int main(int argc, char* argv[]) {
    // Inputs
    // Check for number of arguments and exit if wrong
    if (argc != 3) {
        cout << "usage:" << endl;
        cout << "\t" << argv[0] << " loop_bound loop_counter" << endl;
        cout << endl;
        cout << "loop_bound is a positive floating-point value" << endl;
        cout << "loop_counter is a positive floating-point value" << endl;
        cout << endl;
        return 1;
    }
    // Set loop_bound and loop_counter to inputs
    loop_bound = stof(argv[1]);
    loop_counter = stof(argv[2]);

    // Number outputs
    print_binary(loop_bound);
    print_binary(loop_counter);

    // Check for overflow
    
    return 0;
}

void print_binary (float num) {
    uint32_t binary;
    memcpy(&num, &binary, sizeof(float));
    memcpy(&binary, &num, sizeof(float));
    cout << endl;
}