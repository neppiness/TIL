import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int n, m;
    static LinkedList<Integer> cr, box;

    static void setup() throws IOException {
        n = Integer.parseInt(br.readLine());
        cr = new LinkedList<>();

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) 
            cr.add(Integer.parseInt(st.nextToken()));
        Collections.sort(cr, Collections.reverseOrder());

        m = Integer.parseInt(br.readLine());
        box = new LinkedList<>();

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < m; i++)
            box.add(Integer.parseInt(st.nextToken()));
        Collections.sort(box, Collections.reverseOrder());
    }

    public static void main(String args[]) throws IOException {
        setup();

    }
}