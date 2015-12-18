#include <stdio.h>
#include <math.h>

int main(void)
{
	long long minimum = 0;
	long long maximum = 0;
	
	int testCases = 0;
	do
	{
		scanf("%d", &testCases);
		getchar();
	}while(testCases <= 0 || testCases > 10);
	
	long long numbers[testCases][2];
	
	char inputs[testCases][21];
	int lines;
	int rows;
	
	char ch;
	
	for(lines = 0; lines < testCases; lines++)
	{
		do
		{
			minimum = 0;
			maximum = 0;
			
			for(rows = 0; rows < 21; rows++)
			{
				inputs[lines][rows] = 'x';
			}
			
			rows = 0;
			while(rows <= 20 && (ch = getchar()) != '\n')
			{
				if(ch != ' ')
				{
					inputs[lines][rows] = ch;
				}
				rows++;
			}
			
			rows = 0;
			while(inputs[lines][rows] != 'x')
			{
				minimum *= 10;
				minimum += inputs[lines][rows] - '0';
				rows++;
			}
			rows++;
			while(rows < 21 && inputs[lines][rows] != 'x')
			{
				maximum *= 10;
				maximum += inputs[lines][rows] - '0';
				rows++;
			}
		}while(minimum > 1000000000 || maximum > 1000000000 || maximum - minimum > 100000 || maximum < minimum);
		
		numbers[lines][0] = minimum;
		numbers[lines][1] = maximum;
	}
	/*for(lines = 0; lines < testCases; lines++)
	{
		for(rows = 0; rows < 21; rows++)
		{
			printf("%c", inputs[lines][rows]);
		}
		printf("\n");
	}*/
	for(lines = 0; lines < testCases; lines++)
	{
		minimum = numbers[lines][0];
		maximum = numbers[lines][1];
		if(lines != 0)
		{
			printf("\n");
		}
		
		while((minimum-1) != maximum)
		{
			if(isPrime(minimum) == 1)
			{
				printf("%d\n", minimum);
			}
			minimum++;
		}
	}
	return 0;
}

int isPrime(long long number)
{
	int counter;
	if(number <= 1)
	{
		return 0;
	}
	for(counter = 2; counter <= sqrt(number); counter++)
	{
		if(number % counter == 0)
		{
			return 0;
		}
	}
	return 1;
}
