#include <stdio.h>
#include <math.h>

int main(void)
{
	
	long long unsigned minimum = 0;
	long long unsigned maximum = 0;
	char inputs[21];
	int counter;
	char ch = 'x';
	int testCases;
	scanf("%d", &testCases);
	while(testCases > 10)
	{
		scanf("%d", &testCases);
	}
	testCases++;
	while(testCases != 0)
	{
		counter = 0;
		ch = 'x'; 	//because ch == '\n' from last loop.
		do
		{
			minimum = 0;
			maximum = 0;
			for(counter = 0; counter <= 20; counter++)
			{
				inputs[counter] = 'x';
			}
			counter = 0;
			while(counter <= 20 && (ch = getchar()) != '\n')
			{
				if (ch != ' ')
				{
					inputs[counter] = ch;
				}
				counter++;
			}
			counter = 0;
			while(inputs[counter] != 'x')
			{
				minimum *= 10;
				minimum += (inputs[counter] - '0');
				counter++;
			}
			counter++;	//so inputs[counter] != 'x'.
			while(counter <= 20 && inputs[counter] != 'x')
			{
				maximum *= 10;
				maximum += inputs[counter] - '0';
				counter++;
			}
		}while(minimum > 1000000000 || maximum > 1000000000 || maximum - minimum > 100000);
		while(minimum != maximum)
		{
			if(minimum <= 1)
			{
				minimum = 2;
			}
			if(isPrime(minimum) == 1)
			{
				printf("%llu\n", minimum);
			}
			minimum++;
		}
		testCases--;
	}
	return 0;
}

int isPrime(long long unsigned number)
{
	int counter;
	for(counter = 2; counter <= sqrt(number); counter++)
	{
		if(number % counter == 0)
		{
			return 0;
		}
	}
	return 1;
}
