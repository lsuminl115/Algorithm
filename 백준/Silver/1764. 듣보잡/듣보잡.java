import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        Set<String> set = new TreeSet<>();
        List<String> list = new ArrayList<>();
        int count = 0;

        String s = scan.nextLine();
        String[] arr = s.split(" ");
        int n = Integer.parseInt(arr[0]);
        int m = Integer.parseInt(arr[1]);
        for(int i=0; i<n;i++)
        {
            String ss = scan.nextLine();
            set.add(ss);
        }
        for(int i=0; i<m; i++)
        {
            String ss = scan.nextLine();
            if(set.contains(ss)) 
            {
                count++;
                list.add(ss);
            }
        }
        Collections.sort(list);
        System.out.println(count);
        for(String sss : list) System.out.println(sss);
        scan.close();
    }
}
