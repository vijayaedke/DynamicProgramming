import java.util.Scanner;


public class SumOfSubset {
  static boolean table[][];
  
  public static void main(String args[]){
	  Scanner sc = new Scanner(System.in);
	  
	  int n = sc.nextInt();
	  int array[] = new int[n];
	  for(int i=0;i<n;i++){
		  array[i] = sc.nextInt();
	  }//for
	  int sum = sc.nextInt();
	  
	  initTable(n,sum);
	  boolean result = checkSumOfSubset(n,sum,array);
	  System.out.println(result);
  }//main()

private static boolean checkSumOfSubset(int n, int sum,int array[]) {
	// TODO Auto-generated method stub
	for(int i=0;i<=n;i++){
		for(int j=0;j<=sum;j++){
			if(i==0 || j==0)
				table[i][j] = true;
			else if(j>=array[i-1])
				table[i][j] = table[i-1][j-array[i-1]] || table[i-1][j];
			else
				table[i][j] = table[i-1][j];
		}//forj
	}//fori
	
	return table[n][sum];
}//checkSumOfSubset

private static void initTable(int n,int sum) {
	// TODO Auto-generated method stub
	table = new boolean[n+1][sum+1];
	
	for(int i =0;i<n; i++){
		table[i][0] =true;
	}//for
}//initTable()


}//sumofSubset
