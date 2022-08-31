#include <stdio.h>
#include <stdlib.h>

/*
   Josephus Problem - Psuedo Code

   all get lives
   start looping
   check if the next in line alive
        if knife isnt with anyone
   			give him the knife
   check if he doesnt have the knife
        get him killed
        raise death counts +1
            check if all dead except 1
				last survivor gets knife index;
		lose the knife
	loop again
*/

void ArrayInitializer(int arr[], int arr_size);
int LastSurvivor(int arr[], int size);

int main(int argc, char *argv[])
{
	int command_line_arg = 100;
	if(argc == 2)
	{
		command_line_arg = atoi(argv[1]);
	}
	else if(argc > 2)
	{
		printf("Too much command line arguments, please enter just 1 ");
		return 0;
	}
	printf("Giving Soldiers:  %d \n",command_line_arg);

	int arr_size = command_line_arg;
	int array[arr_size];
	ArrayInitializer(array, arr_size);
	printf("Last survivor: %d \n",LastSurvivor(array, arr_size));

	return 0;
}

void ArrayInitializer(int arr[], int arr_size)
{
	for (int i = 0; i < arr_size; i++)
	{
		arr[i] = 1;
	}
}

int LastSurvivor(int arr[], int size)
{
	int death_count = 0;
	int i = 0, knife = 0;
	int last_survivor = 0;
	
	while(death_count != size -1)
	{
		// if soldier is alive == 1
		if(arr[i])
		{
			// knife isnt with anyone? give it to this alive solider.
			if(knife == -1)
			{
				knife = i;
			}
			// if solider doesnt have the knife
			if(i != knife)
			{
				arr[i] = 0;
				death_count++;
				if(death_count == size -1)
				{
					// everyone is dead except 1, add knife index 
					last_survivor = knife  + 1;
				}
				knife = -1;
			}
		}
		i = ( i + 1 ) % size;
	}
	return last_survivor;
}

