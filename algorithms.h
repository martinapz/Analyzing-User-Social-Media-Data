#pragma once
#include "graph.h"
#include <string>
#include <vector>
#include <map>
#include <climits>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;

class Algorithms {
    private:
    public:
        /**
         * @brief this returns the shortest distance between the start and end nodes.
         * 
         * @param graph the graph we are searching through
         * @param start the start Node 
         * @param end the end Node
         * @return int the shortest distance between the start and end node
         */
        static int shortestPath(Graph graph, Node start, Node end);

        /**
         * @brief returns the order of Breadth First Search starting with the start Node.
         * 
         * @param graph the graph we are searching through
         * @param start the start Node
         * @return vector<int> the vector of the indicies of the order of the traversal
         */
        static vector<int> BFSTraversal(Graph graph, Node start);

        /**
         * @brief returns a map of each Node mapped to how many times they have been passed through.
         * 
         * @param graph the graph we are searching through
         * @return map<Node, int> map of Nodes to the amount they are passed through between
         */
        static map<Node, int> floydWarshall(Graph graph);

        /**
         * @brief returns the Node passed through the most.
         * 
         * @param graph the graph we are searching through
         * @return Node the Node passed through the most
         */
        static Node betweennessCentrality(Graph graph);
};