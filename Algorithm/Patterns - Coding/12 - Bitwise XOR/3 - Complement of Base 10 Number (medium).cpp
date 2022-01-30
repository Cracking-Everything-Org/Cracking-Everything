Problem Statement #
Every non-negative integer N has a binary representation, for example, 8 can be represented as “1000” in binary and 7 as “0111” in binary.

The complement of a binary representation is the number in binary that we get when we change every 1 to a 0 and every 0 to a 1. For example, the binary complement of “1010” is “0101”.

For a given positive number N in base-10, return the complement of its binary representation as a base-10 integer.

Example 1:

Input: 8
Output: 7
Explanation: 8 is 1000 in binary, its complement is 0111 in binary, which is 7 in base-10.
Example 2:

Input: 10
Output: 5
Explanation: 10 is 1010 in binary, its complement is 0101 in binary, which is 5 in base-10.


int bitwiseComplement(int num) {
  // count number of total bits in 'num'
  int bitCount = 0;
  int n = num;
  while (n > 0) {
    bitCount++;
    n = n >> 1;
  }

  // for a number which is a complete power of '2' i.e., it can be written as pow(2, n), if we
  // subtract '1' from such a number, we get a number which has 'n' least significant bits set to
  // '1'. For example, '4' which is a complete power of '2', and '3' (which is one less than 4)
  // has a binary representation of '11' i.e., it has '2' least significant bits set to '1'
  int all_bits_set = pow(2, bitCount) - 1;

  // from the solution description: complement = number ^ all_bits_set
  return num ^ all_bits_set;
}

Time Complexity #
Time complexity of this solution is O(b) where ‘b’ is the number of bits required to store the given number.

Space Complexity #
Space complexity of this solution is O(1).
