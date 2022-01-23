// Name			: Amritpal Singh
// Project		: crytoMagic 
// FileName		: crytoHeader.h
// Date			: 23 January, 2022
// Description	: This File Contain the include defination, and function prototypes for crytoMagic Project


// include files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//constants
#define ENCRYPT_MODE "-encrypt"  
#define DECRYPT_MODE "-decrypt"  
#define ENCRYPTION_EXTENSION ".crp"  
#define DECRYPTION_EXTENSION ".txt" 
#define MAX_LINE_LENGTH 120

#pragma warning(disable: 4996)


//prototypes
void warnAboutCommandLineError();
void encryptFile(char* fileName);
char* changeFileExtension(char* currentFileName, char* newExtensionToBeGiven);
void decryptFile(char* fileName);
char* encryptionScheme(char ch);
int HexadecimalTodecimal(char* hexaDecimalNumber);
char decryptionScheme(char* str, int index);
char* decimalToHexadecimal(int num);

