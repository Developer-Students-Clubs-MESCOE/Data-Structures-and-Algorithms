// All subset of a string

import java.util.*;

public class AllSubsetOfString {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String st = sc.next();	//input string to find subset
        ArrayList<String> ans = new LexSort().powerSet(st);
        Collections.sort(ans);
        for(String s: ans)
            System.out.print(s + " ");
        System.out.println();
	}

}
class LexSort
{
    static ArrayList<String> powerSet(String s)
    {
    	ArrayList<String> list = new ArrayList<String>();
    	String a = "";
    	subSet( list,  s, a, 0, s.length());
		return list;
    }

	private static void subSet(ArrayList<String> list, String s, String a, int i, int n) {
		if (i==n) {
			list.add(a);
		} else {
			subSet(list, s, a+s.charAt(i), i+1, n);
			subSet(list, s, a, i+1, n);
		}
	}
}
