#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_letter(char c);
int check_key(string text);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    else
    {
        string key = argv[1];
        if (strlen(key) < 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        else
        {
            int res = check_key(key);
            if (res == 1)
            {
                return res;
            }
            string text = get_string("plaintext: ");
            int n = strlen(text);
            string cipher_text = malloc(n + 1);
            strcpy(cipher_text, text);
            for (int i = 0; i < n; i++)
            {
                char c = cipher_text[i];
                if (c >= 65 && c <= 90) // if current letter is upper
                {
                    cipher_text[i] = toupper(key[c - 65]); // new letter should be upper as well
                }
                else if (c >= 97 && c <= 122) // if current letter is lower
                {
                    cipher_text[i] = tolower(key[c - 97]); // new letter should be lower as well
                }
            }
            printf("ciphertext: %s\n", cipher_text);
            return 0;
        }
    }
}

int is_letter(char c)
{
    return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122));
}

int check_key(string key)
{
    int counter = 0;
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (toupper(key[i]) == toupper(key[j]))
            {
                counter++;
            }
        }
        if (counter != 1 || !is_letter(key[i]))
        {
            printf("Invalid key\n");
            return 1;
        }
        counter = 0;
    }
    return 0;
}
