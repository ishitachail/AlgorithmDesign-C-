//Assume that you are being provided with a text file containing a rectangular matrix 
// representing the pixel values in an image (in the range 0 to 255). Design and implement an 
// algorithm to print the brightest area in the image. The definition of the brightest area is a 
// rectangular submatrix of A[][] of maximum sum, where A[][] is obtained by subtracting 128 from 
// each pixel value in the original image. Make sure that you use your solution to Q2 as a blackbox.

#include <iostream>
#include <algorithm>

std::vector <int> MaxSubarray(std::vector <int>Arr,int width,int StartCol){ //ques2
    std::vector<std::vector<int>> S;
    for (int i =0 ; i<Arr.size();i++){
        S.push_back({0,0,0});
    }
    int MaxSum;         //S[x][0]
    int StartIndex=0;     //S[x][1]
    int EndIndex;       //S[x][2]
    for (int j=1;j<Arr.size();j++){
        MaxSum=std::max(Arr[j],Arr[j]+S[j-1][0]);
        if (Arr[j] > Arr[j]+S[j-1][0]){
            StartIndex = j;
        }
        EndIndex=j;
        S[j][0]=MaxSum;
        S[j][1]=StartIndex;
        S[j][2]=EndIndex;
    }
    std::vector<int> MaxSumVector;
    MaxSumVector.push_back(S[0][0]);
    MaxSumVector.push_back(0);
    MaxSumVector.push_back(0);
    for (int k =0;k<Arr.size();k++){
        if(S[k][0]>MaxSumVector[0]){
            MaxSumVector[0]=S[k][0];
            MaxSumVector[1]=S[k][1];
            MaxSumVector[2]=S[k][2];
        }
    }
    MaxSumVector.push_back(width);
    MaxSumVector.push_back(StartCol);
    return MaxSumVector;
    //MaxSumVector = {max sum, start index , end index, width, startcolumn}
}

std::vector<int> CreateArray(std::vector<std::vector<int>> Matrix,int StartCol,int Width){ 
    //given the start column and width, we add those many columns and return the resulted single array
    std::vector <int>resulted_array;
    for (int i=0;i<Matrix.size();i++){
        resulted_array.push_back(0);
    }
    for (int j= StartCol;j<StartCol+Width;j++){
        for(int k=0;k<Matrix.size();k++){
            resulted_array[k]+=Matrix[k][j];
        }
    }
    return resulted_array;
}

std::vector<std::vector<int>> CreateSumOfAllArrays(std::vector<std::vector<int>> Matrix){
    //we are making a collection of all max sums of all possible submatrices
    std::vector<std::vector<int>> Collection;
    for (int width=1;width<=Matrix[0].size();width++){
        for(int StartCol=0;StartCol<=Matrix[0].size()-width;StartCol++){
            Collection.push_back(MaxSubarray(CreateArray(Matrix,StartCol,width),width,StartCol));
        }
    }
    return Collection;
}

int main(){
    //in the actual pixel matrix we will subtract 128 from all terms so that we will get some negative numbers in the matrix
    std::vector<std::vector<int>> Matrix={{1,32,-1,-4,20},{-8,-3,34,-2,1},{3,58,-9,1,3},{-4,-1,1,7,-6},{-2,-3,87,1,-1}};
    std::vector<std::vector<int>> Collection = CreateSumOfAllArrays(Matrix);
    std::vector<int> final_result = {Collection[0][0],0,0,0,0};  //{maxsum,start,end,width,startcol} vector with max sum
    for(int i=0;i<Collection.size();i++){
        if(Collection[i][0]>final_result[0]){
            final_result=Collection[i];
        }
    }
    std::cout<<"Pixel Matrix:\n";
    for(int i =0 ; i< Matrix.size();i++){
        for (int j =0 ; j< Matrix[0].size();j++){
            std::cout<<Matrix[i][j]<<" ";
        }
        std::cout<<"\n";
    }
    std::cout<<"\n";
    std::cout<<"Max Sum is "<<final_result[0]<<"\n";
    std::cout<<"Brightest Area:\n";
    for (int i = final_result[1];i<=final_result[2];i++){
        for(int j = final_result[4];j<final_result[4]+final_result[3];j++){
            std::cout<<Matrix[i][j]<<" ";
        }
        std::cout<<"\n";
    }

}




