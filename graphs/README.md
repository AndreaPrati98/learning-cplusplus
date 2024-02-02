# C++ learning homework
The main goal is to implement the fameous Dijkstra's algo. Firstly, I need to write an (Abstract Data Type) ADT using C++. There are two options to represent the graph:
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
  
