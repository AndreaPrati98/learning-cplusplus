#include <iostream>
#include <ctime>

using namespace std;

const int SIZE = 4;
const double DENSITY = 0.1;

void printMatrix(bool** const matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

inline bool randomBool(double probabilityTrue) {
    if (probabilityTrue > 1) 
    {
        cout << "Huston, we have a problem" << endl;
    }
    
    srand(clock()); 
    
    double randomValue = (rand() % 100);
    cout << (randomValue/100) << endl;
    return (randomValue/100) >= probabilityTrue;
    // return rand()/(RAND_MAX+1.0) < probabilityTrue;

    // // Generate a random value between 0 and 1
    // double randomValue = static_cast<double>(rand()) / (RAND_MAX + 1.0);
    // return randomValue < probabilityTrue;

}


bool** create_random_graph(int size, float density) {
    srand(clock());

    bool** graph = new bool*[size]; // creating a graph as a matrix

    // let's declare all the rows
    for (int i = 0; i < size; i++)
    {
        graph[i] = new bool[size];
    }
        

    for (int i = 0; i < size; ++i)
    {
        // now I add edges accordingly to density, the probability and edge exists
        for (int j = 0; j < size; j++) {
            cout << "Cycle with i: " << i << " and j: "<< j << endl;
            
            if (i == j) {
                
                graph[i][j] = false; // no loops
            } else {
                
                graph[i][j] = graph[j][i] = randomBool(density);;
            }
            
        }        
    }

    printMatrix(graph, size, size);

    return graph;
}

bool is_connected(bool *graph[], int size) {
    int old_size= 0, c_size = 0;
    bool* close = new bool[size];
    bool* open = new bool[size];

    for (int i = 0; i < size; i++)
    {
        /* code */
    }
    
    return 0;
}

int main() {
    bool** graph = create_random_graph(SIZE, DENSITY);

    return 0;
}

