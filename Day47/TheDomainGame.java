 /*
 Description: A website domain like "mail.google.com" consists of various subdomains.
At the top level, we have "com", at the next level, we have "google.com" and at the lowest level, "mail.google.com".
When we visit a domain like "mail.google.com", we will also visit the parent domains "google.com" and "com" implicitly.
The count-paired domain is a count (representing the number of visits this domain received) followed by a space, followed by the address.
An example of a count-paired domain might be "9001 mail.google.com".
You are given a list cpdomains of count-paired domains. You need to return a list of count-paired domains, (in the same format as the input, and in any order) that explicitly counts the number of visits to each subdomain.
 */
 
 import java.util.ArrayList;
 import java.util.Collection;
 import java.util.Collections;
 import java.util.HashMap;
 import java.util.List;
 import java.util.Scanner;
 
 public class Main {
 
 	 public static List<String> subdomainVisits(String[] cpdomains) 
      {
 	 	 HashMap<String, Integer> domainMap = new HashMap<>();
 	 	 for (String eachDomain : cpdomains) 
           {
 	 	 	 String[] completeLine = eachDomain.split("\\s+");
 	 	 	 String[] actualNames = completeLine[1].split("\\.");
 	 	 	 int count = Integer.valueOf(completeLine[0]);
 	 	 	 String cur = "";
 
 	 	 	 for (int i = actualNames.length - 1; i >= 0; --i) 
                {
 	 	 	 	 cur = actualNames[i] + (i < actualNames.length - 1 ? "." : "") + cur;
 	 	 	 	 domainMap.put(cur, domainMap.getOrDefault(cur, 0) + count);
 	 	 	 }
 	 	 }
 
 	 	 List<String> ans = new ArrayList<>();
 	 	 for (String dom : domainMap.keySet())
 	 	 	 ans.add("" + domainMap.get(dom) + " " + dom);
 	 	 return ans;
 	 }
 
 	 public static void main(String[] args) {
 	 	 Scanner s = new Scanner(System.in);
 	 	 int n = Integer.parseInt(s.nextLine());
 	 	 String[] cpd = new String[n];
 	 	 for (int i = 0; i < cpd.length; i++) {
 	 	 	 cpd[i] = s.nextLine();
 	 	 }

 	 	 List<String> ans = subdomainVisits(cpd);
 	 	 Collections.sort(ans);
 	 	 System.out.println(ans);
 	 }
 
 }