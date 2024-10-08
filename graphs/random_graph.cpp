#include <iostream>
#include <ctime>
#include <set>
#include <fstream>


using namespace std;

/// @brief Number of nodes of the graph
const int SIZE = 50;

/// @brief density of the graph
const double DENSITY = 0.2;

/// @brief Minimum weigth possible on an edge
const int MIN_WEIGTH = 1;

/// @brief Maximum weigth possible on an edge
const int MAX_WEIGTH = 10;


class Graph {
public:
    Graph(int numVertices, double density) : numVertices(numVertices), density(density) {
        adjacencyMatrix = create_random_graph(numVertices, density);
    };
    
    /// @brief Get the graph
    /// @return Graph as adjacency matrix
    int** get_graph() {
        return adjacencyMatrix;
    };
    
    /// Return number of vertices
    int V(int** G) {
        return numVertices;
    };

    /// Return number of edges
    int E(int** G) {
        return numEdges;
    }; 

    /// Test whether there is an edge from x to y
    bool adjacent(int** G, int x, int y); 
    
    /// List all nodes y such that there is an edge from x to y
    set<int> neighbors(int** G, int x); 
    
    void add(int** G, int x, int y); // Add the edge from x to y
    void remove(int** G, int x, int y); // Remove the edge from x to y
    // double get_node_value(int x); // Return the value associated with node x
    // void set_node_value(int x, double value); // Set the value associated with node x
    int get_edge_value(int** G, int x, int y); // Return the value associated with the edge (x, y)
    void set_edge_value(int** G, int x, int y, int value); // Set the value associated with the edge (x, y)
    bool is_connected(int *graph[]);
    void print_on_file(string filename);

private:

    int** create_random_graph(int size, float density, int minWeigth = 1.0, int maxWeigth = 10.0);
    int numVertices;
    int numEdges;
    int** adjacencyMatrix;
    // std::vector<std::vector<std::pair<int, double>>> adjacencyList;
    double density;
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
                graph[i][j] = graph[j][i] = weight;
            }
            
        }        
    }

    // printMatrix(graph, size, size);

    return graph;
}

bool Graph::is_connected(int *graph[]) 
{
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
                open[j] = open[j] || graph[i][j];
            }
            
        }

        // if after the iteration the size of the closed set doesn't change then stop.
        if(old_size == c_size) return false;
        if(c_size == size) return true;
    }

    
    return 0;
}


bool Graph::adjacent(int** G, int x, int y) {
    return G[x][y];
}
 
set<int> Graph::neighbors(int** G, int x) {
    int* row = G[x];
    set<int> res;

    for (int i = 0; i < numVertices; i++)
    {
        if(row[i]) {
            res.insert(row[i]);
        }
    }
    
    return res;
}

void Graph::add(int **G, int x, int y) {
    int edge = G[x][y];

    if(edge) {
        cout << "The edge already exists." << endl;
    } else {
        int newEdge = randomWeight(density, MIN_WEIGTH, MAX_WEIGTH);
        G[x][y] = G[y][x] = newEdge;
        cout << "Added new edge: " << x << ", " << y << " . Weight: " << newEdge << endl;
    }
}

inline void Graph::remove(int** G, int x, int y) {
    G[x][y] = 0;
}

inline int Graph::get_edge_value(int** G, int x, int y) {
    return G[x][y];
}

inline void Graph::set_edge_value(int** G, int x, int y, int value) {
    G[x][y] = G[y][x] = value;
}

void Graph::print_on_file(string filename) {
    ofstream outp(filename);
    
    outp << "Number of vertices: " << numVertices << ", number of edges: " << numEdges << endl;

    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            if(adjacencyMatrix[i][j]) {
                outp << i << '\t' << j << 't' << adjacencyMatrix[i][j] << '\t';
            }
        }
        
    }
    
}

int main() {
    
    Graph gr(SIZE, DENSITY);
    int** G = gr.get_graph();

    bool isConnected = gr.is_connected(G);

    cout << "Is the graph connected? " << isConnected << endl;

    gr.print_on_file("./graph_printed.txt");

    return 0;
}

