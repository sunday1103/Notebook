import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {
	static Scanner scanner;
	static boolean debug=true;
	int N;
	int arr[];
	int prime_list[];
	int is_prime[]; //初始化为最大偶数

	bool is_prime(int num){
		int k=sqrt(m);
   		int i;
		for (i=2;i<=k;i++)
			if (m%i==0) break;
		if (i>k) return 1;
		else return 0;
	}

	void init()
	{
		is_prime[]; //初始化大小为 max oushu
	}

	int my_distance(int a, int b)
	{
		int dis = 0
		for (int i = a; i < b; i++) {
			if (is_prime(i)) {
				dis++;
			}
		}
		return dis;
	}

	void my_f()
	{
		//最小和最大偶数之间的距离
		int a = arr[0];
		int b = arr[N-1];
		int distance = 0;
		int distance_sum = 0;
		for (int i = a; i < b; i++) {
			if (is_prime(i)) {
				distance++;
				is_prime[i] = 1;
			}
			else{
				is_prime[i] = 0;
			}
		}

		distance_sum += distance;

		int i = 0;
		int j = 1;
		while(1)
		{
			distance_sum += my_distance(arr[i], arr[j]);

			if (j == N-1) {
				i++;
				j = i;
				if (i = N - 1) break;
			}
			j++;
		}

		int count[] = new int //大小为 size -1 . init is 0;

		int i = 0;
		int j = 1;
		while(j <= size -1)
		{
			for
		}



	}
	
	public static void main(String[] args){
		scanner=new Scanner(System.in);
		Main obj= new Main();
		while(scanner.hasNext()){
			N = a=scanner.nextInt();
			读入数组中
		}
		init();
		my_f();
	}

}