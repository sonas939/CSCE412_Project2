#include <iostream>
#include <string>
#include <vector>
#include "server.cpp"
#include <random>
#include "loadbalancer.cpp"

using namespace std;

/* The main function was written by us except for the random number generator that was used in request.cpp and documentation from ChatGPT

/**

@brief Main function that simulates request processing by servers
@return 0 if program executes successfully
*/

/**
 * @mainpage
 * Created by: Sona Shah and Asha Aare
 * 
 */

int main() 
{
    /* Get user input for number of clock cycles, number of servers, and maximum processing time. */ 
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

    /* Open a log file that will add the data to a txt file */ 
    std::ofstream log_file;
    log_file.open("log.txt", std::ios::app);

    /* Create a vector of Server objects. */ 
    vector<Server> servers;
    for (int i = 1; i <= numServers; i++) {
        /* Create a new Server object and add vallues.*/
        servers.push_back(Server(to_string(i),nullptr));
    }

    /* Create a LoadBalancer object. */
    LoadBalancer load;
    /* Add the specified number of requests to the LoadBalancer object. */
    for(int i = 0; i < numRequests; i++) {
        /* Create a new Request object with the specified maximum processing time.*/
        load.addRequest(new Request(maxProcessing));
    }

    /* Create a string to hold log output and initialize it with the starting queue size. */
    string log_output = "Starting Queue Size: " + to_string(load.size());

    /* Log the number of clock cycles, number of servers, processing time range, and starting queue size. */
    log_file << "Number of Clock Cycles: " << numClockCycles << std::endl;
    log_file << "Number of Servers: " << numServers << std::endl;
    log_file << "Processing Time Range: 2 to " << maxProcessing << std::endl;
    log_file << log_output << std::endl;

    /* Iterate for the specified number of clock cycles. */
    for (int i = 0; i < numClockCycles; i++) {
        
        /* Add random number generator for requests - generates number between 1 and 5. Number has 20% chance of being 1 */
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 5);

        /* If the random number is 1, add a new request to the LoadBalancer object. */
        if (dis(gen) == 1) {
        load.addRequest(new Request(maxProcessing));
        }

        for (int j = 0; j < numServers; j++) {
            /* Check if the current server is available.*/
            if (servers.at(j).isAvailable()) {
                /* If the load balancer queue is empty, stop iterating through the servers.*/
                if (load.isEmpty()) {
                    break;
                }
                /* Assign the next request from the load balancer to the current server.*/
                servers.at(j).setRequest(load.getNextRequest());
            }
            /* If the server is not available, update its processing time.*/
            else {
                servers.at(j).updateTime(i);
            }
        }
    }
    /* After all the servers have been processed, log the ending queue size to the log file.*/
    log_output = "Ending Queue Size: " + to_string(load.size());
    log_file << log_output << std::endl;
    log_file.close();

    return 0;
}