#include <iostream>
#include <random>

using namespace std;

/// @brief Number of nodes of the graph.
const int SIZE = 5;

/// @brief density of the graph.
const float DENSITY = 0.2;

/// @brief Minimum weigth possible on an edge.
const float MIN_WEIGTH = 1;

/// @brief Maximum weigth possible on an edge.
const float MAX_WEIGTH = 10;

/// @brief Precision decimal number.
const int PRECISION = 3;


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

    void add(int x, int y) {
        int edge = adjacencyMatrix[x][y];

        if(edge) {
            cout << "The edge already exists." << endl;
        } else {
            int newEdge = randomWeight(MIN_WEIGTH, MAX_WEIGTH);
            adjacencyMatrix[x][y] = adjacencyMatrix[y][x] = newEdge;
            // cout << "Added new edge: " << x << ", " << y << " . Weight: " << newEdge << endl;
        }
    }

    inline void Graph::remove(int** G, int x, int y) {
       G[x][y] = 0;
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

class PriorityQueue {
public:
    PriorityQueue() {}
};

class ShortestPath {

private:
    Graph graph;
    PriorityQueue priorityQueue;  

public:

    vector<int> path(int s, int t) {
        int dist[graph.V()];
    }

    vector<int> path_size(int s, int t);

    ShortestPath(): graph(), priorityQueue() {}

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

int main() {

    cout.precision(PRECISION);

    Graph graph(SIZE);

    cout << graph << endl;

}