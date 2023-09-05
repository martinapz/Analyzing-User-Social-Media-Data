#include "graph.h"
#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

Graph::Graph(){}

void Graph::insertNode(int latitude, int longitude) {
    Node n;
    n.latitude_ = latitude;
    n.longitude_ = longitude;

    if (adj_list_.find(n) == adj_list_.end()) {
        //this node is not already in the adj list, so it must be added
        vector<Node> v;
        n.index_ = getNextIndex();
        nodes_to_indices.insert({n, n.index_});
        adj_list_.insert({n, v});
        indexed_nodes_.push_back(n);
    } else {
        //this node doesn't need to be re-added, but for the sake of adding futue edges, 
        //the index still needs to be accurate
        n.index_ = nodes_to_indices.at(n);
    }
}

int Graph::getNextIndex() {
    return ++next_index_;
}

map<Node, vector<Node>> Graph::getAdjList() {
    return adj_list_;
}

void Graph::insertEdge(Node s, Node end, int person) {
    Edge e;
    s.index_ = nodes_to_indices.at(s);
    end.index_ = nodes_to_indices.at(end);

    e.start_ = s;
    e.end_ = end;

    e.person_index_ = person;
    e.distance_ = getDistance(s, end);

    edges_.push_back(e);

    if(s.latitude_ == end.latitude_ && s.longitude_ == end.longitude_) {
        //don't add an edge if the start and end node are the same
    } else {
        //need to check and see if the adj list already has the node
        vector<Node> starts = adj_list_.at(s);
        vector<Node> ends = adj_list_.at(end);
        if(std::find(starts.begin(), starts.end(), end) != starts.end()) {
            /* starts contains end so don't add it again */
        } else {
            adj_list_.at(s).push_back(end);
        }

        if(std::find(ends.begin(), ends.end(), s) != ends.end()) {
            /* ends contains start so don't add it again */
        } else {
            adj_list_.at(end).push_back(s);
        }
    }
}

float Graph::getDistance(Node start, Node end) {
    //using the haversine equation to find the distance between two points using their longitude and latitude
    //this returns the distance in kilometers 
    float const mean_radius_of_earth = 6371.009; 

    float delta_lat = (end.latitude_ - start.latitude_) * M_PI / 180.0;
    float delta_long = (end.longitude_ - start.longitude_) * M_PI / 180.0;
        
    // convert to radians
    float start_latitude = (M_PI * start.latitude_) / 180;
    float end_latitude = (M_PI * end.latitude_) / 180;

    // apply formula
    float formula = pow(sin(delta_lat / 2), 2) + pow(sin(delta_long / 2), 2) * cos(start_latitude) * cos(end_latitude);
    return 2 * mean_radius_of_earth * asin(sqrt(formula));

}

void Graph::printAdjList() {
    for (auto const &pair: adj_list_) {
        std::cout << "{" << "(" << pair.first.longitude_ << ", " << pair.first.latitude_  << ")" << " index: " << pair.first.index_ << ": ";
        vector<Node> v = pair.second;
        for(size_t i = 0; i < v.size(); i++) {
            if(i != v.size() - 1) {
                cout << "(" << v[i].longitude_ << ", " << v[i].latitude_  << ")" << " index: " << v[i].index_ << ", ";
            } else {
                cout << "(" << v[i].longitude_ << ", " << v[i].latitude_  << ")" << " index: " << v[i].index_;
            }
            
        }
        cout << "}\n";
    }
}

vector<Node> Graph::getIndexedNodes() {
    return indexed_nodes_;
}