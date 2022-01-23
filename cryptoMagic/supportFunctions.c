// Name			: Amritpal Singh
// Project		: crytoMagic 
// FileName		: supportFunctions.c
// Date			: 23 January, 2022
// Description	: This File contains the supportive functions for the project crytoMagic and also reposnible for changing file extension.




#include "crytoHeader.h"






// Function Name: HexadecimalTodecimal
// Description	: Convert Hexadeimal Number to Decimal Number
// Parameter	: char* hexaDecimalNumber-> The hexadecimal Number which is to be converted to decimal Number
// Return		: the decimalNumber (int) 
int HexadecimalTodecimal(char* hexaDecimalNumber)
{

	int decimalNumber = 0;
	int x = 1;
	int len = strlen(hexaDecimalNumber);
	for (int i = len - 1; i >= 0; i--)
	{
		int j = hexaDecimalNumber[i];
		char k = hexaDecimalNumber[i];
		if (hexaDecimalNumber[i] >= '0' && hexaDecimalNumber[i] <= '9')
		{
			decimalNumber += x * (hexaDecimalNumber[i] - '0');
		}
		else if (hexaDecimalNumber[i] >= 'A' && hexaDecimalNumber[i] <= 'F')
		{
			decimalNumber += x * (hexaDecimalNumber[i] - 'A' + 10);
		}

		x *= 16;
	}
	return decimalNumber;
}



// Function Name: decimalToHexadecimal
// Description	: Convert decimal Number to HexaDecimal Number
// Parameter	: int num-> The decimal Number which is to be converted to hexadecimal Number
// Return		: char* hexaDecimalNumber 
char* decimalToHexadecimal(int num)
{

	int quotient = num;
	int remainder = 0;
	int j = 1;
	char hexadecimalNum[3];
	hexadecimalNum[2] = '\0';
	
	while (quotient != 0)
	{
		remainder = quotient % 16;
		if (remainder < 10)
		{
			hexadecimalNum[j--] = 48 + remainder;
		}
		else
		{
			hexadecimalNum[j--] = 55 + remainder;
		}
		quotient = quotient / 16;
	}

	return hexadecimalNum;
}




// Function Name: warnAboutCommandLineError
// Description	: Inform user how to use terminal correctly to run the program
// Parameter	: void
// Return		: void 
void warnAboutCommandLineError()
{
	printf("Usage Error: Please specify the encryption or decryption mode correctly with correct file name.\n"
		"USAGE: cryptomagic [mode] filename\n"
		"Example: cryptoMagic –decrypt myFile.crp\n\n");
}





// Function Name: changeFileExtension
// Description	: Inform user how to use terminal correctly to run the program
// Parameter	: char* currentFileName--> current name of the file 
//					char* newExtensionToBeGiven--> new extension to be given
// Return		: char* newFileName --> newFileName with new extension 
char* changeFileExtension(char* currentFileName, char* newExtensionToBeGiven)
{
	char* newFileName = currentFileName; /* make a copy */

	int len = strlen(newFileName); //length of name of File
	int extLen = strlen(newExtensionToBeGiven); //length of fileExtension

	int pos = 0; /* grab the last dot found */
	int index = 0; /* current iterator character */
	int newLen = 0; /* total size of currentFileName excluding extension*/


	for (int index = 0; index <= len; index++)
	{
		char i = newFileName[index];
		/* find the last dot in the string */
		if (newFileName[index] == '.')
		{
			pos = index; /* save the position */
		}
	}

	newLen = pos; /* save the position of the last dot in the string */

	if (pos == 0)
	{
		strcat(newFileName, newExtensionToBeGiven);
	}
	else
	{
		for (int index = 0; pos <= (newLen + extLen); index++)
		{
			newFileName[pos] = newExtensionToBeGiven[index];
			pos++;
		}
	}

	return newFileName;


}