# C++ learning homework
> This homework assignment is from the course "C++ for C Programmers, Part A" by professor Ira Pohl.

The main goal is to implement the fameous [Dijkstra's algo](https://en.wikipedia.org/wiki/Dijkstra's_algorithm). Firstly, I need to write an (Abstract Data Type) ADT using C++. There are two options to represent the graph:
- edge list
- matrix

Moreover, there will be necessary to create a method that randomly generates the graph, therefore the set of edges with positive distances. The random graph will have an edge density parametner and distance range as a parameter. 
Density 0.1 would means the graph have 10% of its edges picked at random and the distance range will be used to randomly decide the cost of the edge.

Let's consider that:
- an edge will have a positive cost that is its distance. 
- the graph is <u>undirected</u>
  
## Turn in
- [ ] Create a procedure to randomly generate graph given a certain density and a distrance range.
- [ ] Implement the Dijkstra's algorithm.
- [ ] Using densities 20% and 40% on a graph with 50 nodes with distance range from 1.0 to 10.0 compute the average path length (using 49 paths). Omit the non-existing edges from the average.
- [ ] For a set of randomly generated graphs an average shortest path
  
## Recall of the algorithm
There are needed three basics abstractions: Graph, PriorityQueue and ShortestPath algo. It's needed to decide the naming convention for the vertices (V), by convention, generally they are mapped onto a set of integers in the range `0` -> `|V|-1`. 

Let's describe the interfaces.

### Interface Graph
This class will need:
- [ ] `V(G)`: return number of vertices in the graph.
- [ ] `E(G)`: returns number of edges in the graph.
- [ ] `adjacent(G, x, y)`: tests whether there is an edge from node x to node y.
- [ ] `neighbors(G, x)`: lists all nodes y such that there is an edge from x to y.
- [ ] `add(G, x, y)`: adds to G the edge from x to y, if it is not there.
- [ ] `delete(G, x, y)`: removes to G the edge from x to y, if it is not there.
- [ ] `get_node_value(G, x)`: returns the value associated with the node x.
- [ ] `set_node_value( G, x, a)`: sets the value associated with the node x to a.
- [ ] `get_edge_value( G, x, y)`: returns the value associated to the edge (x,y).
- [ ] `set_edge_value(G, x, y, v)`: sets the value associated to the edge (x,y) to v.

The main question is: how to represent the graph as a member ADT? Usually threre are two approaches: adjacency list and adjacency matrix (depending on the relative edge density). For sparse graphs, the list approach is more efficient but for dense graphs the matrix can be more eddificent. Moreover, there is also to think about how to add the weight to the edges, maybe considering it in the `add(G, x, y)` or maybe it would make sense to use a different DS and use the indexes to access it. 

The PriorityQueue is required to access the vertex with the next shortest link in the shortest path calculation at the top of the queue. Usually a [minHeap](https://en.wikipedia.org/wiki/Min-max_heap).

Considering the class PriorityQueue:
- [ ] `chgPriority(PQ, priority)`: changes the priority (node value) of queue element.
- [ ] `minPriority(PQ)`, removes the top element of the queue
- [ ] `contains(PQ, queue_element)`: does the queue contain queue_element.
- [ ] `insert(PQ, queue_element)`: insert queue_element into queue
- [ ] `top(PQ)`:returns the top element of the queue.
- [ ] `size(PQ)`: return the number of queue_elements.

The last class is the ShortestPathAlgo, which implements the algo itself. It requires both the previous presented classes' instances and an additional ADT to maintain the parent relationship of the shortest path.

Considering the class Shortest Path:
- [ ] `vertices(List)`: list of vertices in G(V,E).
- [ ] `path(u, w)`: find shortest path between u-w and returns the sequence of vertices representing shorest path u-v1-v2-…-vn-w.
- [ ] `path_size(u, w)`: return the path cost associated with the shortest path.

## Assumptions
- edges are undirected
- non-negative costs