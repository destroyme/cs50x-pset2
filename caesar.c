/***********************************************************
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
////////////////////////////////////////////////////////////
\\\\\\\\\\\\\\\\\\\created by destroyme_\\\\\\\\\\\\\\\\\\\\
//////////////////////pset2/cs50x///////////////////////////
\\\\\\\\\\\\\\\convert plain text to encrypted\\\\\\\\\\\\\\
//////////////text utilizing the caesar cipher//////////////
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
    // Exits for invalid arguments at the command line
    if (argc != 2)
    {
        printf("Usage: ./ceasar <key> where key >= 0\n");
        return 1;
    }
    
    // Convert the command line argument into an integer.
    int key = atoi(argv[1]);
    if (key < 0)
    {
        printf("Usage: ./ceasar <key> where key >= 0\n");
        return 1;
    }
            
    // Prompt user for a string
    string ptext = GetString();
    
    /* Convert string to cipher text */
    // Variable preparation
    key = key % 26;
    int ctext;
    
    for (int i = 0, k = strlen(ptext); i < k; i++)
    {
        if (islower(ptext[i]))
        {
            ctext = (ptext[i] + key) % 123;
            if (ctext < 97)
            {
                // loop back to ascii
                ctext = ctext + 'a';
            }
            printf("%c", ctext);
        }
        else if (isupper(ptext[i]))
        {
            ctext = (ptext[i] + key) % 90;
            
            if (ctext < 65)
            {
                // loop back to ascii
                ctext = ctext + 'A';
            }
            printf("%c", ctext);
        }
        else 
        {
            printf("%c", ptext[i]);
        }
        
    }    
    
    printf("\n");
}
