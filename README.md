# Determinant-calculator-with-permutations
# Determinant
Determinant is a function that takes matrix and returns a real number. Geometrically speaking, it is a measure that shows
us by which factor a vector space is warped with given matrix transformation. It quantifies how much the hyper-volume of multidimensional space
has changed under the transformation.
# Script description
This script can calculate a determiniant of nxn matrix given dimension n. This calculation is done using
all possible permutations of array `(1,2...,n)`. This is the definition:

![Screenshot 2024-03-22 212829](https://github.com/ttcpavle/Determinant-calculator-with-permutations/assets/159661698/5a92c367-51e3-4607-b58c-219ea2ebbd36=350x350)

This algorithm is very inefficient since number of permutations is very huge and is calculated recursivly but it shows a very interesing property
of a determinant. Much faster way to calculate det would be using the Gaussian elimination method, which has the time complexity `O(n^3)`.
This algorithm has time complexity of `O(n!)` making it faster for smaller matrix, to be precise, it should be faster for matrix up to size of 5 since 5!<5^3.
Recursion algorithm used for permutations in the script is not the most efficient one, the point was only to show interesting way of calculating determinant.

<img src="https://github.com/ttcpavle/Determinant-calculator-with-permutations/assets/159661698/69dacc10-a0c3-405d-85f1-c6a003a12bbc" alt="x! and x^3 graphs" style="width: 40%; display: block; margin: auto;">

red:  `x!`  (permutations)

blue: `x^3` (gaussian elimination)

If implemented correctly, calculating smaller matrix determinant with this algorithm should be faster, as you can see in the graph.
There is always room for improvement. Thank you for reading.

NOTE: this project is under MIT licence



