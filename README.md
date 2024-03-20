## AlgorithmDesign-C++  
# Probelm Staments:
1. <Maximum_Sum_Subarray_Recursive>: Implement the divide and conquer based algorithm to find the subarray
    a given array of maximum sum. At the end of each recursive call, print
   a statement "We are done with the subproblem Ali... j]"
   so as to let the user visualize the whole computation sequence.
2. <Maximum_Sum_Subarray_NonRecursive>:  Implement the linear time algorithm for finding the
   subarray of a given array of maximum sum. In this algorithm, you have to have a recursive
   subroutine that populates an array S, where S[i]=(j, Sy...) (ordered pair) where j is
   the starting index for which we do have a subarray ending at index i of maximum sum (S,...).
   Further, a final pass over the array S[] gives us the required solution.
3. <BirthgestAreaInPixelMatrix>: Assume that you are being provided with a text file containing
    a rectan- gular matrix representing the pixel values in an image (in the range 0 to 255).
   Design and implement an algorithm to print the brightest area in the image. The definition
   of the brightest area is a rectangular subma- trix of All of
   maximum sum, where A[][] is obtained by subtracting 128 from each pixel value in the original image.
4. <LongestNonDecreasingSubsequence>: Implement an O(nlogk) algorithm to compute the longest non-decreasing
   sequence in the given array A[1...n] of integers, where k is the length of the solution.
   You should have both a recursive and non-recursive im- plementations. Use appropriate data structures
   to deploy memoization. Furthermore, your procedure should:
(a) Read the value i from the user and compute the longest non-decreasing sequence in the subarray A[1... i) in O(k) time.
(b) Compute the longest non-decreasing sequence "ending at A[i]" in O(k) time.
