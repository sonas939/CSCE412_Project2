#include <iostream>
#include <string>
#include "request.h"
#include <fstream>
using namespace std;

/**

    @brief Server class that handles requests
*/

class Server {
    public:
        /*
        * @brief Constructor for Server object
        * @param name Name of the server as a string
        * @param request Request object that the server is handling
        */
        Server(string name, Request* request) : name_(name), request_(request) {}

         /**
         * @brief Getter for server name
         * @return Server name as a string
         */
        string getName() const { return name_; }

         /**
         * @brief Getter for request object
         * @return Pointer to request object
         */
        Request* getRequest() const { return request_; }

         /**
         * @brief Setter for server name
         * @param name Server name as a string
         */
        void setName(string name) { name_ = name; }

         /**
         * @brief Setter for request object
         * @param request Pointer to request object
         */
        void setRequest(Request* request) { request_ = request; }

         /**
         * @brief Updates the time remaining for the request to be completed
         * @param clockCycle Current clock cycle as an int
         */
        void updateTime(int clockCycle) {
            int time = request_->get_time()-1;
            request_->set_time(time);
            if (time <= 0) {
                std::ofstream log_file;
                log_file.open("log.txt", std::ios::app); 
                string log_output =  "At " + to_string(clockCycle) + " Server " + name_ + " processed request from " + request_->get_ip_in() + " to " + request_->get_ip_out();
                log_file << log_output << std::endl;
                log_file.close();
                request_ = nullptr;
            }
        }

         /**
         * @brief Check if the server is available to handle a new request
         * @return True if the server is available, false otherwise
         */
        bool isAvailable() {
            if (request_ == nullptr) {
                return true;
            } 
            return false;
        }

    private:
        /**
        * @brief Server name
        */
        string name_;

        /**
        * @brief Pointer to request object being handled by the server
        */
        Request* request_;
};