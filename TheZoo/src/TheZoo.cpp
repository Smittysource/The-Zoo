/*
 *  TheZoo.cpp
 *
 *  David Smith
 *  CS 210
 *  December 9, 2020
 *
 *  This file contains the driver code for the application TheZoo. This code uses the Animal, Mammal, Oviparous, Bat, Crocodile, Goose,
 *  Pelican, SeaLion, and Whale classes which are included through TheZoo.h. This code then creates a vector of pointers to the base class
 *  Animal to store information about each of the animals in the zoo. A function is included to generate the data file directly from user
 *  prompts using JNI interface with the ZooFileWriter class. Functions are also included to display a menu and get user input, add an animal
 *  to the vector, delete an animal from the vector, load animal data from file to the vector, write animal data from the vector to the file,
 *  and dispaly the animal data on the screen.
 *
 */

#include "TheZoo.h"

// Entry point for program execution
int main() {
	// Local variable declaration
	vector<Animal*> zooAnimals;				// Vector of pointers to base class Animal for storing animal data
	// Loop while there are no serious errors or user choosing to quit
	while(Driver(zooAnimals));
	// Safely remove all animals from the vector
	emptyVector(zooAnimals);
	// Exit program
	return 1;
} // End main

// Driver function for program. Displays the menu and then processes user command
bool Driver(vector<Animal*>& zooAnimals) {
	// Declare local variables
	char command = 'q';						// Command from user as char. Initialized to 'q' to quit
	bool saveStatus = false;				// Did save complete successfully as bool

	// Display the menu
	DisplayMenu();
	// Get command from the user
	cin >> command;
	// Ignore input to clear newline
	cin.ignore();
	// Evaluate the command entered by user. Each number option in the menu is tested.
	switch(command) {
	// 1 - Generate Data
	case '1':
		// Prompt to verify file destruction
		cout << "Are you sure you want to generate new data? This will erase current zoo animal file. Please type Y or N and then press enter." << endl;
		// Get response from user
		cin >> command;
		// Ignore input to clear newline
		cin.ignore();
		// If user didn't answer yes
		if(command != 'Y' && command != 'y') {
			// Notify user of cancellation of creating new data
			cout << "Canceling creating new data and file. Press enter to continue." << endl;
			// Ignore waits for user to press enter
			cin.ignore();
			// Cancel creating new file and return with continue command
			return true;
		} // End if
		// Clear the screen
		ClearScreen();
		// Display the prompts, get input from user, and save to file
		GenerateData();
		// Clear the screen
		ClearScreen();
		// Exit driver with continue status
		return true;
		// Break statement to keep execution from entering next case
		break;
	// 2 - Load Animal Data
	case '2':
		// Clear the screen
		ClearScreen();
		// If there are currently animals stored in zooAnimals vector
		if(!zooAnimals.empty()) {
			// Prompt to verify overwrite of current data in vector
			cout << "Are you sure you want to overwrite working data with data from file? Press Y or N and then press enter." << endl;
			// Get response from user
			cin >> command;
			// Ignore input to clear newline
			cin.ignore();
			// If user didn't answer yes
			if (command != 'Y' || command != 'y') {
				// Notify user of load cancellation
				cout << "Canceling loading file. Press enter to continue." << endl;
				// Ignore waits for user to press enter
				cin.ignore();
				// Return continue status
				return true;
			} // End if
		} // End if
		// Load the animal data from the file. If the data in the file is corrupted
		if(!LoadDataFromFile(zooAnimals)) {
			// Return with exit code
			return false;
		} // End if
		// Notify user that enter must be pressed to continue
		cout << endl << "Press enter to continue." << endl;
		// Ignore causes execution to wait for user to press enter
		cin.ignore();
		// Clear the screen
		ClearScreen();
		// Exit driver with continue status
		return true;
		// Break statement to keep execution from entering next case
		break;
	// 3 - Display Animal Data
	case '3':
		// Clear the screen
		ClearScreen();
		// Display the data for all animals in the zoo
		DisplayAnimalData(zooAnimals);
		// Notify user that enter must be pressed to continue
		cout << endl << "Press enter to continue." << endl;
		// Ignore causes execution to wait for user to press enter
		cin.ignore();
		// Clear the screen
		ClearScreen();
		// Exit driver with continue status
		return true;
		// Break statement to keep execution from entering next case
		break;
	// 4 - Add Record
	case '4':
		// Clear the screen
		ClearScreen();
		// Add an animal to the zoo data
		AddAnimal(zooAnimals);
		// Notify user that enter must be pressed to continue
		cout << endl << "Press enter to continue." << endl;
		// Ignore causes execution to wait for user to press enter
		cin.ignore();
		// Clear the screen
		ClearScreen();
		// Exit driver with continue status
		return true;
		// Break statement to keep execution from entering next case
		break;
	// 5 - Delete Record
	case '5':
		// Clear the screen
		ClearScreen();
		// Remove an animal from the zoo
		RemoveAnimal(zooAnimals);
		// Notify user that enter must be pressed to continue
		cout << endl << "Press enter to continue." << endl;
		// Ignore causes execution to wait for user to press enter
		cin.ignore();
		// Clear the screen
		ClearScreen();
		// Exit driver with continue status
		return true;
		// Break statement to keep execution from entering next case
		break;
	// 6 - Save Animal Data
	case '6':
		// Clear the screen
		ClearScreen();
		// Prompt to verify file overwrite
		cout << "Are you sure you want to save the current data? This will overwrite the current zoo animal file. Please type Y or N and then press enter." << endl;
		// Get response from user
		cin >> command;
		// Ignore input to clear newline
		cin.ignore();
		// If user didn't answer yes
		if(command != 'Y' && command != 'y') {
			// Cancel overwriting file and return with continue command
			return true;
		} // End if
		// Save the current data in to the file
		saveStatus = SaveDataToFile(zooAnimals);
		// If saving to file was successful
		if(saveStatus) {
			// Notify user of success
			cout << "Save successfully completed." << endl;
		} // End if
		// Notify user that enter must be pressed to continue
		cout << endl << "Press enter to continue." << endl;
		// Ignore causes execution to wait for user to press enter
		cin.ignore();
		// Clear the screen
		ClearScreen();
		// If saving to file was not successful
		if(!saveStatus) {
			// Exit driver with exit status
			return false;
		} // End if
		// Exit driver with continue status
		return true;
		// Break statement to keep execution from entering next case
		break;
	// 7 - Quit
	case '7':
		// Clear the screen
		ClearScreen();
		// Exit driver with quit status
		return false;
		// Break statement to keep execution from entering next case
		break;
	// Default - any other command was entered
	default:
		// Notify user that command entered was invalid
		cout << "Invalid selection. Try again." << endl;
		// Exit driver with continue status
		return true;
		// Break statement to keep execution from entering next case
		break;
	} // End switch
	// Return with continue status
	return true;
} //  End Driver

// Display the menu to the user
void DisplayMenu() {
	// Display the options menu
	cout << endl << endl << "What would you like to do?" << endl
		 << "(1) Generate Data" << endl
		 << "(2) Load Animal Data" << endl
		 << "(3) Display Animal Data" << endl
		 << "(4) Add Record" << endl
		 << "(5) Delete Record" << endl
		 << "(6) Save Animal Data" << endl
		 << "(7) Quit." << endl
		 // Prompt for user command
		 << "Type the number corresponding to your selection and press enter." << endl;
} // End DisplayMenu()

// Add an animal to the zooAnimals vector
void AddAnimal(vector<Animal*>& zooAnimals) {
	// Declare local variables
	string buffer;						// Buffer to hold working text as string
	string inputBuffer;					// Buffer to hold user input as string
	string name;						// Animal's name as string
	SubType type;						// Sub-type of animal as SubType

	// Prompt user for Track#
	cout << "What is the Track# for the animal you wish to add?" << endl;
	// Get Track# from user
	getline(cin,inputBuffer);
	// Check if Track# entered is not a number
	if(!CheckNumber(inputBuffer)) {
		// Notify user that Track# must be a number
		cout << "Track# must be only digits. Canceling adding animal.";
		// Exit function
		return;
	} // End if
	// Check if Track# is too long
	if(!CheckLength(inputBuffer, Animal::TRACK_LENGTH)) {
		// Notify user that Track# is too long
		cout << "Track# cannot be more than " << Animal::TRACK_LENGTH << " digits. Canceling adding animal.";
		// Exit function
		return;
	} // End if
	// Set working text to Track# with leading zeros fill to length of Animal::TRACK_LENGTH
	buffer = padString(Animal::TRACK_LENGTH - inputBuffer.length(), '0') + inputBuffer;
	// Prompt user for animal's name
	cout << "What is the name of the animal?" << endl;
	// Get animal's name from user
	getline(cin,inputBuffer);
	// Check if animal's name is too long
	if(!CheckLength(inputBuffer, Animal::NAME_LENGTH)) {
		// Notify user that animal's name is too long
		cout << "Animal name cannot be longer than " << Animal::NAME_LENGTH << " characters. Canceling adding animal.";
		// Exit function
		return;
	} // End if
	// Concatenate animal's name to end of buffer
	buffer += inputBuffer + padString(Animal::NAME_LENGTH - inputBuffer.size());
	// Set name variable to animal's name to use in the next prompts
	name = inputBuffer;
	// Prompt for animal's sub-type. Type can be inferred from sub-type
	cout << "What sub-type is " << name << "?" << endl;
	// Get sub-type from user
	getline(cin,inputBuffer);
	// Check if sub-type is too long
	if(!CheckLength(inputBuffer, Animal::SUB_LENGTH)) {
		// Notify user that sub-type is too long
		cout << "Sub-type cannot be longer than " << Animal::SUB_LENGTH << " characters. Canceling adding animal.";
		// Exit function
		return;
	} // End if
	// Convert sub-type into SubType enumeration
	type = evaluateSubType(inputBuffer);
	// Evaluate animal type based on animal sub-type
	switch(type) {
	// If the animal is a bat, whale, or sealion
	case bat:
	case whale:
	case sealion:
		// Then it is a mammal. Concatenate Mammal to end of buffer with padding fill to Animal::TYPE_LENGTH
		buffer += "Mammal" + padString(Animal::TYPE_LENGTH - 6);
		// End case
		break;
	// If the animal is a goose, pelican, or crocodile
	case goose:
	case pelican:
	case crocodile:
		// Then it is oviparous. Concatenate Oviparous to end of buffer with padding fill to Animal::TYPE_LENGTH
		buffer += "Oviparous" + padString(Animal::TYPE_LENGTH - 9);
		// End case
		break;
	// If animal sub-type is unknown or any other case not specified
	case unknown:
	default:
		// Notify user of errer
		cout << "Unknown animal sub-type. Canceling adding animal.";
		// Exit function
		return;
	} // End switch
	// Concatenate sub-type to buffer with padding to fill to Animal::SUB_LENGTH
	buffer += inputBuffer + padString(Animal::SUB_LENGTH - inputBuffer.size());
	// Prompt for number of eggs
	cout << "How many eggs does " << name << " have?" << endl;
	// Get number of eggs from user
	getline(cin,inputBuffer);
	// Check if number of eggs is not a number
	if(!CheckNumber(inputBuffer)) {
		// Notify user that number of eggs must be a number
		cout << "Number of eggs must be only digits. Canceling adding animal.";
		// Exit function
		return;
	} // End if
	// Concatenate number of eggs to end of buffer
	buffer+=inputBuffer;
	// Ask user for nursing status
	cout << "Is " << name << " nursing? Press Y or N and press Enter." << endl;
	// Get nursing status from user
	getline(cin, inputBuffer);
	// If the animal is nursing
	if(inputBuffer.at(0) == 'Y' || inputBuffer.at(0) == 'y') {
		// Concatenate 1 with a leading space to buffer
		buffer += " 1";
	} // End if
	// Otherwise, the animal is not nursing
	else {
		// Concatenate 0 with a leading space to buffer
		buffer += " 0";
	} // End else
	// Prompt user to verify adding animal to vector
	cout << "Are you sure you want to add this animal to the current data?" << endl;
	// Get verification from user
	cin >> inputBuffer;
	// If user did not select yes
	if(inputBuffer.at(0) != 'Y' && inputBuffer.at(0) != 'y') {
		// Notify user of cancelation
		cout << "Canceling adding animal";
		// Exit function
		return;
	} // End if
	// If the buffer processes into the vector successfully
	if(processAnimal(zooAnimals, buffer)) {
		// Notify user that
		cout << "Animal added successfully.";
	} // End if
	// Otherwise, it did not process successfully
	else {
		// Notify user of error
		cout << "Unable to add animal.";
	} // End else
	// Exit function
	return;
} // End Driver

// This function removes an animal from the vector based on Track#
void RemoveAnimal(vector<Animal*>& zooAnimals) {
	// Declare local variables
	string trackNumber;										// Track# as string
	int index;												// Index in vector of animal with Track# as int
	int trackNum;											// Track# as int

	// If the vector is empty
	if(zooAnimals.empty()) {
		// Notify user that there are no animals to delete
		cout << "There are no zoo animals in the data.";
		// Exit function
		return;
	} // End if
	// Prompt user for Track# of animal to delete
	cout << "What is the Track# of the animal whose record you wish to delete?" << endl;
	// Get Track# from user
	getline(cin, trackNumber);
	// If Track# is too long
	if(!CheckLength(trackNumber,Animal::TRACK_LENGTH)) {
		// Notify user of error
		cout << "That Track# is too long. ";
		// Exit function
		return;
	} // End if
	// If Track# is empty
	else if(trackNumber.length() == 0) {
		// Notify user of error
		cout << "That Track# is too short. ";
		// Exit function
		return;
	} // End else if
	// Convert Track# string to int
	trackNum = stoi(trackNumber);
	// Find the index of the animal that has Track#
	index = FindIndex(zooAnimals, trackNum);
	// If the index indicates that the animal was not found
	if(index == -1) {
		// Notify user of error
		cout << "That Track# was not found in the data. ";
	} // End if
	// Otherwise, the animal with Track# was found
	else {
		// Delete the data from the pointer
		delete zooAnimals.at(index);
		// Remove the pointer from the vector
		zooAnimals.erase(zooAnimals.begin()+index);
		// Notify user of deletion
		cout << "Animal successfully deleted.";
	} // End else
} // End RemoveAnimal

// This function loads the data into the vector from pre-existing file
bool LoadDataFromFile(vector<Animal*>& zooAnimals) {
	// Declare local variables
	ifstream input;							// Input stream from file as ifstream
	string buffer;							// Buffer of data from file as string

	// Open the input file
	input.open("zoodata.txt");
	// If the file did not open
	if(!input.is_open()) {
		// Notify user of error
		cout << "Unable to open zoodata.txt. Terminating loading data. Press enter to continue." << endl;
		// Exit function
		return true;
	} // End if
	// Delete all pointers in the vecter, then remove them from the vector
	emptyVector(zooAnimals);
	// While the end of the file has not been reached
	while(!input.eof()) {
		// Get the next line in the file
		getline(input,buffer);
		// If the line is empty (The last output in the Java creation of the file has a newline)
		if(buffer.size() == 0) {
			// Continue to top of loop and check loop condition
			continue;
		} // End if
		// If the buffer is smaller than the minimum size length of a line. This number is achieved by adding all of the Animal::"field"_LENGTHs plus 3 for eggs and nursing and a space between
		if(buffer.length() < 54) {
			// Notify user of bad input file
			cout << "Data in file is not in proper format. Program terminating. Press enter to end." << endl;
			// Close the input file
			input.close();
			// Return with exit code
			return false;
		} // End if
		processAnimal(zooAnimals, buffer);
	} // End while
	// Close the input file
	input.close();
	// Notify user of success
	cout << "Data successfully loaded from file.";
	// Return continue code
	return true;
} // End LoadDataFromFile

// This function saves the data from the vector to the file
bool SaveDataToFile(vector<Animal*>& zooAnimals) {
	// Declare local variable
	ofstream outFS;							// Output file stream as ofstream

	// Open the file to be written
	outFS.open("zoodata.txt");
	// If the file did not open
	if(!outFS.is_open()) {
		// Notify user of error
		cout << "Unable to open zoodata.txt for writing. Program terminating.";
		// Exit function
		return false;
	} // End if
	// Loop through the vector
	for(unsigned int index = 0; index < zooAnimals.size();index++) {
		// Output the animal's toString result with a newline to the output file stream
		outFS << zooAnimals.at(index)->toString() << endl;
	} // End for
	// Close the output file
	outFS.close();
	// Exit function
	return true;
} // End SaveDataToFile

// This function displays the data for all animals in the vector to the user
void DisplayAnimalData(vector<Animal*>& zooAnimals) {
	// If the vector is empty
	if(zooAnimals.empty()) {
		// Notify user of error
		cout << "There are no animals in the zoo data." << endl;
		// Exit function
		return;
	} // End if
	// Print header
	cout << left << setfill(' ') << setw(Animal::PADDING) << ""
		 << setw(Animal::TRACK_LENGTH + Animal::PADDING) << "Track #"
		 << setw(Animal::NAME_LENGTH + Animal::PADDING) << "Name"
		 << setw(Animal::TYPE_LENGTH + Animal::PADDING) << "Type"
		 << setw(Animal::SUB_LENGTH + Animal::PADDING) << "Sub-type"
		 << setw(Animal::INT_LENGTH + Animal::PADDING) << "Eggs"
		 << setw(Animal::INT_LENGTH + Animal::PADDING) << "Nurse" << endl;
	// Loop through the vector
	for(unsigned int index = 0; index < zooAnimals.size(); index++) {
		// Use the animal subclasses' print methods to display the animal's information to the user
		zooAnimals.at(index)->print();
		// Move to next line
		cout << endl;
	} // End for
} // End DisplayAnimalData

// This function processes a zoo animal string into the vector. The string is formatted exactly the same as a line in the input or output file
bool processAnimal(vector<Animal*>& zooAnimals, string& buffer) {
	// Declare local variables
	Animal* currentAnimal = nullptr;														// Current animal as Animal*
	int indexOfSpaceEggsNurse;																// Index of the space between number of eggs and nursing status in the string as int
	int subTypeIndex = Animal::TRACK_LENGTH + Animal::NAME_LENGTH + Animal::TYPE_LENGTH;	// Index of the sub-type data in the string based on width of fields as int
	string subBuffer;																		// Sub-type as string
	SubType type;																			// Sub-type as SubType enumeration

	// Get sub-type string from input string
	subBuffer = buffer.substr(subTypeIndex, Animal::SUB_LENGTH);
	// Get sub-type as SubType enumeration
	type = evaluateSubType(subBuffer);

	// Switch the sub-type to create pointer to correct subclass
	switch(type) {
	// If the sub-type is a bat
	case bat:
		// Assign current animal to point to a new Bat
		currentAnimal = new Bat();
		break;
		// If the sub-type is a whale
	case whale:
		// Assign current animal to point to a new Whale
		currentAnimal = new Whale();
		break;
		// If the sub-type is a sealion
	case sealion:
		// Assign current animal to point to a new SeaLion
		currentAnimal = new SeaLion();
		break;
		// If the sub-type is a pelican
	case pelican:
		// Assign current animal to point to a new Pelican
		currentAnimal = new Pelican();
		break;
		// If the sub-type is a crocodile
	case crocodile:
		// Assign current animal to point to a new Crocodile
		currentAnimal = new Crocodile();
		break;
		// If the sub-type is a goose
	case goose:
		// Assign current animal to point to a new Goose
		currentAnimal = new Goose();
		break;
		// If the sub-type is unknown or any other sub-type
	case unknown:
	default:
		// Notify user of error
		cout << "Unknown type of animal. Canceling process.";
		// If currentAnimal has been assigned a pointer to a subclass
		if(currentAnimal != nullptr) {
			// Delete the pointer
			delete currentAnimal;
		} // End if
		// Exit function
		return false;
	} // End switch
	// Set currentAnimal's Track#. Track# is the first Animal::TRACK_LENGTH characters of the input string
	currentAnimal->setTrackNum(stoi(buffer.substr(0, Animal::TRACK_LENGTH)));
	// Set currentAnimal's Name. Animal's name is Animal::NAME_LENGTH characters long and comes after Track#
	currentAnimal->setName(buffer.substr(Animal::TRACK_LENGTH, Animal::NAME_LENGTH));
	// Find the index of the space between number of eggs and nursing status. Number of eggs is at index subTypeIndex + Animal::SUB_LENGTH
	indexOfSpaceEggsNurse = buffer.find(' ', subTypeIndex + Animal::SUB_LENGTH);
	// Set currentAnimal's number of eggs. The eggs data begins at sub-type index + Animal::SUB_LENGTH and ends at the character before the space between number of eggs and nursing status
	currentAnimal->setNumberOfEggs(stoi(buffer.substr(subTypeIndex + Animal::SUB_LENGTH, buffer.size() - 1 - indexOfSpaceEggsNurse)));
	// Set currentAnimal's nursing status. The nursing status data begins at the character after the space between number of eggs and nursing status and ends at the end of the string.
	currentAnimal->setNursing(stoi(buffer.substr(indexOfSpaceEggsNurse + 1, (buffer.size() - 1 - indexOfSpaceEggsNurse))));
	// Add the currentAnimal to the vector zooAnimals
	zooAnimals.push_back(currentAnimal);
	// Stop referencing the animal since it is now referenced in the vector
	currentAnimal = nullptr;
	// Exit function
	return true;
} // End processAnimal

// This function finds the index of an animal in the vector zooAnimals that has the Track# that is passed in as trackNumber
int FindIndex(vector<Animal*>& zooAnimals, int trackNumber) {
	// Loop through the vector
	for(unsigned int index = 0; index < zooAnimals.size(); index++) {
		// If the Track# of the animal in the vector matches trackNumber
		if(zooAnimals.at(index)->getTrackNum() == trackNumber) {
			// Return the current index
			return index;
		} // end if
	} // End for
	// If the number was not found, return -1
	return  -1;
} // End FindIndex

// Provided function for generating a new zoodata file. This function uses a Java class ZooFileWriter.class to ask user for input and write data to "zoodata.txt"
void GenerateData()               //DO NOT TOUCH CODE IN THIS METHOD
{
     JavaVM *jvm;                      // Pointer to the JVM (Java Virtual Machine)
     JNIEnv *env;                      // Pointer to native interface
                                                              //================== prepare loading of Java VM ============================
     JavaVMInitArgs vm_args;                        // Initialization arguments
     JavaVMOption* options = new JavaVMOption[1];   // JVM invocation options
     options[0].optionString = (char*) "-Djava.class.path=";   // where to find java .class
     vm_args.version = JNI_VERSION_1_6;             // minimum Java version
     vm_args.nOptions = 1;                          // number of options
     vm_args.options = options;
     vm_args.ignoreUnrecognized = false;     // invalid options make the JVM init fail
                                                                          //=============== load and initialize Java VM and JNI interface =============
     jint rc = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);  // YES !!
     delete options;    // we then no longer need the initialisation options.
     if (rc != JNI_OK) {
            // TO DO: error processing...
            cin.get();
            exit(EXIT_FAILURE);
     }
     //=============== Display JVM version =======================================
     cout << "JVM load succeeded: Version ";
     jint ver = env->GetVersion();
     cout << ((ver >> 16) & 0x0f) << "." << (ver & 0x0f) << endl;

     jclass cls2 = env->FindClass("ZooFileWriter");  // try to find the class
     if (cls2 == nullptr) {
            cerr << "ERROR: class not found !";
     }
     else {                                  // if class found, continue
            cout << "Class MyTest found" << endl;
            jmethodID mid = env->GetStaticMethodID(cls2, "createZooFile", "()V");  // find method
            if (mid == nullptr)
                   cerr << "ERROR: method void createZooFile() not found !" << endl;
            else {
                   env->CallStaticVoidMethod(cls2, mid);                      // call method
                   cout << endl;
            }
     }


     jvm->DestroyJavaVM();
     cin.get();
}

// This function prints 100 newline characters to clear the portion of the console that the user sees
void ClearScreen() {
	// Loop fifty times
	for(int i = 0; i < 50; i++) {
		// Output two newlines
		cout << endl << endl;
	} // End for
} // End ClearScreen

// This function checks whether the length of a string is longer than the maximum allowed
bool CheckLength(string inString, unsigned int maxLength) {
	// If the input string has a length greater than the maximum length allowed
	if(inString.length() > maxLength) {
		// Return false
		return false;
	} // End if
	// Otherwise, the string is shorter than the maximum allowed
	else {
		// Return true
		return true;
	} // End else
} // End CheckLength

// Check whether a number contains anything other than digits
bool CheckNumber(string inString) {
	// If there are no characters in the string that aren't digits
	if(inString.find_first_not_of("0123456789") == string::npos) {
		// Return true
		return true;
	} // End if
	// Otherwise, there is something besides a digit in the string. Return false
	return false;
} // End CheckNumber

// This function checks an input string for one of the sub-types available as subclasses of Animal.
SubType evaluateSubType(string subType) {
	// Loop through each character in the string
	for(unsigned int index = 0; index < subType.length(); index++) {
		// Make the current character lowercase
		subType.at(index) = tolower(subType.at(index));
	} // End for

	// Check if "bat" is in the input string
	if(subType.find("bat") != string::npos) {
		// Return the SubType bat
		return bat;
	} // End if
	// Check if "whale" is in the input string
	if(subType.find("whale") != string::npos) {
		// Return the SubType whale
		return whale;
	} // End if
	// Check if "pelican" is in the input string
	if(subType.find("pelican") != string::npos) {
		// Return the SubType pelican
		return pelican;
	} //End if
	// Check if "sealion" is in the input string
	if(subType.find("sealion") != string::npos) {
		// Return the SubType sealion
		return sealion;
	} //End if
	// Check if "goose" is in the input string
	if(subType.find("goose") != string::npos){
		// Return the SubType goose
		return goose;
	} //End if
	// Check if "crocodile" is in the input string
	if(subType.find("crocodile") != string::npos) {
		// Return the SubType crocodile
		return crocodile;
	} //End if
	// None of the known sub-types are in the string. Return unknown subtype
	return unknown;
} //End evaluateSubType

// This function deletes the pointers in the vector then erases each element in the vector
void emptyVector(vector<Animal*>& zooAnimals) {
	// Loop through the elements in the vector
	for(unsigned int index = 0; index < zooAnimals.size(); index++) {
		// Delete the pointer at the current index
		delete zooAnimals.at(index);
	} // End for
	// While zooAnimals is not empty
	while(!zooAnimals.empty()) {
		// Erase the last element in the vector
		zooAnimals.erase(zooAnimals.end());
	} // End while
} // End emptyVector

// This function returns padding characters in a string. If padChar is not used, the padding character used is ' '
string padString(int paddingNeeded, char padChar) {
	// Declare local variable
	string buffer = "";									// Buffer to store padding characters as string initialized to empty string

	// Loop as many times as the number of characters of padding needed
	for(int index = 0; index < paddingNeeded; index++) {
		// Concatenate the padding character to the buffer
		buffer += padChar;
	} // End for
	// Return the buffer
	return buffer;
} // End padString
