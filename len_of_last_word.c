#include <stdio.h>
#include <string.h>

/*
   Given a string s consisting of words and spaces, return the length of the last word in thestring. A word is a maximal substring consisting of non-space characters only.
   */

int lengthOfLastWord(char * s);


int main()
{
	printf("'iKYMxBNoJ   xbjmCbyvzWCwYGUepzHnnUosSTz': %d \n", lengthOfLastWord("iKYMxBNoJ   xbjmCbyvzWCwYGUepzHnnUosSTz"));
	printf("'a': %d \n", lengthOfLastWord("a"));
	printf("'': %d \n", lengthOfLastWord(""));
	printf("'Hello World': %d \n", lengthOfLastWord("Hello World"));
	return 0;
}

int lengthOfLastWord(char * s)
{
	int z = strlen(s) - 1 , i = 0;
	int isLetterFound = 0;

	if(s == "") return 0;

	while(z != -1)
	{
		if(s[z] > 64 && s[z] < 123)
		{
			isLetterFound = 1;
		}
		if(isLetterFound)
		{
			if(s[z] == ' ')
			{
				return i;
			}
			i++;
		}
		z--;
	}
	return i;
}
