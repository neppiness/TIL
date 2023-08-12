import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String[] str = new String[3];
    static HashMap<String, Integer> map = new HashMap<>();

    public static void main(String[] args) throws IOException {
        for (int i = 0; i < 3; i++)
            str[i] = br.readLine();

        Integer ans = 0;
        for (int i = 0; i < 3; i++) {
            int code = (1 << i);
            for (int len = 1; len <= str[i].length(); len++) {
                for (int stidx = 0; stidx + len <= str[i].length(); stidx++) {
                    String substr = str[i].substring(stidx, stidx + len);

                    Integer foundValue = map.get(substr);
                    if (foundValue == null) {
                        map.put(substr, code);
                        foundValue = code;
                    }
                    int valueToBeUpdated = (foundValue | code);
                    if (valueToBeUpdated == 7) {
                        ans = Math.max(ans, len);
                        System.out.println(substr);
                    }
                    map.put(substr, valueToBeUpdated);
                }
            }
        }
        System.out.println(ans);
    }
}