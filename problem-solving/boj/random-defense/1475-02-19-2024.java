import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String a = br.readLine();
        int[] count = new int[9];
        for (int i = 0; i < a.length(); i++) {
            char c = a.charAt(i);
            c -= '0';
            if (c == 9) c = 6;
            count[c]++;
        }
        count[6] = count[6] / 2 + count[6] % 2;
        int max = 0;
        for (int i = 0; i < 9; i++) {
            max = Math.max(max, count[i]);
        }
        System.out.print(max);
    }

}

