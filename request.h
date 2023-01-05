/**
    @file request.h
    @brief This file contains the declaration of the Request class.
*/

#ifndef REQUEST_H
#define REQUEST_H

#include <string>

    /**
    @class Request
    @brief A class representing a request made by a client.
    */
   
    class Request {
    public:
    /*
    * @struct Data
    * @brief A struct containing the data of a request.
    */
    struct Data {
    std::string ip_in; /* The client's IP address. */
    std::string ip_out; /* The server's IP address. */
    int time; /** The time at which the request was made. */
    };

     /**
      * @brief Constructor for the Request class.
      * @param n The number of random IP addresses to generate.
      */
     Request(int n);

     /**
      * @brief Get the client's IP address.
      * @return The client's IP address.
      */
     std::string get_ip_in() const;

     /**
      * @brief Get the server's IP address.
      * @return The server's IP address.
      */
     std::string get_ip_out() const;

     /**
      * @brief Get the time at which the request was made.
      * @return The time at which the request was made.
      */
     int get_time() const;

     /**
      * @brief Set the client's IP address.
      * @param ip_in The new client's IP address.
      */
     void set_ip_in(std::string ip_in);

     /**
      * @brief Set the server's IP address.
      * @param ip_out The new server's IP address.
      */
     void set_ip_out(std::string ip_out);

     /**
      * @brief Set the time at which the request was made.
      * @param time The new time at which the request was made.
      */
     void set_time(int time);

     /**
      * @brief Generate a random IP address.
      * @return A randomly generated IP address.
      */
     std::string generate_random_ip();

     /**
      * @brief Generate a random number.
      * @param n The upper bound for the generated random number.
      * @return A random number between 0 and n-1.
      */
     int generateRandomNumber(int n);

    private:
    Data data_; /** The data of the request. */
    };

#endif
