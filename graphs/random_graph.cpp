#include <iostream>
#include <ctime>

using namespace std;

const int SIZE = 4;
const double DENSITY = 0.3;

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
    // cout << (randomValue/100) << endl;

    return (randomValue/100) < probabilityTrue;

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
            // cout << "Cycle with i: " << i << " and j: "<< j << endl;
            
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

int main() {
    bool** graph = create_random_graph(SIZE, DENSITY);

    return 0;
}

