#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n"); // verify input if is 2 arguments
        return 1;
    }
    for (int i = 0, length = strlen(argv[1]); i < length; i++) //verify if arguments is numbers
    {
        if (! isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int key = atoi(argv[1]);
    string text = get_string("plaintext: ");
    int x = strlen(text); //text length
    int cipher[x]; // future cipher text
    printf("ciphertext: "); // text cypher

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                int begin = 65;
                cipher[i] = ((text[i] - begin + key) % 26) + begin; // construct by cypher text by table of caracters lower case
                printf("%c", cipher[i]);
            }
            else if (islower(text[i]))
            {
                int begin = 97;
                cipher[i] = ((text[i] - begin + key) % 26) + begin; // construct by cypher text by table of caracters lower case
                printf("%c", cipher[i]);

            }
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}