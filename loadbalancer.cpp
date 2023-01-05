#include <queue>
#include "request.h"

class LoadBalancer {
    public:
        LoadBalancer(){};
        
        void addRequest(Request* request) {
            requestQueue.push(request);
        }

        Request* getNextRequest() {
            Request* nextRequest = requestQueue.front();
            requestQueue.pop();
            return nextRequest;
        }

        bool isEmpty() {
            return requestQueue.empty();
        }

        int size() {
            return requestQueue.size();
        }

    private:
        std::queue<Request*> requestQueue;

};
