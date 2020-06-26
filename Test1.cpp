#include <iostream> //Include text input and output support
#include <fstream> //Include file input/output support
using namespace std; //Use standard namespace

template <class T> //Declare template

char* convertDataToString(T); //Allocates sizeof(T) + sizeof(char) bytes, fills the final byte with '\0', and the rest is just the data provided as an argument

int main(){

	float number = 50.3; //Declare floating point number "number"

	char* binaryFloat = convertDataToString <float> (number); //Convert number into a string

	ofstream writer("Test1.txt", ios::binary); //Open a file named Test1.txt

	if(!writer){ //Check if file was opened succesfully

		cerr<<"Could not open file!"<<endl; //Output error message

		return -1; //Return error code -1

	}

	size_t size = sizeof(number) + sizeof(char); //Find the size of the string binaryFloat

	writer.write(binaryFloat, size); //Write binaryFloat into a file

	delete[] binaryFloat; //Free the memory block binaryFloat was contained in

	return 0;

}

template <class T> //Declare template

char* convertDataToString(T dataToConvert){ 

	const size_t BUFFER_SIZE = sizeof(dataToConvert) + sizeof(char); //Find size string buffer should be

	char* binaryData = new char[BUFFER_SIZE]; //Allocate memory required for the buffer

	T* temporaryData = reinterpret_cast<T*>(binaryData); //Create a pointer of type T that points at the address of binaryData

	*temporaryData = dataToConvert; //Put the data to convert into the buffer

	*(binaryData + (BUFFER_SIZE - sizeof(char))) = '\0'; //Add a NULL character at the end of the buffer

	return binaryData;

}
