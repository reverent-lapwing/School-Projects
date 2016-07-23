
/* DESCRIPTION:
* Program uses sieve of Eratosthenes to find and store number of divisors for every positive integer less or equal to sieveSize
* Then it uses stored values to find antiprimes (highly composite numbers)
* Number 'p' is antiprime if for all 'q' < 'p' number of divisors div('q') < div('p')
*/

/* INPUT:
* Size of sieve of Eratosthenes
*/

/* OUTPUT:
* Displays every antiprime less or equal to sieveSize
*/


#include <iostream>
#include <vector>


int main()
{
 std::cout << "Enter range of numbers to search for antiprimes: 0-";
 std::size_t sieveSize;
 std::cin >> sieveSize;

// 1 and 2 must be hard-coded as first anti-primes, because of the simplification of the algorithm (omitting divisors 1 and 'p' for each number 'p')
 if( sieveSize == 1 )
 {
  std::cout << "1\n";
  return 0;
 }
 if( sieveSize == 2 )
 {
  std::cout << "1\n2\n";
  return 0;
 }

// For a number 'p', sieve[p] == number of divisors excluding 'p' and 1
// Dynamic size container such as std::vector can hold more data than std::array
 std::vector<std::uint32_t> sieve(sieveSize+1);

// Biggest number of divisors found in the loop so far
 std::uint32_t maxSoFar = 0;
 std::size_t halfSieve = sieveSize/2 + 1;

 try
 {
 // 1 and 2 are skipped by the algorithm
  std::cout << "1\n2\n";

  for( std::uint32_t i = 2; i < halfSieve; i++ ) // 'i' starts at 2, program omits "divides by 1" rule
  {
   for( std::uint32_t j = 2; i*j <= sieveSize; j++ ) // 'j' starts at 2, program omits "divides by itself" rule
   {
    sieve.at(i*j)++;
   }

   if( maxSoFar < sieve.at(i) )
   {
    std::cout << i << "\n";
    maxSoFar = sieve.at(i);
   }
  }
 }
 catch( std::exception & e )
 {
  std::cout << "Program terminated unexpectedly: " << e.what() << "\n";
 }

 return 0;
}
