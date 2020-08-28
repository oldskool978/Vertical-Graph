/*
*Goals
*histogram of words IN VERTICAL
*/
#include <stdlib.h>
#include <stdio.h>
#include<ctype.h>

int main()
{
    int *Tracker = calloc(0,sizeof(int));
    int WordCount, CurrentChar, CharCount, WordPosition, GreatestNum, BigNum, IndiCount;
    WordCount = CurrentChar = CharCount = WordPosition = GreatestNum = IndiCount = 0;
    while ((CurrentChar = getchar()) != EOF)
    {
        if ( isalpha(CurrentChar) > 0)
            CharCount++;

        else
        {
            if (CharCount > 0)
            {
                WordCount++;
                IndiCount++;
                Tracker = realloc(Tracker,(sizeof(int) * WordCount));
                Tracker[WordCount - 1] = CharCount; 
                if (CharCount > GreatestNum)
                    GreatestNum = CharCount;
                CharCount = 0;
            }
        }
        if (CurrentChar == '\n')
            break;
    }
    BigNum = GreatestNum;
    while(BigNum > 0)
    {
        for (int i = 0; i < WordCount; i++)
        {
            if (Tracker[i] < BigNum)
                printf(" ");
            else 
                printf("#");
        }
        printf("\n");
        BigNum--;
    }
    free(Tracker);
    printf("%i words in total, longest length is %i \n",WordCount, GreatestNum);
    return 0;
}
