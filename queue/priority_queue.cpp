//
// Created by Zeeshan Shaikh on 6/9/21.
//

# include <iostream>
#include <queue>

using namespace std;
void print_queue(priority_queue<int> pq){
    priority_queue<int> temp = pq;
    cout << "The elements of the queue are: ";
    while(!temp.empty()){
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
}

void print_queue2(priority_queue<int, vector<int>, greater<int>> pq){
    priority_queue<int, vector<int>, greater<int>> temp = pq;
    cout << "The elements of the queue are: ";
    while(!temp.empty()){
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
}

int main(){
    // Defining a priority queue
    // Important note here: By default C++ initializes priority queue using max heap
    priority_queue<int> defaultQueue;

    // Adding elements
    defaultQueue.push(15);
    defaultQueue.push(30);
    defaultQueue.push(8);
    defaultQueue.push(100);
    defaultQueue.push(78);

    // Printing all the elements in the Queue
    cout << "----- MAX HEAP -----" << endl;
    print_queue(defaultQueue);

    // We can also change the priority queue to use min heap instead
    // Initializing a priority queue with min heap here
    priority_queue<int, vector<int>, greater<int>> minHeapQueue;

    // Adding elements
    minHeapQueue.push(15);
    minHeapQueue.push(30);
    minHeapQueue.push(8);
    minHeapQueue.push(100);
    minHeapQueue.push(78);

    // Printing all the elements in the Queue
    cout << "----- MIN HEAP -----" << endl;
    print_queue2(minHeapQueue);
}