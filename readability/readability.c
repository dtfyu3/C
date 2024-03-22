#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
float get_index(string text);
int is_sentence_end(char c, char next, char prev);

int main(void)
{
    string text = get_string("Text: ");
    int score = round(get_index(text));
    if (score <= 0)
    {
        printf("Before Grade 1\n");
    }
    else if (score >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", score);
    }
}

float get_index(string text)
{
    float index = 0;
    int letters = 0;
    int words = 0;
    int sentences = 0;
    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        char c = text[i];
        if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
        {
            letters++;
        }
        else if (c == 32)
        {
            words++;
        }
        else if (is_sentence_end(c, text[i + 1], text[i - 1]))
        {
            sentences++;
        }
    }
    words++; // to add first word in the text which goes without space
    float L = ((float) letters / words) * 100;
    float S = ((float) sentences / words) * 100;
    index = 0.0588 * L - 0.296 * S - 15.8;
    return index;
}

int is_sentence_end(char c, char next, char prev)
{
    return ((c == 46 || c == 33 || c == 63) && (next == 32 || next == 0)) ||
           (c == 34 && (prev == 46 || prev == 33 || prev == 63));
}
