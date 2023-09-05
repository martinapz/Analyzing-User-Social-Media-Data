#pragma once
#include "graph.h"

class readFile {
    public:
    /**
     * @brief This will translate the raw data into a Graph 
     * representation that we can work with to discover 
     * things about the data.
     * 
     * @param txt_file the location of the data txt file
     * @return Graph a Graph representation of the given data
     */
    Graph read(string txt_file);
};