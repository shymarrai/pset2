#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);  // declaring function by count the letters of text
int count_words(string text);  // declaring function by count the words of text
int count_sentences(string text);  // declaring function by count the words of text

int letters = 0; // declaring variable for visibility in all scops
int words = 0; // variable by words by sentences
int sentences = 0; // variable for sentences

int main(void)
{
    string text = get_string("Text: "); // input de text for work

    letters = count_letters(text);
    words = count_words(text);
    sentences = count_sentences(text);

    float L = (float) letters / (float) words * 100;

    float S = (float) sentences / (float) words * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;

    index = round(index);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) index); // call the index by test
    }


}

int count_letters(string text)
{
    int c = 0 ;

    while (c <= strlen(text)) // verifi if percursor is all the text
    {
        if (isalpha(text[c]))   // is momement actuall is letter alphabetic ?
        {
            letters++; // so letter + 1
        }
        c++;
    }
    return letters; // return valor of letter
}

int count_words(string text)
{
    int c = 0 ;

    while (c <= strlen(text)) // verifi if percursor is all the text
    {
        if (isspace(text[c]))
        {
            words++; // so words + 1
        }
        c++;
    }
    return words + 1;
}

int count_sentences(string text)
{
    int c = 0 ;

    while (c <= strlen(text)) // verifi if percursor is all the text
    {
        if ((text[c] == '!') || (text[c] == '?') || (text[c] == '.'))
        {
            sentences++; // so sentence ++
        }
        c++;
    }
    return sentences;
}







