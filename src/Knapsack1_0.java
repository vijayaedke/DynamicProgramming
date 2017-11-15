import java.util.Scanner;


public class Knapsack1_0{
	static int table[][];
	public static void main(String  args[]){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int weight[] = new int[n];
		int value[] = new int[n];
		sc.nextLine();
		for(int i=0;i<n;i++){
			String str = sc.nextLine();	
			String s1[] = str.split(" ");
			weight[i] = Integer.parseInt(s1[0]);
			value[i] = Integer.parseInt(s1[1]);
		}//for
		int total = sc.nextInt();
		
		initTable(n,total);
		int res = calculateValue(n,weight,value,total);
		System.out.println(res);
	}//main	
	private static int calculateValue(int n, int[] weight, int[] value,	int total) {
		// TODO Auto-generated method stub
		
		for(int i=0;i<=n;i++){
			
			for(int j=0;j<=total;j++){
				
				if(i==0 || j==0)
					table[i][j] =0;
				
				else if(weight[i-1] <= j)
					table[i][j] = Math.max(value[i-1]+table[i-1][j-weight[i-1]], table[i-1][j]);
				else
					table[i][j]=table[i-1][j];
			}//for j
		}//for i 
		
		return table[n][total];
	}//calculateValue() 
	private static void initTable(int n, int total) {
		// TODO Auto-generated method stub
		table = new int[n+1][total+1];
		
		for(int i=0;i<=n;i++)
			table[i][0]=0;
	}//initTable
}//Knapsack1_0