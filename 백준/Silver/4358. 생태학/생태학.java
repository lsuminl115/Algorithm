import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		TreeMap<String, Integer> map = new TreeMap<>();
		TreeSet<String> set = new TreeSet<>();
		int count=0;
		while(scan.hasNext())
		{
			String s = scan.nextLine();
			Integer cnt = map.get(s);
			map.put(s, (cnt==null) ? 1 : cnt+1);
			set.add(s);
			count++;
		}
		
		for(String ss : set)
		{
			System.out.printf("%s %.4f\n",ss,(double)map.get(ss) / (double)count * 100);
		}
		scan.close();
		
	}

}