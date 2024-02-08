#include <iostream>
#include <random>

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
    inline int V() {
        return numVertices;
    };

    /// Return number of edges
    inline int E() {
        return numEdges;
    };

    void printMatrix(int** const matrix, int rows, int cols) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

private:
    
    inline float randomWeight(float density, float minWeight, float maxWeight) {
        if(density < 0 || density > 1) {
            throw invalid_argument("Density must stay between 0 and 1");
        }


        // Define a random number generator engine
        random_device rd;
        mt19937 gen(rd());
        
        // Define a distribution for the desired range
        // firstly for the probability of edge existance, secondly for the weight
        uniform_real_distribution<double> distribution(0.0, 1.0);
        double probability = distribution(gen);

        uniform_real_distribution<double> distribution(1.0, 10.0);

        // Generate a random double within the specified range
        double rWeight = distribution(gen);

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

int main() {

    cout.precision(PRECISION);

}