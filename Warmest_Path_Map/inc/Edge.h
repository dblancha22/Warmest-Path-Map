#ifndef EDGE_H
#define EDGE_H

struct Edge{

	unsigned int destin;	// Location of Edge Destination
	float weight;				// Edge Weight. Can be negative.

	// Default Constructor
	Edge() : destin(), weight( ) {}

	// Overloaded Constructor
	Edge( unsigned int dest, float weightIn ) : destin(dest), weight(weightIn) {}

	// Overloaded == operator
	bool operator==( const Edge& rhs ) const{

		return destin == rhs.destin && weight == rhs.weight;

	}
};

#endif
