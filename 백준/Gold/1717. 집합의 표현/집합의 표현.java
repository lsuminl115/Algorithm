import java.util.*;
public class Main {
	static int[] parent = new int[1000001];
	public static int get(int x)
	{
		if(parent[x] == x) return x;
		else return parent[x] = get(parent[x]);
	}
	
	public static void union(int a, int b)
	{
		a = get(a);
		b = get(b);
		
		if(a < b) parent[b] = a;
		else parent[a] = b;
	}
	
	public static boolean cmp(int a, int b)
	{
		a = get(a);
		b = get(b);
		
		if(a == b) return true;
		else return false;
	}
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int m = scan.nextInt();
		for(int i=1; i<=n; i++) parent[i] = i;
		for(int i=0; i<m; i++)
		{
			int k = scan.nextInt();
			int a = scan.nextInt();
			int b = scan.nextInt();
			if(k == 0)
			{
				union(a, b);
			}
			else
			{
				if(cmp(a, b)) System.out.println("YES");
				else System.out.println("NO");
			}
		}
		scan.close();
	}

}
