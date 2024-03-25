#ifndef GRAPH1_H
#define GRAPH1_H

#include "stack.h"
#include "DynArr.h"
#include "Vertex2.h"
#include <iostream>
#include <vector>

#define VECTOR std::vector

template<class T>
class Graph{

	private:
		DynArr< Vertex< T > > vertices;	// Adjacency List

	public:
		// Constructor
		Graph( ) : vertices() {}

		// Add a vertex prior to any edges
		void add_vertex( const T& vertexData ){

			Vertex<T> theVertex( vertexData );
			vertices.push_back( theVertex );
		}

		// Add Edge from Origin to Destination, with weight
		void add_edge(unsigned int origin, unsigned int destin, float weight ){

			if( origin < vertices.size() && destin < vertices.size() ){

				vertices[origin].add_edge( destin, weight );

			}
		}


		// Dijkstra's Algorithm
		void Dijkstra( unsigned int origin, unsigned int destin ){

					if( origin >= vertices.size() || destin >= vertices.size() || vertices.size() == 0 ){

						std::cout << "Invalid Inputs" << std::endl;
						return;

					}

					/* Initialize the Elements */
					stack< unsigned int > theStack;
					DynArr< unsigned int > parents( vertices.size() );
					DynArr< float > distance;
					stack< unsigned int > finalPath;

					bool found = false;

					/* Initialize the origin */
					theStack.push( origin );
					distance[origin] = 0;
					parents[origin] = -1;

					if( destin == origin ){
						found = true;
					}

					if( !found ){

						/* Initialize all the distances after the origin */
						for( unsigned int iter = 1; iter < vertices.size(); iter++ ){
							// Make it the largest possible int
							distance[ iter ] = (float)2147483647;
							// Set the parent to -1
							parents[ iter ] = -1;
						}

						/* Run the shortest path algorithm */
						while( !theStack.empty() ){

							// Get the top element of the stack and pop
							unsigned int index = theStack.top();
							theStack.pop();

							// Evaluate the edges from the vertex
							for(unsigned int iter = 0; iter < vertices[ index ].num_edges(); iter++ ){

								// Obtain the edge
								Edge tempEdge = vertices[ index ].get_edge( iter );

								// If the weight of the edge plus distance of the  distance is less than the destin weight
								if( distance[ index ] + tempEdge.weight < distance[ tempEdge.destin ] ) {

									// Update the distance
									distance[ tempEdge.destin ] = distance[ index ] + tempEdge.weight;

									// Update the parent of the destin
									parents[ tempEdge.destin ] = index;

									// Check if destin is the result;
									if( tempEdge.destin == destin && !found ){

										found = true;
									}

									theStack.push( tempEdge.destin );
								}
							}
						}
					}

					// Otherwise, go through the parents until we find the origin
					if( found ){

						unsigned int sentinel = destin;
						finalPath.push( sentinel );		// Push the desination onto the stack

						while( parents[sentinel] != -1 ){

							finalPath.push( parents[sentinel] );	// Push the parent onto the stack
							sentinel = parents[sentinel];			// Update the sentinel

						}

						// Stack contains the correct order
						std::cout << "The valid Dijkstra path from 0 to " << destin << " is: ";
						while( !finalPath.empty() ){

							std::cout << finalPath.top() << " ";
							finalPath.pop();
						}
						std::cout << ", and the distance is " << distance[destin] << std::endl;
						std::cout << std::endl;
					}

				}

	// Overloaded Operator - Provided for the students
		friend std::ostream& operator<<( std::ostream& output, const Graph<T>& theGraph ){

			for( unsigned int iter = 0; iter < theGraph.vertices.size(); iter++ ){

				output << iter << ": " << theGraph.vertices[ iter ] << std::endl;

			}

			return output;
		}
};

#endif
