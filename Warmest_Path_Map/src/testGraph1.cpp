#include "../inc/Graph1.h"

#include <iostream>
#include <fstream>

#define COUT std::cout
#define ENDL std::endl
#define OFSTREAM std::ofstream

int main(int argc, char* argv[]){

	Graph< std::string > theGraph;
	
 if(argc == 3){

  std::ifstream my_file_buildings;
	my_file_buildings.open(argv[1]);
	std::string s1;

		while(std::getline(my_file_buildings,s1)){
			theGraph.add_vertex((const std::string) s1);
		}

	my_file_buildings.close();


	std::ifstream my_file_paths;
	my_file_paths.open(argv[2]);
	unsigned int orig, dest;
	float weight;

		while(my_file_paths>>orig>>dest>>weight)
			theGraph.add_edge(orig, dest, weight);
			

	 my_file_paths.close(); 
}


std::cout<<theGraph<<std::endl;

theGraph.Dijkstra(0,27);

	return 0;
}

