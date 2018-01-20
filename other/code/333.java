
import java.util.*;

public class Main {
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		String str = in.nextLine();
		in.close();
		int max = 0;
		if(str.charAt(0) == str.charAt(1))
			max = 1;
		for(int i=1; i<str.length()-1; i++){
			int currentmax = -1;
			if(str.charAt(i) == str.charAt(i+1)){
				currentmax = FindMax(str,i-1,i+2);
				if(currentmax > max){
					max = currentmax;
				}
			}
			if(str.charAt(i-1) == str.charAt(i+1)){
				currentmax = FindMax(str,i-2,i+2);
				if(currentmax > max){
					max = currentmax;
				}
			}
			
		}
		System.out.println(max);
	}
	public static int FindMax(String str, int from, int to){
		int solution = 1;
		int len = str.length();
		if(0 > from || len <= to)
			return solution;
		do{
			char a = str.charAt(from);
			char b = str.charAt(to);
			if(a == b){
				solution ++;
				from--;
				to++;
			}
			else{
				break;
			}
		}while(0 <= from && len > to);
		return solution;
	}

}