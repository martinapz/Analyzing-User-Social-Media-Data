#pragma once
#include <map>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

/**
 * The node struct represents each location in the data set. It is defined by its latitude and longitude. 
 */
struct Node {
    int index_;
    float latitude_;
    float longitude_;

    bool operator<(const Node &other) const {
        //first, go by latidudes
        if(std::floor(latitude_) < std::floor(other.latitude_)) {
            return true;
        } else if (std::floor(latitude_) == std::floor(other.latitude_)) {
            //if latidues are the same, go by longitudes
            if(std::floor(longitude_) < std::floor(other.longitude_)) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    bool operator==(const Node &other) const{
        if(longitude_ == other.longitude_ && latitude_ == other.latitude_ && index_ == other.index_) {
            return true;
        } else {
            return false;
        }
    }
};

    
/**
 * The edge struct is an edge that is created between two points when a person has travelled between these two points. The edge struct 
 * contains the two points it connects as well as the distance between the two points. 
 */
struct Edge {
    int person_index_;
    Node start_;
    Node end_;
    int distance_; 
};

/**
 * The graph class holds the functions used to create and fill the structures for the graph. 
 */
class Graph {
    public:
        /**
         * @brief Construct a new Graph object
         */
        Graph();

        /**
         * @brief inserts a Node if it is not already there.
         * 
         * @param latitude the new latitude
         * @param longitude the new longitude
         */
        void insertNode(int latitude, int longitude);

        /**
         * @brief inserts an edge between two nodes if one does not already exist for that person.
         * 
         * @param start start node
         * @param end end node 
         * @param person the index of the person
         */
        void insertEdge(Node start, Node end, int person);

        /**
         * @brief returns the distance between the two nodes
         * 
         * @param start start location
         * @param end end location
         * @return float distance between the two nodes
         */
        static float getDistance(Node start, Node end);

        /**
         * @brief prints out the adjacency list of the graph
         */
        void printAdjList();

        /**
         * @brief Get the Indexed Nodes object
         * 
         * @return vector<Node> a vector of Nodes that are at the index of their own index
         *         ex. Node of index 1 will be at position 1.
         */
        vector<Node> getIndexedNodes();

        /**
         * @brief Get the Adj List object
         * 
         * @return map<Node, vector<Node>> the adjacency list of the graph
         */
        map<Node, vector<Node>> getAdjList();

        /**
         * @brief returns the next index of the next new Node
         * 
         * @return int the next index
         */
        int getNextIndex();

    private:
        //keeps track of how many different nodes there are
        int next_index_ = -1;

        //adjacency list maps a node to a vector that holds all of its adjacent nodes
        map<Node, vector<Node>> adj_list_;

        //A vector that holds the indexes of each node
        vector<Node> indexed_nodes_;

        //Vector that holds all the edges of the graph
        vector<Edge> edges_;

        //Map that maps nodes to their indexes
        map<Node, int> nodes_to_indices;
};