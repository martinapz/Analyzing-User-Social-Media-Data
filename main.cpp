/**
 * @file main.cpp
 * Implementation of the main class.
 * 
 */
#include "graph.h"
#include "readFile.h"
#include "algorithms.h"
#include <string>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    readFile f;
    Graph g = f.read("gowalla_data.txt");

    std::cout << "---------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "The adjacency list: " << std::endl;
    g.printAdjList();

    std::cout << "---------------------------------------------------------------------------------------------" << std::endl;
    // The shortest distance from NYC to Santa Cruz from the given 
    // Outputs 4139 km as the shortest distance from NYC to Santa Cruz
    std::cout << "The shortest distance between NYC and Santa Cruz: " << std::endl;
    Node santa_cruz;
    santa_cruz.latitude_ = 37;
    santa_cruz.longitude_ = -122;
    santa_cruz.index_ = 7;

    Node nyc;
    nyc.latitude_ = 40;
    nyc.longitude_ = -74;
    nyc.index_ = 2;

    int dist = Algorithms::shortestPath(g, nyc, santa_cruz);
    std::cout << "NYC -> Santa Cruz: " << dist << " km" << std::endl;
    
    std::cout << "---------------------------------------------------------------------------------------------" << std::endl;
    // Shows the most commonly visited location
    // Outputs Lat: 37 Long: -122 (Santa Cruz, CA)
    std::cout << "The most commonly visited location: " << std::endl;
    Node n = Algorithms::betweennessCentrality(g);
    std::cout << "Latitude: " << n.latitude_ << " Longitude: " << n.longitude_ << std::endl;
}