#include <iostream>
#include <algorithm>

/* Probelm Statement: Implement the divide and conquer based algorithm to find the 
subarray of a given array of maximum sum. At the end of each recursive call, 
print a statement "We are done with the subproblem Ali... j]" so as to 
let the user visualize the whole computation sequence.*/


int max_subarray(int Arr[],int start, int end){
    if ( start == end){ //base case when single element left
        std::cout<<"We are done with subproblem Arr["<<start<<"].\n";
        return Arr[start];
    }
    if (start > end){
        return 0;
    }
    //there are 3 cases possible : 1. subarr is in 1st half, 2. subarr is in 2nd half, 3. subarr is in between 
    int n = (start + end) /2;
    int x1 = max_subarray(Arr,start,n); //case1
    int x2 = max_subarray(Arr,n+1,end); //case2
    int m1 = Arr[n];
    int s1 = 0;
    for (int i = n; i>=start;i--){ //finding max sum of subarr ending at n
        s1 += Arr[i];
        if (s1 > m1) {
            m1 = s1;
        }  
    }
    int m2 = Arr[n+1];
    int s2 = 0;
    for (int i = n+1; i<=end;i++){ //finding max sum of subarr starting at n+1
        s2 += Arr[i];
        if (s2 > m2){
            m2 = s2;
        }
    }
    int x3 = m1+m2; //case3 //adding to find max sum of subarr lying in between both the halves
    int max = x1;
    if (max < x2){
        max = x2;
    }
    if (max < x3){
        max = x3;
    }
    std::cout<<"We are done with subproblem Arr["<<start<<"..."<<end<<"].\n";
    return max; //we are returning max(case1,case2,case3 )   
}

int main(){
    int Arr[] = {-3,1,-8,12,0,-3,5,-9,4};
    std::cout<<"Array : ";
    for (int i=0; i < 9; i++){
        std::cout<<Arr[i]<<" ";
    } 
    std::cout<<"\n";
    int max = max_subarray(Arr,0,8);
    std::cout<<"Max sum of Subarray is "<<max<<"\n";
    return 0;
}