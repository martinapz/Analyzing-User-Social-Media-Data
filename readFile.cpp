#include "readFile.h"
#include "graph.h"
#include <string>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>

void string_to_int(string s, int &i) {
    stringstream ss;  
    ss << s;  
    ss >> i;
}

Graph readFile::read(string txt_file) {
    Graph g;
    fstream newfile;
    newfile.open(txt_file,ios::in);
    if (newfile.is_open()){
        string l;
        int prior_p = -1;
        int prior_lat = -1000;
        int prior_long = - 1000;
        int prior_index = -1;
        
        // continues to translate the data into a Graph format while there are lines
        while(getline(newfile, l)){
            vector<string> result; 
            std::istringstream iss(l); 
            for(std::string s; iss >> s; ) {
                result.push_back(s); 
            }

            int person;
            int latitude;
            int longitude;

            string_to_int(result[0], person);
            string_to_int(result[2], latitude);
            string_to_int(result[3], longitude);

            // checking to see if theres a new person
            if(prior_p != person || (latitude == prior_lat && longitude == prior_long)) {
                prior_p = person;
                prior_lat = latitude;
                prior_long = longitude;
            } else {
                Node s;
                s.latitude_ = prior_lat;
                s.longitude_ = prior_long;

                Node end;
                end.latitude_ = latitude;
                end.longitude_ = longitude;

                g.insertNode(prior_lat, prior_long);
                g.insertNode(latitude, longitude);
                g.insertEdge(s, end, person);

                prior_lat = latitude;
                prior_long = longitude;
            }
            result.clear();
        }
        newfile.close(); //close the file object.
    }
    return g;
}