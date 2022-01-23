// Name			: Amritpal Singh
// Project		: crytoMagic 
// FileName		: supportFunctions.c
// Date			: 23 January, 2022
// Description	: This File responsible for encryting or decrypting the file.


#include "crytoHeader.h"



// Function Name: decryptFile
// Description	: decrypt a file
// Parameter	: char* fileName-> name of the file that is to be decrypted
// Return		: void
void decryptFile(char* fileName)
{
	char memBlock[MAX_LINE_LENGTH] = { 0 };
	FILE* fpts = NULL;
	FILE* fptt = NULL;
	
	//opening the given file
	fpts = fopen(fileName, "r");
	if (fpts == NULL)
	{
		printf(" File does not exists or error in opening..!!");
		return;
	}

	char* decryptedFileName = changeFileExtension(fileName, DECRYPTION_EXTENSION);

	//creating the decrypted file
	fptt = fopen(decryptedFileName, "w");
	if (fptt == NULL)
	{
		printf("Error in Creating the decrypted File!");
		fclose(fpts);
		return;
	}
	while (!feof(fpts))
	{
		int howManyRead = 0;

		char loo[240] = "\0";
		// as long as we are reading at least one character (indicated by the return value
		// from fread), keep going
		if ((howManyRead = fread(memBlock, sizeof(char), 120, fpts)) != 0)
		{
			for (int index = 0; index < howManyRead;)
			{
				if (memBlock[index] == '\n')
				{
					fputc('\n', fptt);
					index++;
				}
				else
				{
					char decryptionCodeGenerated = decryptionScheme(memBlock, index);
					// write (to the output file) the data we just read 
					fputc(decryptionCodeGenerated, fptt);
					index += 2;
				}
			}

		}
	}

	//closing the opened file
	if (fclose(fpts) != 0)
	{
		printf("Error in closing file\n");
		return;
	}
	if (fclose(fptt) != 0)
	{
		printf("Error in closing file\n");
		return;
	}
	printf(" File %s successfully decrypted ..!!\n\n", fileName);
	return;
}





// Function Name: encryptFile
// Description	: encrypt a file
// Parameter	: char* fileName-> name of the file that is to be decrypted
// Return		: void
void encryptFile(char* fileName)
{
	FILE* fpts = NULL;
	FILE* fptt = NULL;

	// opening the given file for reading
	fpts = fopen(fileName, "r");
	if (fpts == NULL)
	{
		printf(" File does not exists or error in opening..!!");
		return;
	}

	char* encryptedFileName = changeFileExtension(fileName, ENCRYPTION_EXTENSION);

	// creating the encrypted file
	fptt = fopen(encryptedFileName, "w");

	if (fptt == NULL)
	{
		printf("Error in Creating the encrypted File!");
		fclose(fpts);
		return;
	}
	char memBlock[MAX_LINE_LENGTH] = { 0 };

	while (!feof(fpts))
	{
		int howManyRead = 0;
		// as long as we are reading at least one character (indicated by the return value
		// from fread), keep going
		if ((howManyRead = fread(memBlock, sizeof(char), MAX_LINE_LENGTHS, fpts)) != 0)
		{
			for (int index = 0; index < howManyRead; index++)
			{
				char* encryptionCodeGenerated = encryptionScheme(memBlock[index]);
				int len = strlen(encryptionCodeGenerated);
				// write (to the output file) the data we just read 

				fprintf(fptt, "%s", encryptionCodeGenerated);
			}

		}
	}

	//closing the opened file
	if (fclose(fpts) != 0)
	{
		printf("Error in closing file\n");
		return;
	}
	if (fclose(fptt) != 0)
	{
		printf("Error in closing file\n");
		return;
	}
	printf(" File %s successfully encrypted ..!!\n\n", fileName);
	return;
}





// Function Name: encryptionScheme
// Description	: the encrypt scheme applied in order to enrypt a character
// Parameter	: char ch - character to be encrypted
// Return		: char* - the encrypted string
char* encryptionScheme(char ch)
{
	if (ch == 9)
	{
		// if tab return TT
		return "TT";
	}
	else if (ch == '\n')
	{
		// not changing carriage returns
		return "\n";
	}
	else
	{
		// encrypting as specified
		int asciiCodeOfCh = (int)ch;
		int outChar = asciiCodeOfCh - 16;
		if (outChar < 32)
		{
			outChar = (outChar - 32) + 144;
		}
		char buffer[3];
		itoa(outChar, buffer, 16);   // here 16 means Hexadecimal
		return buffer;
	}

}




// Function Name: decryptionScheme
// Description	: the decrypt scheme applied in order to derypt a string
// Parameter	: char ch - character to be encrypted
// Return		: char - the decrypted character
char decryptionScheme(char* str, int index)
{
	// get the two digit hexadecimal number pair
	char hexadecimalNum[3] = "";
	hexadecimalNum[0] = str[index];
	hexadecimalNum[1] = str[index + 1];
	hexadecimalNum[2] = '\0';


	if (hexadecimalNum[0] == 'T' && hexadecimalNum[1] == 'T')
	{
		// if TT return tab
		return '\t';
	}
	else if (hexadecimalNum[0] == '\n')
	{
		// if carriage return
		return '\n';
	}
	else
	{
		// decryption as specified
		int outChar = HexadecimalTodecimal(hexadecimalNum);
		outChar = outChar + 16;
		if (outChar > 127)
		{
			outChar = (outChar - 144) + 32;
		}
		char decryptedCh = outChar;
		return decryptedCh;
	}
}
