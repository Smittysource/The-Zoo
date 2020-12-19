/*
 * Oviparous.h
 *
  *  David Smith
 *  CS 210
 *  December 9, 2020
 *
 *  This file contains the class declaration for the class Oviparous derived from the class Animal.
 *
 */

#ifndef OVIPAROUS_H_
#define OVIPAROUS_H_

#include "Animal.h"

// Class Oviparous derived from class Animal
class Oviparous: public Animal {
public:
	// Declare member methods and fields
	Oviparous();							// Default constructor
	void setNumberOfEggs(int numEggs);		// Mutator for number of eggs.
	int getNumberOfEggs();					// Accessor for number of eggs.
	int getNursing() {return 0;};			// Accessor for nursing status. Oviparous animals don't nurse. Returning not nursing.
	string toString();						// Returns a string with all of the oviparous animal's information in the same format it is in in the file
	void print();							// Print the animal's information to the screen
	void setNursing(int nurse) {};			// Mutator for nursing status. Oviparous animals don't nurse. Ignoring input.

	int NumberOfEggs;						// Number of eggs as int
}; // End Class Oviparous

#endif /* OVIPAROUS_H_ */
