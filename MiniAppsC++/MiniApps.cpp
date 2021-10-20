#pragma once
#include "MiniApps.h"

MiniApps::MiniApps()
{

}

MiniApps::~MiniApps()
{

}

void MiniApps::keepCounting()
{
	cout << "Keep Counting\n";
	cout << "-------------\n";
	cout << "You will be presented with 8 addition questions.\n";
	cout << "After the first question, the left-hand operand is the result of \nthe previous addition\n";

	// need to start the timer so create start/end time variables
	// record timer in milliseconds using GetTickCount
	// need to convert to seconds by /1000
	// use DWORD to store time --> only stores unsigned integers --> never stores negative numbers


	DWORD start, elapsed;
	bool allQsCorrect, correct;
	int currentQ = 1, op1, op2, answer, correctAnswers = 0;
	const int MAX_QS = 8, MIN_RANGE = 1, MAX_RANGE = 10;
	char randOp;
	const char operators[] = { '+', '-' };

	start = GetTickCount(); // start the timer that returns the number of milliseconds elapsed from a certain point.


	// generate random number for op1 initially (as it is only needed once)
	op1 = MIN_RANGE + (rand() % MAX_RANGE);

	do
	{

		// generate random number op2 for each question
		op2 = MIN_RANGE + (rand() % MAX_RANGE);

		//get random operator
		randOp = operators[rand() % 2];

		//ask the first question and collect the answer
		cout << "Question " << currentQ << ": " << op1 << randOp << op2 << "\n";
		cin >> answer;

		// check if the answer is right or wrong
		if (answer == op1 + op2 || answer == op1 - op2)
		{
			correct = true;
			correctAnswers++;
			op1 = answer;
			++currentQ;
		}
		else
		{
			correct = false;
			cout << "Sorry, you got a question wrong\n";
			cout << "Your time is only displayed when you get all 8 questions are answered correctly. Try again.\n";
		}



	} while (correct && correctAnswers != MAX_QS);

	//stop the timer
	elapsed = (GetTickCount() - start) / 1000;

	if (correctAnswers == 8)
	{
		cout << "Well done you have correctly answered all 8 questions in " << elapsed << " seconds\n";
	}

	cout << "\n";

}
void MiniApps::numberConversion()
{
	cout << "Number Conversion\n";
	cout << "----------------\n";
	cout << "Enter any base-10 number:\n";

	//declare variables
	int base10;
	cin >> base10; // take in user input and assign to base10 var

	char hexaDeciNum[100];

	// start counter for char array index
	int i = 0;
	int temp = base10;

	while (temp != 0) // once base10 = 0 each number has been converted
	{
		int rem = 0;
		rem = temp % 16; // get the remainder

		if (rem < 10) // if rem is less than 10 then convert to the corresponding ascii number characters (which start from 48)
		{
			hexaDeciNum[i] = rem + 48;
		}
		else {
			hexaDeciNum[i] = rem + 55; // by adding 55 we convert the number into the ascii letter (which start from 65)
		}
		i++; // increment index iterator
		temp /= 16;
	}

	cout << "Equivelant Hexidecimal Value: ";
	for (int j = (i - 1); j >= 0; j--) // start from the end of the array which is i-1 and print backwards 
	{
		cout << hexaDeciNum[j];
	}
	cout << "\n";

	// convert to binary
	int binary[20];
	temp = base10;
	i = 0;

	while (temp != 0)
	{
		binary[i] = temp % 2; // the remainder after modulus 2 is either 1 or 0 so assign value
		i++; // increment index counter
		temp /= 2; // get new quotient
	}

	// print out binary
	cout << "Equivelant Binary Value: ";
	for (int j = (i - 1); j >= 0; j--)
	{
		cout << binary[j];
	}
	cout << "\n\n";
}
void MiniApps::upcConverter()
{

	cout << "UPC Generator\n";
	cout << "------------\n";
	cout << "Enter a 6 digit number\n";
	int code;
	cin >> code;

	// input validation
	if (code < 0 || code > 1000000)
		cout << "Invalid number\n";
	else
	{
		// create an array to hold each digit
		int digits[6];
		for (int i = 0; i < 6; i++)
		{
			// split the number into it's digits
			digits[i] = code % 10;
			code = code / 10;
		}

		int tempSum = 3 * (digits[5] + digits[3] + digits[1]);
		tempSum += digits[4] + digits[2] + digits[0];


		//get remainder when resukt us divided by 10
		int rem = tempSum % 10;

		// if remainder is 0 then use 0 as check digit,
		int checkDigit;
		if (rem == 0)
		{
			checkDigit = 0;
		}
		else {
			// subract the remainder from 10 to derive check digit
			checkDigit = 10 - rem;
		}


		// add digit onto end of the array
		// swap order or array

		int UPC[7];

		for (int i = 0; i < 7; i++)
		{
			UPC[i] = digits[5 - i];
		}

		UPC[6] = checkDigit;

		// display the 7 digit code
		cout << "Your UPC code is ";
		for (int i = 0; i < 7; i++)
		{
			cout << UPC[i];
		}
		cout << endl;

	}


}
void MiniApps::upcChecker()
{

}



