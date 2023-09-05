Final Project Proposal

Location based online social network data set: 
http://snap.stanford.edu/data/loc-Gowalla.html

From our chosen data set, we can learn how many users have traveled from one 
location to the other. In this project, we hope to gain more insight into the 
traveling patterns between users based on their activity on Gowalla. 
Although we don’t have a specific problem we aim to solve, we hope to learn
more about how social media data can track individual users and learn more about 
the users through their location data.


With our dataset, we will download the data through the Stanford dataset website 
provided by the course staff. In terms of storing and parsing the data, we plan to 
parse it through JSON and store it as a user object that keeps track of where and 
when they have checked in. We are currently planning to parse the data only from 
travel within the US, but if we have more time we’d like to include other countries
as well and use that data to compare statistics from the US. We will handle potential
errors by discarding the data point that is associated with the error, this includes 
data points that are outside of the US longitude and latitude. 

Using social media login data, we’re going to find the amount of people that travel 
from point A to point B or vice versa. The graph vertices are locations with some 
error that will be represented as point objects. The edges are the people that travel
from A to B or from B to A. We will have a vector of either user objects or their 
ids to represent each edge.

We will be implementing a Breadth First Search (BFS) to find the place that has been 
traveled the most from A to B or vice versa with O(n + m) as our target efficiency. The 
input is the graph of location vertices and the edges are vectors of people. The output
is the points of two locations that people travel the most between.

We will also implement a shortest Path algorithm to find the shortest path taken between
two locations (O(n^2) for Dijkstra linear-search). The input is the two locations we want
to find the shortest path between. The output is the minimum number of vertices one needed
to pass through to get to the final location. 

The third algorithm that we plan on implementing will be Betweenness Centrality. We will be
implementing this using the Floyd-Warshall algorithm. The estimated running time of this
algorithm will be around O(V^3). The input of the algorithm will be the graph with the data associated
with the social media locatinons of its users, and the output will be a 2d vector of the 
shortest paths for each vertex. We will use this output to find the location that people
travelled through the most. 
 
Timeline:
Week 1 (Nov 8 - Nov 14)
- Create contact and project proposal & get it approved
- Acquire the data we are using here
   - http://snap.stanford.edu/data/loc-Gowalla.html 

Week 2 (Nov 15 - Nov 21)
- Process the data
- Create objects, method outlines and begin writing the methods
   - Test objects and any methods that are done

Week 3 (Nov 22 - Nov 28)
- Finish creating and testing the methods 

Week 4 (Nov 29 - Dec 5)
- Work on implementation of final algorithm
- Potentially Force-directed graph drawing
    - https://en.wikipedia.org/wiki/Force-directed_graph_drawing 

Week 5 (Dec 6 - Dec 12)
- Finish working on and and testing the Betweeness centrality algorithm and test 
other algorithms with larger test cases. 

Submit project by Dec 13th 
