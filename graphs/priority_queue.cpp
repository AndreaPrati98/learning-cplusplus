#include <iostream>

using namespace std;

/**
 * @brief Element of the priority queue. The first element represent the node number, the second one the priority.
 */
typedef tuple<int, int> queue_element;

class PriorityQueue {

private: 
    vector<queue_element> heap;

    /// @brief Helper functions to maintain heap property. It checks that the parent is actually smaller then the added element 
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

    /** @brief Helper functions to maintain heap property. It checks that the leaves are bigger then the parent. 
     *  @param index - of the element we want to check
    */ 
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
        if (isEmpty()) throw out_of_range("Heap is empty");
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
        // substitue the first element of the heap (the root) with the last element of the heap (one of its leaves)
        heap[0] = heap.back();
        // then I discard the last element of the heap because it's a duplicate
        heap.pop_back();
        // I call the recurive function to adjust the tree (in array form, in this case)
        heapifyDown(0);

        return min;

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
    
    bool contains(queue_element element) {
        for(const auto& e : heap) {
            if (e == element) {
                return true;
            }
        }
        return false;
    }

    bool contains(int node) {
        for(const auto& e : heap) {
            if (get<0>(e) == node) {
                return true;
            }
        }
        return false;
    }

    /**
     * @brief Change the priority (ndoe value) of a queue element
     * 
     * @param element 
     * @param priority 
     */
    void chgPriority(queue_element element, int priority) {
        
        for (int i = 0; i < heap.size(); ++i) {
            if (heap[i] == element) {
                // found the element to be changed
                get<1>(heap[i]) = priority;
                // if the updated element violates the heap property, we can either 'heapify' 
                // depending on whether the updated element should move up or down in 
                // the heap to restore the heap property.
                if (i > 0 && get<1>(heap[i]) < get<1>(heap[(i - 1) / 2])) {
                    
                    heapifyUp(i);
                } else {
                    
                    heapifyDown(i);
                }
                return;
            }
        }
        throw invalid_argument("Element not found in the queue");
    }

};

int main() {
    PriorityQueue pq;

    pq.insert(2, 4);
    pq.insert(3, 7);
    pq.insert(1, 5);

    cout << pq << endl;

    cout << get<0>(pq.extractMin()) << endl; // ! TBD yet
    
    cout << pq << endl;

}