// Name			: Amritpal Singh
// Project		: crytoMagic 
// FileName		: crytoMagic.c
// Date			: 23 January, 2022
// Description	: This project is used to encrypt and decrypt ASCII files.


#include "crytoHeader.h"




int main(int argc, char* argv[]) {

    if (argc == 2) 
    {
        // only file name given encrypt it
		encryptFile(argv[1]);
    }
    else if (argc == 3) {
        if (strcmp(argv[1], ENCRYPT_MODE) == 0)
        {
            // encrypt the file
			encryptFile(argv[2]);
        }
        else if (strcmp(argv[1], DECRYPT_MODE) == 0)
        {
            // decrypt the file
			decryptFile(argv[2]);
        }
        else
        {
            // error msg
            warnAboutCommandLineError();
        }
    }
    else 
    {
        //error message
        warnAboutCommandLineError();
    }
    return 0;
}

