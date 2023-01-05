#include "request.h"
#include <string>
#include <random>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Constructor
Request::Request(int n)
    : data_{generate_random_ip(),generate_random_ip(),generateRandomNumber(n)} {}

// Accessors (getters)
string Request::get_ip_in() const { return data_.ip_in; }
string Request::get_ip_out() const { return data_.ip_out; }
int Request::get_time() const { return data_.time; }

// Mutators (setters)
void Request::set_ip_in(std::string ip_in) { data_.ip_in = ip_in; }
void Request::set_ip_out(std::string ip_out) { data_.ip_out = ip_out; }
void Request::set_time(int time) { data_.time = time; }

// Generate random IP addresses
string Request::generate_random_ip() {
    std::random_device rd;  // Seed the generator
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 255);

    std::ostringstream oss;
    oss << dis(gen) << "." << dis(gen) << "." << dis(gen) << "." << dis(gen);
    return oss.str();
}

int Request::generateRandomNumber(int n) {
    std::random_device rd;  // Random number generator
    std::mt19937 gen(rd()); // Mersenne Twister 19937 generator
    std::uniform_int_distribution<> dis(2, n); // 2 to n uniform distribution

    return dis(gen);
}
