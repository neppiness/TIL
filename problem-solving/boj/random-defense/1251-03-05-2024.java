import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        List<String> stringList = new ArrayList<>();

        for (int i = 1; i < s.length(); i++) {
            for (int j = i + 1; j < s.length(); j++) {
                String ss1 = s.substring(0, i);
                String ss2 = s.substring(i, j);
                String ss3 = s.substring(j);
                if (ss2.length() == 0) {
                    continue;
                }
                StringBuilder sb1 = new StringBuilder(ss1);
                StringBuilder sb2 = new StringBuilder(ss2);
                StringBuilder sb3 = new StringBuilder(ss3);
                sb1.reverse();
                sb2.reverse();
                sb3.reverse();
                String newString = sb1
                        .append(sb2)
                        .append(sb3)
                        .toString();
                stringList.add(newString);
            }
        }
        Collections.sort(stringList);
        System.out.print(stringList.get(0));
    }

}

