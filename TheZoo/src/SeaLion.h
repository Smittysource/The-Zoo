/*
 * SeaLion.h
 *
 *  David Smith
 *  CS 210
 *  December 9, 2020
 *
 *  This file contains the class declaration for the class SeaLion derived from the class Mammal.
 *
 */

#ifndef SEALION_H_
#define SEALION_H_

#include "Mammal.h"

// Class SeaLion derived from class Mammal
class SeaLion: public Mammal {
public:
	// Declare member methods and fields
	SeaLion();						// Default Constructor
	string toString();				// Returns a string with all of the mammal's information in the same format it is in in the file
	void print();					// Print the animal's information to the screen

	string type = "SeaLion";		// Sub-type of animal as string
}; // End class SeaLion

#endif /* SEALION_H_ */
