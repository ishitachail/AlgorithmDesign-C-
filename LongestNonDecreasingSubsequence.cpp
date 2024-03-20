#include <iostream>
/* Probelm Statement: Implement an O(nlogk) algorithm to compute the longest non-decreasing sequence 
in the given array A[1...n] of integers, where k is the length of the solution. You should have both a 
recursive and non-recursive im- plementations. Use appropriate data structures to deploy memoization. 
Furthermore, your procedure should:
(a) Read the value i from the user and compute the longest non-decreasing sequence in the subarray A[1... i) in O(k) time.
(b) Compute the longest non-decreasing sequence "ending at A[i]" in O(k) time.*/


int BinarySearching(std::vector<int> Mem, int k, std::vector<int> Input){
    int low = 0;
    int high = Mem.size()-1;
    // ans stores Index of element which is upper bound of k
    int ans = Mem.size();   
    
    while(low <= high){
        
        int mid = low + (high - low) / 2;
        if(Input[Mem[mid]] <= k){
            low = mid+1;
        }
        else{
            ans = mid;
            high = mid-1;
        }
    }
    // return only ans if you want just the index of upper-bound
    return ans; 
}

std::vector <std::vector <int>> LongestNonDecSubSeq (std::vector<int> input){
    std::vector<int> tail;
    std::vector<int> pred;
    std::vector<int> mem;
    mem.push_back(0);
    tail.push_back(0);
    pred.push_back(-1);
    for (int i=1;i<input.size();i++){
        int index = BinarySearching(mem,input[i],input);
        if(index==mem.size()){
            mem.push_back(i);
        }
        else{
            mem[index]=i;
        }
        tail.push_back(mem[mem.size()-1]);
        pred.push_back(mem[index-1]);
        
    }
    std::vector <std::vector <int>> result;
    result.push_back(mem);
    result.push_back(tail);
    result.push_back(pred);
    return result;

}
void printvector(std::vector<int> V){
     for (int i = 0; i<V.size();i++){
        std::cout<<V[i]<<" ";
    }
    std::cout<<"\n";
}
void printvectorrev(std::vector<int> V){
    for(int i = V.size()-1;i>=0;i--){
        std::cout<<V[i]<<" ";
    }
     std::cout<<"\n";
}
std::vector<int> BacktrackSolA(std::vector<int> input,std::vector<int>tail ,std::vector<int> pred, int i){
    int index = tail[i];
    std::vector<int>V;
    while (pred[index]!=-1){
        V.push_back(input[index]);
        index = pred[index];
    }
    V.push_back(input[index]);
    //printvector(V);
    return V;

}
std::vector<int> BacktrackSolB(std::vector<int> input,std::vector<int>tail ,std::vector<int> pred, int i){
    int index = i;
    std::vector<int>V;
    while (pred[index]!=-1){
        V.push_back(input[index]);
        index = pred[index];
    }
    V.push_back(input[index]);
   // printvector(V);
    return V;
}


int main(){
    std::vector<int> input= {-2,7,4,0,1,5,3,8,6,5,6,4};
    std::vector <std::vector <int>> result = LongestNonDecSubSeq(input);
    std::cout<<"Input : ";
    printvector(input);
    std::cout<<"Mem : ";
    printvector(result[0]);
    std::cout<<"Tail : ";
    printvector(result[1]);
    std::cout<<"Pred : ";
    printvector(result[2]);
    int i;
    std::cout<<" Enter index i =  ";
    std::cin>>i;
    std::cout<<"Part A : ";
    printvectorrev(BacktrackSolA(input,result[1],result[2],i));
    std::cout<<"Part B : ";
    printvectorrev(BacktrackSolB(input,result[1],result[2],i));



}
