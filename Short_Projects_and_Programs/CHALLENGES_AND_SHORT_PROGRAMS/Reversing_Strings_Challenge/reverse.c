/***********************************************
Purpose: <This file contains the definition for
 the 'reverse' function.>
***********************************************/

char* reverse(char *word)
{
    int ctr = 0;

    while (word[ctr] != '\0')
    {
        ctr++;
    }

    char p[ctr];
    int i = 0;
    int j = 0;

    for (i=ctr-1;i>=0;i--)
    {
        p[j] = word[i];
        j++;
    }
    for (i=0;i<ctr;i++)
    {
        word[i]=p[i];
    }

    return word;
}




