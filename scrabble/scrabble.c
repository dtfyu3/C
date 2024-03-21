#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int get_score(string word, int points[]);
void print_winner(int first_score, int second_score);

int main(void)
{
    const int n = 2;
    string words[n];
    int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int first_score = 0;
    int second_score = 0;
    for (int i = 0; i < n; i++) // for each word
    {
        words[i] = get_string("Player %i: ", i + 1);
        if (i == 0)
        {
            first_score = get_score(words[i], points);
        }
        else
        {
            second_score = get_score(words[i], points);
        }
    }
    print_winner(first_score, second_score);
}

int get_score(string word, int points[])
{
    int shift = 65;
    int len = strlen(word);
    int score = 0;
    for (int j = 0; j < len; j++) // for each letter in that word
    {
        char letter = toupper(word[j]);
        for (int k = 0; k < 25; k++) // number of symbols in dictionary
        {
            if ((letter - shift) == k)
            {
                score += points[k];
            }
        }
    }
    return score;
}

void print_winner(int first_score, int second_score)
{
    if (first_score > second_score)
    {
        printf("Player 1 wins!\n");
    }
    else if (second_score > first_score)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}
