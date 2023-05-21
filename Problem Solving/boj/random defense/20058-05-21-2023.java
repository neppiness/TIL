import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int[][] ice = new int[66][66];
    static ArrayList<Integer> fs = new ArrayList<>();

    static int n, lg, q;

    void fireStorm(int f) {

    }

    void printResult() {
        
    }


    public static void main(String[] args) throws IOException {

        st = new StringTokenizer(br.readLine());
        lg = Integer.parseInt(st.nextToken());
        q = Integer.parseInt(st.nextToken());
        n = (1 << lg);

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine()); 
            for (int j = 0; j < n; j++)
                ice[i][j] = Integer.parseInt(st.nextToken());
        }
        
        st = new StringTokenizer(br.readLine());
        while (st.hasMoreTokens())
            fs.add(Integer.parseInt(st.nextToken()));
        
        for (int f : fs) fireStorm(f);
        printResult();
    }
}