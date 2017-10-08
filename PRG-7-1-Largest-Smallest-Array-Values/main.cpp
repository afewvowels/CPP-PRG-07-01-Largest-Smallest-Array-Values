//
//  main.cpp
//  07-01-Largest-Smallest-Array-Values
//
//  Created by Keith Smith on 9/22/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Write a program that lets the user enter ten values into an array. The program should
//  then display the largest and smallest values in the array.


#include <iostream>

using namespace std;

const int INT_NUMBERS_TOTAL = 10;

int intNumbersArray[INT_NUMBERS_TOTAL];

void fillArray();
int sortHighest();
int sortLowest();
void output(int, int);

int main()
{
    int intNumberHighest;
    int intNumberLowest;
    
    fillArray();
    
    intNumberHighest = sortHighest();
    intNumberLowest = sortLowest();
    
    output(intNumberHighest, intNumberLowest);
    
    return 0;
}

void fillArray()
{
    // Temporary variable that will be overwritten
    // to hold user input to assign to array value
    int intTemp;
    
    // Loop through for each value in the index (10 times in this case)
    for(int index = 0 ; index < INT_NUMBERS_TOTAL ; index++)
    {
        cout << "Please enter an integer value: ";
        cin >> intTemp;
        while(!cin)
        {
            cout << "Please enter an integer value: ";
            cin.clear();
            cin.ignore();
            cin >> intTemp;
        }
        
        intNumbersArray[index] = intTemp; // Assign user input to array at index
    }
}

int sortHighest()
{
    int intHighest;
    
    intHighest = -2147483647; // Initialize accumulator at minimum int value
    
    for(int index = 0 ; index < INT_NUMBERS_TOTAL ; index++)
    {
        if(intNumbersArray[index] > intHighest)
        {
            intHighest = intNumbersArray[index];
        }
    }
    
    return intHighest;
}

int sortLowest()
{
    int intLowest;
    
    intLowest = 2147483647; // Initialize accumulator at maximum int value
    
    for(int index = 0 ; index < INT_NUMBERS_TOTAL ; index++)
    {
        if(intNumbersArray[index] < intLowest)
        {
            intLowest = intNumbersArray[index];
        }
    }
    
    return intLowest;
}

void output(int intHighest, int intLowest)
{
    cout << "For index values:\n";
    
    for(int index = 0 ; index < INT_NUMBERS_TOTAL ; index++)
    {
        cout << intNumbersArray[index] << " ";
        
        if((index + 1) % 3 == 0)
        {
            cout << endl;
        }
    }
    
    cout << endl;
    
    cout << "The highest number was: " << intHighest << endl;
    cout << "The lowest number was: " << intLowest << endl;
}

