#include <iostream>
#include <string>
#include <cstdint>
#include <cstring>
#include <bitset>

using namespace std;

float loop_counter;
float loop_bound;

void convert_to_binary (float bound, float counter);
void check_for_overflow(float bound, float counter);

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

    // Number conversions
    convert_to_binary(loop_bound, loop_counter);

    // Number outputs

    // Check for overflow
    check_for_overflow(loop_bound, loop_counter);
    
    return 0;
}

void convert_to_binary (float bound, float counter) {
    uint32_t binary;

    memcpy(&binary, &num, sizeof(float));

    uint32_t sign = (binary >> 31) & 0x1;
    uint32_t exponent = (binary >> 23) & 0xFF;
    uint32_t fraction = (binary) & 0x7FFFFF;

    cout << bitset<1>(sign) << " ";
    cout << bitset<8>(exponent) << " ";
    cout << bitset<23>(fraction) << endl;
}

void check_for_overflow(float bound, float counter) {
    // Check to see if the bound's exponent is significantly more than the counter's exponent
}