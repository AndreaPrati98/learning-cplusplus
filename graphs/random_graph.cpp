#include <iostream>
#include <ctime>

using namespace std;

/// @brief Number of nodes of the graph
const int SIZE = 10;

/// @brief density of the graph
const double DENSITY = 0.5;

/// @brief Minimum weigth possible on an edge
const int MIN_WEIGTH = 1;

/// @brief Maximum weigth possible on an edge
const int MAX_WEIGTH = 10;


class Graph {
public:
    Graph(int numVertices, double density) : numVertices(numVertices), density(density) {
        adjacencyMatrix = create_random_graph(numVertices, density);
    };
    
    /// Return number of vertices
    int V() {
        return numVertices;
    };

    /// Return number of edges
    int E() {
        return numEdges;
    }; 

    /// Test whether there is an edge from x to y
    bool adjacent(int x, int y); 
    
    /// List all nodes y such that there is an edge from x to y
    std::vector<int> neighbors(int x); 
    
    void add(int x, int y, double weight); // Add the edge from x to y
    void remove(int x, int y); // Remove the edge from x to y
    double get_node_value(int x); // Return the value associated with node x
    void set_node_value(int x, double value); // Set the value associated with node x
    double get_edge_value(int x, int y); // Return the value associated with the edge (x, y)
    void set_edge_value(int x, int y, double value); // Set the value associated with the edge (x, y)

private:

    int** create_random_graph(int size, float density, int minWeigth = 1.0, int maxWeigth = 10.0);
    int numVertices;
    int numEdges;
    int** adjacencyMatrix;
    double density;
    // std::vector<std::vector<std::pair<int, double>>> adjacencyList;
};

void printMatrix(int** const matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

inline int randomWeight(double probabilityTrue, int minWeigth, int maxWeigth) {
    if (probabilityTrue > 1) 
    {
        cout << "Huston, we have a problem" << endl;
    }
    
    srand(clock()); 
    
    double randomValue = (rand() % 100);
    
    if ((randomValue/100) < probabilityTrue) {
        // cout << "Random value: " << (randomValue/100) << " probability value: " << probabilityTrue << endl;
        
        randomValue = (rand() % maxWeigth) + 1;
        // cout << static_cast<int>(randomValue) << endl;
        return static_cast<int>(randomValue);
    }

    return 0;

}

int** Graph::create_random_graph(int size, float density, int minWeigth, int maxWeigth) {
    srand(clock());

    int** graph = new int*[size]; // creating a graph as a matrix

    // let's declare all the rows
    for (int i = 0; i < size; i++)
    {
        graph[i] = new int[size];
    }
        
    for (int i = 0; i < size; ++i)
    {
        // now I add edges accordingly to density, the probability and edge exists
        // important to use j = i otherwise we risk to overwrite 
        for (int j = i; j < size; j++) {
            // cout << "Cycle with i: " << i << " and j: "<< j << endl;
            
            if (i == j) {
                
                graph[i][j] = 0; // no loops
            } else {
                int weight = randomWeight(density, minWeigth, maxWeigth);
                if (weight) {
                    cout << "Weigth: " << weight << " at (i,j): " << i << ',' << j << endl;
                    
                }
                graph[i][j] = graph[j][i] = weight;
            }
            
        }        
    }

    printMatrix(graph, size, size);

    return graph;
}

bool is_connected(bool *graph[], int size) 
{
    int old_size= 0, c_size = 0;

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
            
            for (int j = 0; j < size; j++)
            {
                open[j] = open[j] || graph[i][j];
            }
            

            if(open[i] && (close[i] == false)) 
            {
                // if the i-th node has been already reached but is not in the closed list, yet
                close[i] = true;
                c_size++;
            }
        }
    }

    if(c_size == size) return true;
    if(old_size == c_size) return false;
    
    return 0;
}


bool Graph::adjacent(int x, int y) {
    return adjacencyMatrix[x][y];
}

vector<int> Graph::neighbors(int x) {
    int* row = adjacencyMatrix[x];
    vector<int> res;

    for (int i = 0; i < numVertices; i++)
    {
        cout << row[i] << ", ";
        if(row[i]) {
            res.push_back(row[i]);
        }
    }
    cout << endl;
    
    return res;
}

int main() {
    
    Graph gr(SIZE, DENSITY);

    vector<int> vect = gr.neighbors(3);

    
    cout << "Printing vector of neighbors" << endl;
    for (int i = 0; i < vect.size(); i++)
    {
        cout << vect[i] << ", ";
    }
    
    cout << endl;
    
    return 0;
}

