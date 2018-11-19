#include "sortFunctions.h"


int *sort(int userArray[], int size,int &finalSize) {//integer sort definition
	
	//static int *sortedArray = new int[size];//declaring static dynamic array

	int change = 0;//variable to hold the current element

	for (int i = size -1; i > 0; i--) {//for loop controlling which elements to loop through first, starting from the last

		for (int j = 0; j < i; j++)//loop that checks each element
		{
			if (userArray[j] > userArray[j + 1]) {//checks if the current element is greater than the next element
				change = userArray[j];
				userArray[j] = userArray[j + 1];//sets this element to the next element
				userArray[j + 1] = change;//sets next element to this element
			}
		}
	}

	for (int i = 0; i < size; i++)
		std::cout << userArray[i] << " ";//prints the elements of the array
	std::cout << std::endl;//ends the line after printing the array
	return userArray;//returning the sorted array

}
char *sort(char userArray[], int size,int &finalSize) {

	char change = ' ';

	for (int i = size - 1; i > 0; i--) {

		for (int j = 0; j < i; j++)
		{
		
			if (userArray[j] > userArray[j + 1]) {
				change = userArray[j];
				userArray[j] = userArray[j + 1];
				userArray[j + 1] = change;
			}
		}
	}

	for (int i = 0; i < size; i++)
		std::cout << userArray[i] << " ";
	std::cout << std::endl;
	return userArray;
}


std::string *sort(std::string userArray[], int size, int &finalSize) {
	std::string change = " ";

	for (int i = size - 1; i > 0; i--) {

		for (int j = 0; j < i; j++)
		{

			//.length() is a function in the string library that gets the amount of characters in a given string.
			if (userArray[j].length() > userArray[j + 1].length()) {
				change = userArray[j];
				userArray[j] = userArray[j + 1];
				userArray[j + 1] = change;
			}
		}
	}

	for (int i = 0; i < size; i++) {
		std::cout << userArray[i] << " ";
		std::cout << std::endl;


	}
		return userArray;
}