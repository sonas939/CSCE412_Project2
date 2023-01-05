#ifndef REQUEST_H
#define REQUEST_H

#include <string>

class Request {
    public:
        struct Data {
            std::string ip_in;
            std::string ip_out;
            int time;
        };

        // Constructor
        Request(int n);

        // Accessors (getters)
        std::string get_ip_in() const;
        std::string get_ip_out() const;
        int get_time() const;

        // Mutators (setters)
        void set_ip_in(std::string ip_in);
        void set_ip_out(std::string ip_out);
        void set_time(int time);

        // Generate random IP addresses
        std::string generate_random_ip();
        int generateRandomNumber(int n);

    private:
        // Private data member
        Data data_;
};

#endif