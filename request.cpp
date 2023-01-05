#include "request.h"
#include <string>
#include <random>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/**

    @brief Constructor for Request object
    @param n upper bound for random number generator
*/
    Request::Request(int n)
    : data_{generate_random_ip(),generate_random_ip(),generateRandomNumber(n)} {}

/**

    @brief Getter for IP address coming into the request
    @return IP address coming into the request as a string
*/
    string Request::get_ip_in() const { return data_.ip_in; }

/**

    @brief Getter for IP address going out of the request
    @return IP address going out of the request as a string
*/
    string Request::get_ip_out() const { return data_.ip_out; }

/**

    @brief Getter for time of the request
    @return Time of the request as an int
*/
    int Request::get_time() const { return data_.time; }

/**

    @brief Setter for IP address coming into the request
    @param ip_in IP address coming into the request as a string
*/
    void Request::set_ip_in(std::string ip_in) { data_.ip_in = ip_in; }

/**

    @brief Setter for IP address going out of the request
    @param ip_out IP address going out of the request as a string
*/
    void Request::set_ip_out(std::string ip_out) { data_.ip_out = ip_out; }

/**

    @brief Setter for time of the request
    @param time Time of the request as an int
*/
    void Request::set_time(int time) { data_.time = time; }

/**

    @brief Generates a random IP address
    @return Random IP address as a string
*/
    string Request::generate_random_ip() {
    std::random_device rd; // Seed the generator
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 255);

    std::ostringstream oss;
    oss << dis(gen) << "." << dis(gen) << "." << dis(gen) << "." << dis(gen);
    return oss.str();
    }

/**

    @brief Generates a random number between 2 and n

    @param n Upper bound for random number generator

    @return Random number as an int
*/
    int Request::generateRandomNumber(int n) {
    std::random_device rd; // Random number generator
    std::mt19937 gen(rd()); // Mersenne Twister 19937 generator
    std::uniform_int_distribution<> dis(2, n); // 2 to n uniform distribution

    return dis(gen);
    }