/*
File: PALIN_-_The_Next_Palindrome
Author: Platon-Nikolaos Kiorpelidis
Purpose: Solution to the problem "PALIN - The Next Palindrome"
Date: 16-6-2016
Language: C++
Problem: For a given positive integer K of not more than 1000000 digits, write the value of the smallest palindrome larger than K to output.
*/


#include <iostream>
#include <cstdint>

using namespace std;

bool is_palindrome(uint32_t number)
{
  uint8_t digit;
  uint32_t backwards_number = 0;
  uint32_t temp_number = number;

  while(temp_number != 0)
  {
    digit = temp_number % 10;
    backwards_number *= 10;
    backwards_number += digit;
    temp_number /= 10;
  }

  if(backwards_number == number)
    return true;
  return false;
}

int main(int argc, char const *argv[])
{
  uint32_t test_cases;
  cin >> test_cases;

  while(test_cases != 0)
  {
    uint32_t K;
    cin >> K;

    uint32_t number = K;

    bool flag = false;
    while(flag == false)
    {
      number++;
      flag = is_palindrome(number);
    }
    cout << number << endl;
    test_cases--;
  }

  return(EXIT_SUCCESS);
}
