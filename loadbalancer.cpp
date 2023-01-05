#include <queue>
#include "request.h"
/**

    @brief LoadBalancer class that manages requests to be processed
*/

class LoadBalancer {
    public:
        /*
        * @brief Constructor for LoadBalancer object
        */
        LoadBalancer(){};
        
         /**
         * @brief Add request to the queue to be processed
         * @param request Pointer to request object to be added
         */
        void addRequest(Request* request) {
            requestQueue.push(request);
        }

         /**
         * @brief Get the next request in the queue to be processed
         * @return Pointer to the next request object
         */
        Request* getNextRequest() {
            Request* nextRequest = requestQueue.front();
            requestQueue.pop();
            return nextRequest;
        }

         /**
         * @brief Check if the request queue is empty
         * @return True if the queue is empty, false otherwise
         */
        bool isEmpty() {
            return requestQueue.empty();
        }

         /**
         * @brief Get the size of the request queue
         * @return Size of the request queue as an int
         */
        int size() {
            return requestQueue.size();
        }

    private:
        /**
        * @brief Queue of pointers to request objects
        */
        std::queue<Request*> requestQueue;

};
