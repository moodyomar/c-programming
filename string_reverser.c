#include <stdio.h>
#include <string.h>  

void *StrReverser(char *str);

int main(int argc, char *argv[])
{
	char *str = "default";
	if(argc == 2)
	{
		str = argv[1];
	}

	StrReverser(str);

	return 0;
}

void *StrReverser(char *str)
{
	int len = strlen(str);
	char rev_str[len];

	int i = 0, j = len - 1;
	while(str[i] != '\0')
	{
		rev_str[i] = str[j];
		i++;
		j--;
	}
	printf("String flipped: %s \n",rev_str);
}

