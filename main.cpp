#include <iostream>
#include <string>
#include <vector>
#include "server.cpp"
#include "loadbalancer.cpp"

using namespace std;

int main() {
    int numClockCycles = 10000;
    int numServers = 20;
    int maxProcessing = 500;
    cout << "Enter number of clock cycles: ";
    cin >> numClockCycles;
    cout << "Enter number of servers: ";
    cin >> numServers;
    cout << "Enter max number of processing: ";
    cin >> maxProcessing;
    int numRequests = numServers * 20;

    vector<Server> servers;
    for (int i = 1; i <= numServers; i++) {
        servers.push_back(Server(to_string(i),nullptr));
    }
    
    LoadBalancer load;
    for(int i = 0; i < numRequests; i++)
    {
        load.addRequest(new Request(maxProcessing));
    }

    for (int i = 0; i < numClockCycles; i++) {
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

    return 0;
}