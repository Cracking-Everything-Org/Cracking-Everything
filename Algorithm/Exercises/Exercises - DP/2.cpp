/*
1. Given an integer, write a recursive function to return the sum of its digits.

Input = 123456, Output = 21

totalSum(n) = n % 10 + totalSum(n / 10) if n > 0
totalSum(0) = 0 if n == 0
*/

int totalSum(num) {
  if (num == 0) {
    return 0;
  }
  return (num % 10) + totalSum(num / 10);
}
