#include <iostream>

using namespace std;

typedef tuple<int, int> queue_element;

class PriorityQueue {

private: 
    vector<queue_element> heap;

    /// @brief Helper functions to maintain heap property. To be used when insert.
    /// @param index 
    void heapifyUp(int index) {
        /*
        given the index we inserted the parent is checked
        */
        int parent = (index - 1) / 2;
        while (index > 0 && get<1>(heap[index]) < get<1>(heap[parent])) {
            swap(heap[index], heap[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    /// @brief Helper functions to maintain heap property. To be used when removed.
    /// @param index 
    void heapifyDown(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < heap.size() && get<1>(heap[left]) < get<1>(heap[index]))
            smallest = left;

        if (right < heap.size() && get<1>(heap[right]) < get<1>(heap[smallest]))
            smallest = right;

        if (smallest != index) {
            // if we find 
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest); // it's recursive
        }
    }

public: 
    
    PriorityQueue() {}
    
    void insert(int node, int weight) {
        heap.push_back(make_tuple(node,weight));
        heapifyUp(heap.size() - 1); // need to check that the added element is less then its parent.
    }

    inline void check_if_empty() {
        if (heap.empty()) throw out_of_range("Heap is empty");
    }

    inline bool isEmpty() {
        return heap.empty();
    }

    queue_element getMin() {
        check_if_empty();

        return heap.front();
    }

    queue_element extractMin() {
        check_if_empty();

        queue_element min = heap.front();
        // todo
        get<1>(min);
    }

    int get_size() {
        return heap.size();
    }

    friend ostream& operator<<(ostream& os, const PriorityQueue pq) {
        cout << "Printing the priority queue:" << endl;

        for(auto el : pq.heap) {
            cout << "(" << get<0>(el) << ", " << get<1>(el) << "); ";
        }

        return os;
    }


};

int main() {
    PriorityQueue pq;

    pq.insert(1, 5);
    pq.insert(2, 4);
    pq.insert(3, 7);

    cout << pq << endl;
    

}