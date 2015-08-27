#include <stdio.h>

//SPOJ problem: Life, the Universe, and Everything.
//Rewrite small numbers from input to output. Stop processing input after reading in the number 42. All numbers at input are integers of one or two digits.

int main()
{
	int number;
	while(1)
	{
		scanf("%d", &number);
		if(number == 42)
		{
			break;
		}
		while(number > 99)
		{
			scanf("%d", &number);
		}
		printf("%d\n", number);
	}
	return 0;
}
