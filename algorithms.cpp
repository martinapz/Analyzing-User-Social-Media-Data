#include "algorithms.h"
#include <queue> 

#define INF 99999

int Algorithms::shortestPath(Graph graph, Node start, Node end) {
    // creates a priority queue and distance vector with each value the max value
    priority_queue<pair<int, int>, vector <pair<int, int>> , greater<pair<int, int>> > pq;
    vector<float> dist(graph.getAdjList().size(), 0x3f3f3f3f);
  
    // since we are starting at start node, push that and show dist will be 0
    pq.push(make_pair(0, start.index_));
    dist[start.index_] = 0;
  
    while (!pq.empty()) {
        int curr_node_index = pq.top().second;
        pq.pop();
  
        // loop through all adjacent nodes
        for (unsigned i = 0; i < graph.getAdjList().at(graph.getIndexedNodes()[curr_node_index]).size(); i++) {
            Node n = graph.getAdjList().at(graph.getIndexedNodes()[curr_node_index])[i];

            int other_node_index = n.index_;
            float dist_a_b = Graph::getDistance(graph.getIndexedNodes()[curr_node_index], n);
            
            // compare to see if distance is better with other path
            if (dist[other_node_index] > dist[curr_node_index] + dist_a_b) {
                dist[other_node_index] = dist[curr_node_index] + dist_a_b;
                pq.push(make_pair(dist[other_node_index], other_node_index));
            }
        }
    }

    return dist[end.index_];
}

vector<int> Algorithms::BFSTraversal(Graph graph, Node start) {
    //Use queue to hold traversal order
    std::queue<Node> queue;
    map<Node, vector<Node>> adj_list = graph.getAdjList();
    //keeps track of the indexes of the traversal order
    vector<int> BFS_indexes;

    std::vector<bool> visited;
    visited.resize(adj_list.size(), false);
    
    
    visited.at(start.index_) = true;
    queue.push(start);
    BFS_indexes.push_back(start.index_);   

    while (!queue.empty()) {
        Node currentNode = queue.front();
        queue.pop();
        std::vector<Node> adjacentNodes = adj_list.at(currentNode);
        //adds the adjacent nodes into the queue if they have not been visited
        for (unsigned i = 0; i < adjacentNodes.size(); i++) {
            if (visited[adjacentNodes[i].index_] == false) {
                visited[adjacentNodes[i].index_] = true;
                queue.push(adjacentNodes.at(i));
                BFS_indexes.push_back(adjacentNodes.at(i).index_);
            }
        }
    }
    return BFS_indexes;
}

map<Node, int> Algorithms::floydWarshall(Graph graph) {
    
    vector<Node> indexed_nodes = graph.getIndexedNodes();
    int V = indexed_nodes.size();
    vector<vector<int>> dist(V, vector<int>(V));
  
    /* Set the initial values of dist to the shortest path
    between two nodes with no intermediate vertex. */

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            Node first = indexed_nodes[i];
            Node second = indexed_nodes[j];
            vector<Node> adjacencies = graph.getAdjList()[first];
            if (std::count(adjacencies.begin(), adjacencies.end(), second)){
                dist[i][j] = Algorithms::shortestPath(graph, first, second);
            }  else {
                dist[i][j] = INF;
            }
        }
    }
    
    //This maps each location to the number of times it has been passed through 
    map<Node, int> node_freq;
    for(Node node : graph.getIndexedNodes()) {
        node_freq.insert({node, 0});
    }

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // If vertex k is on the shortest path from
                // i to j, then update the value of dist[i][j]
                if (dist[i][j] > (dist[i][k] + dist[k][j])
                    && (dist[k][j] != INF
                        && dist[i][k] != INF)) {
                    node_freq[indexed_nodes[k]]++;
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    return node_freq;
}

Node Algorithms::betweennessCentrality(Graph graph) {
    map<Node, int> node_freq = floydWarshall(graph);

    //This returns the most frequently passed through location
    Node between;
    int freq = 0;

    map<Node, int>::iterator it;
    for (it = node_freq.begin(); it != node_freq.end(); it++)
    {
        if (it->second > freq) {
            freq = it->second;
            between = it->first;
        }
    }
    return between;
}
