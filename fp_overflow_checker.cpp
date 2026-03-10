#include <iostream>
#include <string>
#include <cstdint>
#include <cstring>
#include <bitset>

using namespace std;

float loop_counter;
float loop_bound;

uint32_t bound_binary;
uint32_t bound_sign;
uint32_t bound_exponent;
uint32_t bound_fraction;

uint32_t counter_binary;
uint32_t counter_sign;
uint32_t counter_exponent;
uint32_t counter_fraction;

void convert_to_binary (float bound, float counter);
void binary_output(uint32_t sign, uint32_t exponent, uint32_t fraction);
bool check_for_overflow();

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
    cout << endl;
    cout << "Loop bound:\t";
    binary_output(bound_sign, bound_exponent, bound_fraction);
    cout << "Loop counter:\t";
    binary_output(counter_sign, counter_exponent, counter_fraction);
    cout << endl;

    // Check for overflow
    if (check_for_overflow())
        cout << "Warning: Possible overflow!" << endl;
    else
        cout << "There is no overflow!" << endl;
    
    return 0;
}

void convert_to_binary (float bound, float counter) {
    memcpy(&bound_binary, &bound, sizeof(float));
    bound_sign = (bound_binary >> 31) & 0x1;
    bound_exponent = (bound_binary >> 23) & 0xFF;
    bound_fraction = (bound_binary) & 0x7FFFFF;

    memcpy(&counter_binary, &counter, sizeof(float));
    counter_sign = (counter_binary >> 31) & 0x1;
    counter_exponent = (counter_binary >> 23) & 0xFF;
    counter_fraction = (counter_binary) & 0x7FFFFF;
}

void binary_output(uint32_t sign, uint32_t exponent, uint32_t fraction) {
    cout << bitset<1>(sign) << " ";
    cout << bitset<8>(exponent) << " ";
    cout << bitset<23>(fraction) << endl;
}

bool check_for_overflow() {
    // Check to see if the bound's exponent is significantly more than the counter's exponent
    if (bound_exponent < counter_exponent + 24)
        return false;
    
    return true;
}