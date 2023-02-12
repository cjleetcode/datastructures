/*
 *@author Caleb Lee, lab 105, Fall 2021
 *@version 1.0
 */


#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

#include "middleearth.h"
/*
 *@param me: middle earth file; start: first entry of list of cities to visit;
 *@param dests: list of cities to go to
 *@details computes the net distance amongst the places to visit, ending with the starting point
 *@return value of path length
 */
float computeDistance(MiddleEarth& me, const string& start, vector<string>& dests);
/*
 *@param start: first city/ starting point; dests: list of cities to go to
 *@details prints the cycle of cities to go to, returning to the original city at the end
 *@return path list
 */
string printRoute(const string& start, const vector<string>& dests);

int main(int argc, char** argv) {
    // check the number of parameters
    if (argc != 6) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }

    // we'll assume the parameters are all well-formed
    int width = stoi(argv[1]);
    int height = stoi(argv[2]);
    int num_cities = stoi(argv[3]);
    int rand_seed = stoi(argv[4]);
    int cities_to_visit = stoi(argv[5]);

    // create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);
    float f = 0;
    float f1 = 0;
    string st;
    bool firstCycle = true;
    sort(dests.begin() + 1, dests.end());
    do{
      string& sr = dests[0];
	f = computeDistance(me, sr, dests);
        if(firstCycle){
	  firstCycle = false;
	  f1 = f;
	  st = printRoute(sr, dests);
	  continue;
	}
	else{
	  if(f < f1){
	    f1 = f;
	    st = printRoute(sr, dests);
	    continue;
	  }
	}
    } while(next_permutation(dests.begin() + 1, dests.end()));
    // TODO: YOUR CODE HERE
    cout << "Minimum path has distance " << f1 << ": " << st << endl;
    return 0;
}

// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.
float computeDistance(MiddleEarth& me, const string& start, vector<string>& dests) {
    // TODO: YOUR CODE HERE
  float dist = 0;
  for(int i = 0; i < dests.size() - 1; i++){
    dist += me.getDistance(dests[i], dests[i + 1]);
  }
  dist += me.getDistance(dests[dests.size() - 1], start);
  return dist;
}

// This method will print the entire route, starting and ending at the
// 'start' parameter.
// The output should be similar to:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
string printRoute(const string& start, const vector<string>& dests) {
  //TODO: do thing
  string stor = "";
  for(string s: dests)
    stor += s + " -> ";
  stor += start;
  return stor;
}
