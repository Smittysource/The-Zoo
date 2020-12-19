/*
 *  Bat.h
 *
 *  David Smith
 *  CS 210
 *  December 9, 2020
 *
 *  This file contains the class declaration for the class Bat derived from the class Mammal.
 *
 */

#ifndef BAT_H_
#define BAT_H_

#include "Mammal.h"

// Class Bat derived from class Mammal
class Bat: public Mammal {
public:
	// Declare member methods and fields
	Bat();								// Default Constructor
	string toString();					// Returns a string with all of the mammal's information in the same format it is in in the file
	void print();						// Print the animal's information to the screen

	string type = "Bat";				// Sub-type of animal as string
}; // End class Bat

#endif /* BAT_H_ */
