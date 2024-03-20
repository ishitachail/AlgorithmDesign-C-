#include <iostream>
#include <algorithm>
/* Probelm Statement : Implement the linear time algorithm for finding the 
subarray of a given array of maximum sum.
In this algorithm, you have to have a recursive subroutine that populates an 
array S, where S[i]=(j, Sy...) (ordered pair) where j is the starting index for 
which we do have a subarray ending at index i of maximum sum (S,...). 
Further, a final pass over the array S[] gives us the required solution.*/

void max_subarray(int Arr[],int size){
    int S[size][2];
    //S[x][1] has the max sum and S[x][0] has the starting index for which we do have a subarray ending at index i of maximum sum

    S[0][1]=Arr[0]; //initialize max sum with first elem of array
    int max = S[0][1]; //this varaible is to store max of all S[i][1] entries (max sum)
    for (int j =0;j<size;j++){
        S[j][0]=0;
    }
    
    for (int i=1;i<size;i++){ //here i is the ending index
        S[i][1]= std::max(Arr[i],Arr[i]+S[i-1][1]); //max sum of subarray eding at i is either Arrr[i] or S[i-1]+Arr[i], whichever is bigger
       
        if (Arr[i] > Arr[i]+S[i-1][1]){
            S[i][0] = i; //storing the starting index
        }
       
    }

    for (int j = 0; j < size; j++){
        if (S[j][1] > max){
            max = S[j][1];} //we are looping through S[j][1] to find max sum
    }
    std::cout << "Starting index , S[j...i] : \n";
    for (auto &row : S)
    {
        for (auto &column : row)
        {
            std::cout << column << ",";
        }
        std::cout << std::endl;
    }
    
    std::cout<<"\nMaximum sum of sub array = " << max<<"\n"; 
}

int main(){
    int Arr[] = {-3,1,-8,12,0,-3,5,-9,4};
    std::cout<<"Array : ";
    for (int i=0; i < 9; i++){
        std::cout<<Arr[i]<<" ";
    } 
    std::cout<<"\n";
    max_subarray(Arr,9);
    return 0;
}