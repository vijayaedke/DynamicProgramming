import java.util.Scanner;


public class LIS {
	static int table[][];
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		String s1 = sc.next();
		String s2 = sc.next();
		
		initTable(s1.length(),s2.length());
		int r = longestCommonSubsequence(s1,s2);
		System.out.println(r);
	}//main
	private static int longestCommonSubsequence(String s1, String s2) {
		// TODO Auto-generated method stub
		for(int i=0;i<=s1.length();i++){
			for(int j=0;j<=s2.length();j++){
				if(i==0 || j==0 )
					table[i][j] =0 ;
				else if(s1.charAt(i-1)==s2.charAt(j-1))
					table[i][j] = table[i-1][j-1]+1;
				else
					table[i][j] = Math.max(table[i-1][j],table[i][j-1]);
			}//forj			
		}	//fori	
		
		return table[s1.length()][s2.length()];
	}//longestCommonSubsequence
	
	
	private static void initTable(int length, int length2) {
		// TODO Auto-generated method stub
		table = new int[length+1][length2+1];
		for(int i=0;i<=length;i++){
			table[i][0] = 0;
		}//for
		
		for(int i=0;i<=length2;i++){
			table[0][i] = 0;
		}//for
	}//initTable()
	
	
}//LIS
