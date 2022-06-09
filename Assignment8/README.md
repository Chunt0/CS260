# Final Assignment

In driver.cpp you will see that I preconstruct a graph for you.
I used the example found on Geeks For Geeks

https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/

From this you can test Dijkstra's Algorithm, just pick a source and destination and
you will get the shortest path. You can add and remove vertices and edges as you wish,
each time you run Dijkstra's algo it will recalculate all paths from a source from
the graph as it is at that moment. Kruskal's minimum spanning tree works great. It uses
a map that stores each Vertex as a key and the value is a pair -> it's parent vertex and it's rank.
This map is used to check to see if a given edge would create a cycle by finding the absolute
parent, if they aren't the same then they wont create a cycle, then the rank is used to
determine which vertex points to which as it's parent.

Have a look and have fun. Feel free to build graphs to your choosing or modify the existing one 
using the menu.

To compile it just pull all files and enter:
g++ -g edge.cpp vertex.cpp graph.cpp driver.cpp -o graph

