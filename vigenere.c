/***********************************************************
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
////////////////////////////////////////////////////////////
\\\\\\\\\\\\\\\\\\\created by destroyme_\\\\\\\\\\\\\\\\\\\\
//////////////////////pset2/cs50x///////////////////////////
\\\\\\\\\\\\\\\convert plain text to encrypted\\\\\\\\\\\\\\
/////////////text utilizing the vigenere cipher/////////////
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
////////////////////////////////////////////////////////////
***********************************************************/

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
    /*////////////////////////////////////////////
    Exits on invalid arguments at the command line
    ////////////////////////////////////////////*/
    if (argc != 2)
    {
        printf("Usage: ./ceasar <key> where key = keyword\n");
        return 1;
    }
    
    for (int i = 0, length = strlen(argv[1]); i < length; i++)
    {
        if (isalpha(argv[1][i]) == 0)
        {
            printf("Usage: ./ceasar <key> where key = keyword\n");
            return 1;
        }
    }
    
    // prompt
    string ptext = GetString();
    
    // keyword conversion to int
    int kwordl = strlen(argv[1]);
    int kword[kwordl];
    
    for (int i = 0 ; i < kwordl; i++)
    {
        if (islower(argv[1][i]))
        {
            kword[i] = argv[1][i] % 97;
        } 
        else 
        {
            kword[i] = argv[1][i] % 65;
        }
    }
    
    /*/////////////////////////// 
    Convert string to cipher text
    ///////////////////////////*/
    int ctext;
    for (int i = 0, j = 0, k = strlen(ptext); i < k; i++)
    {
        if (islower(ptext[i]))
        {
            ctext = (ptext[i] + kword[j]) % 123;
            if (ctext < 97)
            {
                ctext = ctext + 'a';
            }
            printf("%c", ctext);
            j = (j + 1) % kwordl;
        }
        else if (isupper(ptext[i]))
        {
            ctext = (ptext[i] + kword[j]) % 91;
            
            if (ctext < 65)
            {
                ctext = ctext + 'A';
            }
            printf("%c", ctext);
            j = (j + 1) % kwordl;
        }
        else 
        {
            printf("%c", ptext[i]);
        }
    }
    printf("\n");    
    return 0;   
}
