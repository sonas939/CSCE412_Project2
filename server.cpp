#include <iostream>
#include <string>
#include "request.h"
#include <fstream>
using namespace std;

class Server {
    public:
        Server(string name, Request* request) : name_(name), request_(request) {}

        string getName() const { return name_; }
        Request* getRequest() const { return request_; }

        void setName(string name) { name_ = name; }
        void setRequest(Request* request) { request_ = request; }

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

        bool isAvailable() {
            if (request_ == nullptr) {
                return true;
            } 
            return false;
        }

    private:
        string name_;
        Request* request_;
};
