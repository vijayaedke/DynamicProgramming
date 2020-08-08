#include <stdio.h>
#include <stdlib.h>

//recursive solution
// int subsetExists(int *set,int *sum, int k, int curr,int size){
//     if((*sum)==k)
//         return 1;
    
//     if(curr>=size)
//         return 0;
    
//     if(*sum<k){
//         (*sum)+=set[curr];
//         return subsetExists(set, sum, k, curr+1, size);
//     }
//     return subsetExists(set, sum, k, curr+1, size);
// }//subsetExists

int subsetExists(int *set, int k, int size){
    if(k==0 || size==0)
        return 1;
    
    int **dp = (int **)malloc(sizeof(int *) * size);
    for(int i=0;i<size;i++)
        dp[i] = (int *)malloc(sizeof(int) * k+1);
        
    for(int i=0;i<size;i++)
        dp[i][0] = 1;
    
    for(int j=1;j<=k;j++)
        dp[0][j] = set[0] <= j ? 1 : 0;
        
    for(int i=1;i<size;i++){
        for(int j=1;j<=k;j++){
            if(set[i]<=k)
                dp[i][j] = dp[i-1][j-set[i]] ? 1 : 0;
            else
                dp[i][j] = dp[i-1][j];
        }//forj
    }//fori
    
    
    for(int i=0;i<size;i++){
        for(int j=0;j<=k;j++){
           printf("%d\t", dp[i][j] );
        }//forj
        printf("\n");
    }//fori
    
    return dp[size-1][k];
}//subsetExists

int main() {
	//code
// 	int weights[] = {1, 3, 4, 8};
// 	int k = 6;
	int weights[] = {1, 2, 3, 7};
	int k = 6;
	
	int size = sizeof(weights)/sizeof(weights[0]);
//  recursive solution
// 	int sum=0;
// 	if(subsetExists(weights, &sum, k, 0, size))
// 	    printf("Yes");
// 	else
// 	    printf("NO");

    if(subsetExists(weights, k, size))
        printf("Yes");
    else
        printf("No");
	
	return 0;
}
