#ifndef VERTEX2_H
#define VERTEX2_H

#include "Edge.h"
#include "DynArr.h"

#include <iostream>
#include <vector>

#define VECTOR std::vector

template<class T>
class Vertex{

	private:

		DynArr< Edge > edges;	// Contains all outgoing edges
		T data;					// The data stored in the Vertex
		bool valid;				// Mark as valid - False for Lazy Deletion

	public:

		// Default Constructor
		Vertex( ) : edges(), data( ), valid( true ) {}

		// Overloaded Constructor
		Vertex( const T& dataIn ) : edges(), data( dataIn ), valid( true ) {}

		// Get the Vertex data
		T get_vertex_value() const{

			return data;
		}

		// Set the Vertex Value
		void set_vertex_value(const T& dataIn){

			data = dataIn;
		}

		// Adding an Edge to a Vertex
		void add_edge( unsigned int destin, float weight ){

			// If not, put the edge on the back of the array
			edges.push_back( Edge(destin, weight) );

		}
	

		Edge get_edge( unsigned int edgeOrder ) {

			return edges[ edgeOrder ];
		}

		// Return the number of edges
		unsigned int num_edges() const{

			return (unsigned int)edges.size();
		}


		// Overloaded Friend Output Operator
		friend std::ostream& operator<<( std::ostream& output, const Vertex<T>& theVert ){

			// If the vertex is valid
			if( theVert.valid ){

				// Print the data element first
				output << "[" << theVert.data << ": ";

				//
				for( long unsigned int iter = 0; iter < theVert.edges.size(); iter++ ){

					// Print the destination
					output << "{" << theVert.edges[iter].destin << ", ";

					// Print the weight
					output << theVert.edges[iter].weight << "} ";

				}
				output << "]";

			}
			// If the vertex is not valid, indicate Lazy Deletion
			else{
				output << "[DELETED]";
			}

			return output;
		}

};

#endif
