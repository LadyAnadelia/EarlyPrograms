
/***************************************************************************************
** Description: Create a program that takes the numbers from a user for a matrix,
** calculate the determinant, and prints the matrix and then the determinant.
****************************************************************************************/
#include "readMatrix.hpp"
#include "determinant.hpp"
#include<iostream>
#include<string>
using std::endl;
using std::cout;
using std::cin;

int validation(char validate_charater, char array[], std::string message);

int main()
{
		// Menu selctions
	cout << "Welcome to finding the Deteminant of a Matrix." << endl;
	cout << endl;
	cout << "Choose Matrix size from the following selection:" << endl;
	cout << "1:\t2 X 2" << endl;
	cout << "2:\t3 X 3" << endl;
	cout << endl;

		// Validate the choice of Matrix size

	char number_of_Selections[2] = { '1', '2' };  //the selection choices
	std::string error_Message = "Error! Wrong Input! Try Again!";
	char choice = 'c';
	
	// Return the selcted choice
	int userSelection = validation(choice, number_of_Selections, error_Message);

		// Information that is determed from Users choice
	int size = 0;						// Initialize the row and column size to 0
	std::string squareSize = " ";		// For printing size of Matrix
	
	if (userSelection == 1) // 2X2 matrix
	{
		size = 2;
		squareSize = "2 X 2";
	}
	else  // 3X3 matrix
	{
		size = 3;
		squareSize = "3 X 3";
	}

		// Dynamic Allocation
	int** array2D;
	array2D = new int*[size];
	for (int x = 0; x < size; ++x)
		array2D[x] = new int[size];

		// Go to read matrix and fill in the integers
		// Void readMatrix()
	ReadMatrix rMatrix;
	rMatrix.readMatrix(array2D, size);
	cout << endl; 

		// Display the Matrix - in a box
	std::cout << "Here is the " << squareSize << " Matrix that you entered:" << std::endl;
	rMatrix.printMatrix(array2D, size);
	cout << endl;

		// Display the determinant 
		// Go to int Determinant(); to calculate the determinant
	Determinant calcNumber;
	cout << "The Determinant: " << calcNumber.determinant(array2D, size) << endl;
		
		//Free Dynamic Allocation
	for (int x = 0; x < size; ++x)
		delete[] array2D[x];
	delete[] array2D;

	return 0;
}

/*****************************************************************************************
*		()
*Validates the users choice for the size of the matrix. Prints the message at least twice per error.
*****************************************************************************************/
int validation(char validate_charater, char array[], std::string message)
{
	validate_charater = std::cin.get();
	while (validate_charater != array[0] && validate_charater != array[1])
	{
		std::cout << message;
		validate_charater = std::cin.get();
	}
	if (validate_charater == array[0])
	{
		return array[0] - 48;
	}
	else if (validate_charater == array[1])
	{
		return array[1] - 48;
	}
}
