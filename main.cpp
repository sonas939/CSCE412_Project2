#include <iostream>
#include <string>
#include <vector>
#include "server.cpp"
#include <random>
#include "loadbalancer.cpp"

using namespace std;

int main() {
    int numClockCycles;
    int numServers;
    int maxProcessing;
    cout << "Enter number of clock cycles: ";
    cin >> numClockCycles;
    cout << "Enter number of servers: ";
    cin >> numServers;
    cout << "Enter max number of processing: ";
    cin >> maxProcessing;
    int numRequests = numServers * 20;
    std::ofstream log_file;
    log_file.open("log.txt", std::ios::app); 

    vector<Server> servers;
    for (int i = 1; i <= numServers; i++) {
        servers.push_back(Server(to_string(i),nullptr));
    }
    
    LoadBalancer load;
    for(int i = 0; i < numRequests; i++)
    {
        load.addRequest(new Request(maxProcessing));
    }
    string log_output =  "Starting Queue Size: " + to_string(load.size());
    log_file << log_output << std::endl;

    for (int i = 0; i < numClockCycles; i++) {
        //add random number generator for requests - generates number between 1 and 5. Number has 20% chance of being 1
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 5);
        if (dis(gen) == 1) {
            load.addRequest(new Request(maxProcessing));
        }

        for (int j = 0; j < numServers; j++) {
            if (servers.at(j).isAvailable()) {
                if (load.isEmpty()) {
                    break;
                }
                servers.at(j).setRequest(load.getNextRequest());
            }
            else {
                servers.at(j).updateTime(i);
            }
        }
    }
    log_output =  "Ending Queue Size: " + to_string(load.size());
    log_file << log_output << std::endl;
    log_file.close();

    return 0;
}