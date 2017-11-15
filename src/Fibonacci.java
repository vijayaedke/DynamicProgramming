import java.util.Scanner;


public class Fibonacci {
	static int lookup[];
	public static void main(String args[]){
		
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		init(n);
		int res = calFib(n);
		System.out.println(res);
	}//main

	private static int calFib(int n) {
		// TODO Auto-generated method stub
		if(n<=1)
			lookup[n]= n;
		else {
			lookup[n] = calFib(n-1)+calFib(n-2);
	
		}//else
		return lookup[n];
	}

	static void init(int n){
		lookup = new int[n+1];
		lookup[0]=0;
		lookup[1]=1;
			for(int i=2;i<n;i++){
				lookup[i]=-1;
			}//for
		
	}//init
}//Fibonacci
