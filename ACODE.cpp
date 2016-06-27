/*
Author: Platon-Nikolaos Kiorpelidis
Purpose: Solution to problem "ACODE" from Sphere Online Judge
Date: 24-6-2016
Language: C++
Problem definition: For each input set, output the number of possible decodings for the input string. A = 1, B = 2, .. , Z = 26.
*/

#include <iostream>
#include <cstdint>

using namespace std;

void possible_decodings(void *array, uint32_t array_size)
{
  uint16_t *subproblems = NULL;
  subproblems = new uint16_t[array_size + 1];

  for(size_t i = 0; i < array_size; i++)
    subproblems[i] = 0;
  subproblems[0] = 1;

  size_t counter = 1;
  subproblems[counter] = subproblems[counter - 1];
  counter++;

  while(counter < array_size + 1)
  {
    if( (( ((uint16_t*)array) [counter - 2] == 0) && ( ((uint16_t*)array) [counter - 1] == 0 )) ||
    ((( ( ((uint16_t*)array) [counter - 2] * 10 ) + ((uint16_t*)array) [counter - 1] ) >= 27) && ((((uint16_t*)array) [counter - 1] == 0))))
    {
      cout << "0" << endl;
      return;
    }

    if( ( ( ((uint16_t*)array) [counter - 2] * 10 ) + ((uint16_t*)array) [counter - 1] ) >= 27 ||
    (((uint16_t*)array) [counter - 2] == 0 || ((uint16_t*)array) [counter - 1] == 0))
    {
      subproblems[counter] = subproblems[counter - 1];
    }
    else if( ( ( ((uint16_t*)array) [counter - 2] * 10 ) + ((uint16_t*)array) [counter - 1] ) <= 26)
    {
      subproblems[counter] = subproblems[counter - 2] + subproblems[counter - 1];
    }
    counter++;
  }

  cout << subproblems[array_size] << endl;
  delete [] subproblems;
}

int main()
{
  uint16_t *sequence = NULL;
  uint32_t num_elems = 1;
  char c;

  while(true)
  {
    num_elems = 1;
    c = getchar();
    while(c == '\n')
      c = getchar();
    if(c == '0')
      break;
    while(c != '\n')
    {
      num_elems++;
      sequence = (uint16_t*)realloc(sequence, sizeof(uint16_t) * num_elems);
      sequence[num_elems - 2] = c - '0';
      c = getchar();
    }
    sequence[num_elems - 1] = '\0';

    if(num_elems == 2)
      cout << "1" << endl;
    else
      possible_decodings(sequence, num_elems - 1);
    free(sequence);
    sequence = NULL;
  }
  return(EXIT_SUCCESS);
}
