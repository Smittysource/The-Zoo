/*
 *  TheZoo.h
 *
 *  David Smith
 *  CS 210
 *  December 9, 2020
 *
 *  This file contains the function declarations for the application TheZoo. This code uses the Animal, Mammal, Oviparous, Bat, Crocodile, Goose,
 *  Pelican, SeaLion, and Whale classes which are included through TheZoo.h. This code then creates a vector of pointers to the base class
 *  Animal to store information about each of the animals in the zoo. A function is included to generate the data file directly from user
 *  prompts using JNI interface with the ZooFileWriter class. Functions are also included to display a menu and get user input, add an animal
 *  to the vector, delete an animal from the vector, load animal data from file to the vector, write animal data from the vector to the file,
 *  and display the animal data on the screen.
 *
 */

#ifndef THEZOO_H_
#define THEZOO_H_

#include <iostream>						// Including for interaction with the user through cout and cin
#include <vector>						// Including to use a vector
#include <fstream>						// Including for file input and output using ifstream and ofstream
#include <string>						// Including for string manipulation
#include <jni.h>						// Including for interfacing with the Java Virtual Machine
#include "Bat.h"						// Bat class file
#include "Whale.h"						// Whale class file
#include "SeaLion.h"					// SeaLion class file
#include "Pelican.h"					// Pelican class file
#include "Goose.h"						// Goose class file
#include "Crocodile.h"					// Crocodile class file

// Enumeration for sub-types to correlate with the subclasses being used
enum SubType { unknown, bat, goose, pelican, crocodile, whale, sealion };

using namespace std;

// Provided function for generating a new zoodata file. This function uses a Java class ZooFileWriter.class to ask user for input and write data to "zoodata.txt"
void GenerateData();
// This function adds an animal to the zooAnimals vector
void AddAnimal(vector<Animal*>& zooAnimals);
// This function removes an animal from the vector based on Track#
void RemoveAnimal(vector<Animal*>& zooAnimals);
// This function loads the data into the vector from pre-existing file
bool LoadDataFromFile(vector<Animal*>& zooAnimals);
// This function saves the data from the vector to the file
bool SaveDataToFile(vector<Animal*>& zooAnimals);
// This function displays the data for all animals in the vector to the user
void DisplayAnimalData(vector<Animal*>& zooAnimals);
// Display the menu to the user
void DisplayMenu();
// Driver function for program. Displays the menu and then processes user command
bool Driver(vector<Animal*>& zooAnimals);
// This function prints 100 newline characters to clear the portion of the console that the user sees
void ClearScreen();
// This function checks whether the length of a string is longer than the maximum allowed
bool CheckLength(string inString, unsigned int maxLength);
// Check whether a number contains anything other than digits
bool CheckNumber(string inString);
// This function finds the index of an animal in the vector zooAnimals that has the Track# that is passed in as trackNumber
int FindIndex(vector<Animal*>& zooAnimals, int trackNumber);
// This function checks an input string for one of the sub-types available as subclasses of Animal.
SubType evaluateSubType(string subType);
// This function processes a zoo animal string into the vector. The string is formatted exactly the same as a line in the input or output file
bool processAnimal(vector<Animal*>& zooAnimals, string& buffer);
// This function deletes the pointers in the vector then erases each element in the vector
void emptyVector(vector<Animal*>& zooAnimals);
// This function returns padding characters in a string. If padChar is not used, the padding character used is ' '
string padString(int paddingNeeded, char padChar = ' ');

#endif /* THEZOO_H_ */
