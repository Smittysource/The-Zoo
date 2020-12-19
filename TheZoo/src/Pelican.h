/*
 * Pelican.h
 *
 *  David Smith
 *  CS 210
 *  December 9, 2020
 *
 *  This file contains the class declaration for the class Pelican derived from the class Oviparous.
 *
 */

#ifndef PELICAN_H_
#define PELICAN_H_

#include "Oviparous.h"

// Class Crocodile derived from class Oviparous
class Pelican: public Oviparous {
public:
	// Declare member methods and fields
	Pelican();						// Default Constructor
	string toString();				// Returns a string with all of the mammal's information in the same format it is in in the file
	void print();					// Print the animal's information to the screen

	string type = "Pelican";		// Sub-type of animal as string
}; // End class Crocodile

#endif /* PELICAN_H_ */
