import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] numbers = new int[10];
        int max = 0;
        for (int i = 1; i < 10; i++) {
            String line = br.readLine();
            int x = Integer.parseInt(line);
            numbers[i] = x;
            max = Math.max(max, x);
        }
        System.out.println(max);
        for (int i = 1; i < 10; i++) {
            if (max != numbers[i]) continue;
            System.out.println(i);
            break;
        }
    }

}

