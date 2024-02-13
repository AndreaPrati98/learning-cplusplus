#include <iostream>
#include <random>
#include <set>

using namespace std;

/// @brief Number of nodes of the graph.
const int SIZE = 50;

/// @brief density of the graph.
const float DENSITY = 0.2;

/// @brief Minimum weigth possible on an edge.
const float MIN_WEIGTH = 1;

/// @brief Maximum weigth possible on an edge.
const float MAX_WEIGTH = 10;

/// @brief Precision decimal number.
const int PRECISION = 3;

/**
 * @brief Element of the priority queue. The first element represent the node number, the second one the priority.
 */
typedef tuple<int, int> queue_element;

class Graph {
public:
    Graph(
        int size = SIZE, 
        float density = DENSITY, 
        float minWeight = MIN_WEIGTH, 
        float maxWeigth = MAX_WEIGTH
    ) {
        numVertices = size;
        random_initialization(numVertices, density, minWeight, maxWeigth);
        countEdges();
    }

    /// Return number of vertices
    inline const int& V() const {
        
        return numVertices;
    };

    /// Return number of edges
    inline const int& E() const {
        return numEdges;
    };

    void printMatrix(int** const matrix, int rows, int cols) {
        cout << "Printing the matrix" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    const float& getEdgeValue(int x, int y) const {
        return adjacencyMatrix[x][y];
    }

    inline void setEdgeValue(int x, int y, int value) {
        adjacencyMatrix[x][y] = adjacencyMatrix[y][x] = value;
    }

    void addEdge(int x, int y) {
        int edge = adjacencyMatrix[x][y];

        if(edge) {
            cout << "The edge already exists." << endl;
        } else {
            int newEdge = randomWeight(MIN_WEIGTH, MAX_WEIGTH);
            adjacencyMatrix[x][y] = adjacencyMatrix[y][x] = newEdge;
            // cout << "Added new edge: " << x << ", " << y << " . Weight: " << newEdge << endl;
        }
    }

    inline void removeEdge(int x, int y) {
       adjacencyMatrix[x][y] = 0;
    }

    bool isConnected() const {
        int old_size= 0, c_size = 0, size = numVertices;

        bool* close = new bool[size]; // if true the node can be reached from another
        bool* open = new bool[size]; // if true the node has already been reached

        for (int i = 0; i < size; i++)
        {
            open[i] = close[i] = false;
        }
        open[0] = true;

        // up to here it was initialization

        while (c_size < size)
        {
            for(int i = 0; i < size; ++i)
            {
                old_size = c_size;
                
                if(open[i] && (close[i] == false)) 
                {
                    // if the i-th node has been already reached but is not in the closed list, yet
                    close[i] = true;
                    c_size++;
                }

                for (int j = 0; j < size; j++)
                {
                    // or the j node is in the open set or we add it in case the is an edge i,j.
                    open[j] = open[j] || adjacencyMatrix[i][j];
                }
                
            }

            // if after the iteration the size of the closed set doesn't change then stop.
            if(old_size == c_size) return false;
            if(c_size == size) return true;
        }

        
        return 0;
    }

    /**
     * @brief Given the node we want to know the neighbors of a set of these neighbors is returned.
     * 
     * @param x 
     * @return set<int> 
     */
    set<int> neighbors(int x) const {
        float* row = adjacencyMatrix[x];
        set<int> res;

        for (int i = 0; i < numVertices; i++)
        {
            if(row[i]) {
                res.insert(i);
            }
        }
        
        return res;

    }


private:
    
    inline float randomWeight(float minWeight, float maxWeight) {
        // Define a random number generator engine
        random_device rd;
        mt19937 gen(rd());
        
        // Define a distribution for the desired range
        // Define a distribution for the desired range
        uniform_real_distribution<double> weight_distribution(1.0, 10.0);

        // Generate a random double within the specified range
        double rWeight = weight_distribution(gen);
        return rWeight;
    }

    inline float randomWeight(float density, float minWeight, float maxWeight) {
        if(density < 0 || density > 1) {
            throw invalid_argument("Density must stay between 0 and 1");
        }


        // Define a random number generator engine
        random_device rd;
        mt19937 gen(rd());
        
        // firstly for the probability of edge existance, secondly for the weight
        uniform_real_distribution<double> prob_distribution(0.0, 1.0);
        double probability = prob_distribution(gen);

        // Define a distribution for the desired range
        uniform_real_distribution<double> weight_distribution(1.0, 10.0);

        // Generate a random double within the specified range
        double rWeight = weight_distribution(gen);

        return (probability < density) * rWeight;

    }

    void random_initialization(int size, float density, float minWeight = MIN_WEIGTH, float maxWeigth = MAX_WEIGTH) {
        if(density < 0 || density > 1) {
            throw invalid_argument("Density must stay between 0 and 1");
        }  

        adjacencyMatrix = new float* [size];
        // let's declare all the rows
        for (int i = 0; i < size; i++) {
            adjacencyMatrix[i] = new float[size];
        }

        for (int i = 0; i < size; ++i) {
            // adding edges accordingly to density
            // starting j = i so that we don't override the same cells twice
            for (int j = i; j < size; j++) {
                
                if (i == j) {
                    adjacencyMatrix[i][j] = 0; // no loops
                } else {
                    float weight = randomWeight(density, minWeight, maxWeigth);
                    adjacencyMatrix[i][j] = adjacencyMatrix[j][i] = weight;
                }
                
            }          
        }
    }

    void countEdges() {
        numEdges = 0;
        for (int i = 0; i < numVertices; ++i)
        {
            for (int j = i; j < numVertices; ++j)
            {
                if(adjacencyMatrix[i][j]) {
                    numEdges++;
                }
            }
            
        }
        
    }

    float** adjacencyMatrix;
    int numVertices; 
    int numEdges;
    int k;
};

ostream& operator<< (ostream& os, const Graph& graph) {
    
    for(int i= 0; i < graph.V(); ++i) {
        for(int j = 0; j < graph.V(); ++j) {
            cout << graph.getEdgeValue(i,j) << " ";
        }
        cout << endl;
    }

    return os;
}

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

    /// @brief Helper functions to maintain heap property. It checks that the leaves are bigger then the parent. 
    /// @param index - of the element we want to check
    void heapifyDown(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        // cout << "Heapifying down" << endl;
        if (left < heap.size() && get<1>(heap[left]) < get<1>(heap[index]))
            smallest = left;

        if (right < heap.size() && get<1>(heap[right]) < get<1>(heap[smallest]))
            smallest = right;

        if (smallest != index) {
            // if we find 
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest); // it's recursive
        }

        // cout << "Finished to heapify" << endl;
    }

public:
    PriorityQueue() {}

    /**
     * @brief Insert tuple (node, weight) in the heap.
     * 
     * @param node 
     * @param weight 
     */
    void insert(int node, int weight) {
        heap.push_back(make_tuple(node, weight));
        heapifyUp(heap.size() - 1); // need to check that the added element is less then its parent.
    }

    inline void checkIfEmpty() {
        if (isEmpty()) throw out_of_range("Heap is empty");
    }

    inline bool isEmpty() {
        return heap.empty();
    }

    /// @brief Return the minimum value in the heap **without extraction**.
    /// @return - first element in the heap.
    queue_element getMin() {
        checkIfEmpty();

        return heap.front();
    }

    /**
     * @brief Extract the minimum value of the heap and perform modification on the array to maintain the heap property.
     * 
     * @return queue_element 
     */
    queue_element extractMin() {
        checkIfEmpty();

        queue_element min = heap.front();
        // substitue the first element of the heap (the root) with the last element of the heap (one of its leaves)
        heap[0] = heap.back();
        // then I discard the last element of the heap because it's a duplicate
        heap.pop_back();
        // I call the recurive function to adjust the tree (in array form, in this case)
        heapifyDown(0);

        return min;

    }

    int getSize() const {
        return heap.size();
    }

    inline const vector<queue_element>& getHeap() const {
        return heap;
    }
    
    /**
     * @brief Given a queue_element it returnes true if it is in the heap and false if it's not.
     * 
     * @param element 
     * @return true 
     * @return false 
     */
    bool contains(queue_element element) const {
        for(const auto& e : heap) {
            if (e == element) {
                return true;
            }
        }
        return false;
    }

    /**
     * @brief Given a node it returns true if the node is somehow present in the heap and false if it's not.
     * 
     * @param node 
     * @return true 
     * @return false 
     */
    bool contains(int node) const {
        for(const auto& e : heap) {
            if (get<0>(e) == node) {
                return true;
            }
        }
        return false;
    }

    /**
     * @brief Change the priority (node value) of a queue element
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
    
    /**
     * @brief Change the priority (node value) of a queue element
     * 
     * @param element 
     * @param priority 
     */
    void chgPriority(int node, int priority) {
        
        for (int i = 0; i < heap.size(); ++i) {
            if (get<0>(heap[i]) == node) {
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

ostream& operator<<(ostream& os, const PriorityQueue& pq) {
    cout << "Printing the priority queue:" << endl;

    for(const auto& el : pq.getHeap()) {
        cout << "(" << get<0>(el) << ", " << get<1>(el) << "); ";
    }

    return os;
}

class ShortestPath {

private:

    Graph graph;  

public:

    const Graph& getGraph() const {
        return graph;
    }

    /**
     * @brief Returns the minimum distance from the source node (considering the dist[] array) 
     * and only considering nodes not in the closed set.
     * 
     * @param dist 
     * @param cSet 
     * @return float 
     */
    float minDistance(double dist[], bool cSet[]) const {
        float min = numeric_limits<float>::infinity();
        int index;
        
        // for each vertex let's check if it is not in the closed set
        // and is the minimum vertex among the others.
        for (int v = 0; v < graph.V(); v++){
            
            if (dist[v] <= min && cSet[v] == false){
                min = dist[v];
                index = v;
            }
        }
        return index;
    }

    vector<int> path(int s, int t) const {

        int N = graph.V();

        PriorityQueue priorityQueue = PriorityQueue();
        
        cout << "Shortest path between: (" << s << ", "<< t << ")"<< endl;

        /* The algorithm works by creating three arrays:
         - distances from the source
         - close set to keep track of the visited nodes
         - array keeping track of the previous node for each node (to backtrack the actual shortest path)
        */ 
        vector<int> prev(N, -1); 
        vector<float> dist(N, numeric_limits<float>::infinity()); 
        vector<bool> cSet(N, false); 

        dist[s] = 0;
        priorityQueue.insert(s, 0);
        int cycle = 0;
        
        while (!priorityQueue.isEmpty())
        {
            cout << "Cycle number " << cycle << endl;
            cout << "Queue status: " << priorityQueue << endl;
            queue_element minElement = priorityQueue.extractMin();

            int u = get<0>(minElement);
            
            for (const auto& v : graph.neighbors(u))
            {
                float alt = dist[u] + graph.getEdgeValue(u, v);
                if(alt < dist[v]) {
                    dist[v] = alt;
                    prev[v] = u;
                    if(priorityQueue.contains(v)) {
                        priorityQueue.chgPriority(v, alt);
                    } else {
                        priorityQueue.insert(v, alt);
                    }
                }
            }
            cycle++; 
        }

        return prev;
        
    }

    /**
     * @brief Given a vector containing, for each node, the most convenient previous node, this method build the actual
     * vector containg the simple sequence of nodes to go through in order to do the shortest path.
     * 
     * @param prev 
     * @return vector<int> 
     */
    const vector<int> fromPrevToPath(const vector<int>& prev, int s, int t) {

        bool stop = false;

        vector<int> path;
        path.push_back(t);
        int n = t;
        while(!stop)
        {
            int nodePrev = prev[n]; 
            n = nodePrev;
            path.push_back(n);
            stop = (n == s); // stop criteria is to have reached the source
        }
        return path;
        
    }

    vector<int> path_size(int s, int t);

    ShortestPath(int size = SIZE, float density = DENSITY): graph(size, density) {}

};

int main() {

    cout.precision(PRECISION);


    ShortestPath sp = ShortestPath();

    Graph graph = sp.getGraph();


    cout << "The graph generated has the following adjacency matrix:" << endl;
    cout << graph << endl;

    cout << "Is the graph connected? " << graph.isConnected() << endl;

    int s = 0, t = 3;
    vector<int> precedencies = sp.path(s, t);
    cout << "Vector with precedencies, from 0 to 3: " << endl;
    for(const auto& node : precedencies) {
        cout << node << ", " ;
    }

    cout << endl;

    vector<int> shortestPath = sp.fromPrevToPath(precedencies, s, t);
    cout << "Vector with shortest path, from target to source: "<< endl;
    for(const auto& node : shortestPath) {
        cout << node << ", " ;
    }

    cout << endl;

}
