/*
 *  Animal.cpp
 *
 *  David Smith
 *  CS 210
 *  December 9, 2020
 *
 *  This file contains the class definition for the class Animal. This class contains pure virtual functions getNumberOfEggs, getNursing, setNumberOfEggs, and setNursing
 *  which must be defined in any derived classes. Therefore, an instance of Animal cannot be created.
 *
 */

#include "Animal.h"

// Default constructor
Animal::Animal() {
	// Set default values for fields
	TrackNum = -1;
	Name = "";
} // End default constructor

// Mutator method to set the animals Track#
void Animal::setTrackNum(int inTrackNum) {
	// Set TrackNum field to input inTrackNum
	TrackNum = inTrackNum;
} // End setTrackNum

// Accessor method to get the animals Track#
int Animal::getTrackNum() {
	// Return field TrackNum
	return TrackNum;
} // End getTrackNum

// Mutator method to set the animal's name
void Animal::setName(string inName) {
	// Set field Name to input inName
	Name = inName;
} // End setName

// Accessor method to set the animal's name
string Animal::getName() {
	// Return field Name
	return Name;
} // End getName

// Returns a string with all of the animal's information in the same format it is in in the file
string Animal::toString() {
	// Declare local variable
	string buffer;						// Current text buffer as string

	// Set buffer to the string version of TrackNum
	buffer = to_string(TrackNum);
	// Get padding and set buffer equal to the padding with the previous contents of buffer concatenated to the end
	buffer = padString(TRACK_LENGTH - buffer.size(), '0') + buffer;
	// Concatenate Name plus padding to buffer
	buffer += Name + padString(NAME_LENGTH - Name.size());
	// Return the buffer
	return buffer;
} // End toString

// Utility method to add characters to a string for output
string Animal::padString(int paddingNeeded, char padChar) {
	// Declare local variable
	string buffer = "";					// Current text buffer as string initialized to empty

	// Loop paddingNeeded times
	for(int index = 0; index < paddingNeeded; index++) {
		// Concatenate the padChar to the buffer
		buffer += padChar;
	} // End for
	// Return the buffer
	return buffer;
} // End padString
