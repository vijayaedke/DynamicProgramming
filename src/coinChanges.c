/*
Coin Change 
Medium Accuracy: 47.19% Submissions: 18352 Points: 4
Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , SM } 
valued coins. 

Example 1:

Input:
n = 4 , m = 3
S[] = {1,2,3}
Output: 4
Explanation: Four Possible ways are:
{1,1,1,1},{1,1,2},{2,2},{1,3}.

â€‹Example 2:

Input:
n = 10 , m = 4
S[] ={2,5,3,6}
Output: 5
Explanation: Five Possible ways are:
{2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} 
and {5,5}.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function count() which accepts an array S[] its size m and n as 
input parameter and returns the number of ways to make change for N cents.
*/
#include <stdio.h>
#include <stdlib.h>

void count(int *array, int size, int index, int n, int *coins){
    //
    
    int **matrix=(int **)malloc(sizeof(int *)*size);
    
    for(int i=0;i<size;i++){
        matrix[i] = (int *)malloc(sizeof(int) * (n+1));
    }
    
    for(int i=0;i<size;i++){
        for(int j=0;j<=n;j++){
            if(j==0)
                matrix[i][0] = 1;
            else
                matrix[i][j] = 0;
        }
    }
    
    for(int i=0;i<size;i++){
        for(int j=1;j<=n;j++){
           if(i>0){
               matrix[i][j] = matrix[i-1][j]?matrix[i-1][j]:0;
           }
           if(array[i]<=j){
               matrix[i][j] += matrix[i][j - array[i]];  
           }
        }//for j
    }//for i
    
    for(int i=0;i<size;i++){
        for(int j=0;j<=n;j++){
            printf("%d\t", matrix[i][j]);
        }//for j
        printf("\n");
    }//for i
    printf("Coins %d", matrix[size-1][n]);
    //recursive solution
    // if(index>=size)
    //     return;
    
    // if(n==0){
    //     (*coins)++;
    //     return;
    // }//if
    // if(array[index]<=n){
    //     count(array, size, index, n-array[index], coins);
    // }
    // count(array, size, index+1, n, coins);
    
}//count

int main() {
	//code
	int array[]={2,5,3,6};//{1, 2, 3};
	int size= sizeof(array)/sizeof(array[0]);
	int n=10;//4;
	int coins=0;
	count(array, size, 0, n, &coins);
	if(coins)
	    printf("Coins %d", coins);
	
	
	return 0;
}

/*
output:
1	0	1	0	1	0	1	0	1	0	1	
1	0	1	0	1	1	1	1	1	1	2	
1	0	1	1	1	2	2	2	3	3	4	
1	0	1	1	1	2	3	2	4	4	5	
Coins 5
*/
