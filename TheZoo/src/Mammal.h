/*
 *  Mammal.h
 *
 *  David Smith
 *  CS 210
 *  December 9, 2020
 *
 *  This file contains the class declaration for the class Mammal derived from the class Animal.
 *
 */

#ifndef MAMMAL_H_
#define MAMMAL_H_

#include "Animal.h"

// Class Mammal derived from class Animal
class Mammal: public Animal {
public:
	// Declare member methods and fields
	Mammal();									// Default constructor
	~Mammal();									// Default destructor
	void setNursing(int nursing);				// Mutator for nursing status
	int getNursing();							// Accessor for nursing status
	int getNumberOfEggs() {return 0;};			// Accessor for number of eggs. Mammals don't lay eggs, therefore return should always be 0.
	string toString();							// Returns a string with all of the mammal's information in the same format it is in in the file
	virtual void print();						// Print the animal's information to the screen
	void setNumberOfEggs(int numEggs) {};		// Mutator for number of eggs. Number of eggs is always 0 and retrieving that is handled in getNumberOfEggs. Ignore input

	int Nurse;									// Nursing status as int
}; // End class Mammal

#endif /* MAMMAL_H_ */
