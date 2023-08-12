import java.io.*;
import java.util.*;

public class Main {

    static class Coord implements Comparable<Coord> {
        public int x, y;
        public Coord(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(Coord o) {
            if (this.y == o.y)
                return this.x - o.x;
            return this.y - o.y;
        }
    }

    static ArrayList<Coord> coords = new ArrayList<>();

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        while (n-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            coords.add(new Coord(x, y));
        }
        Collections.sort(coords);

        for (Coord c : coords) {
            bw.write(String.valueOf(c.x));
            bw.write(' ');
            bw.write(String.valueOf(c.y));
            bw.write('\n');
        }
        bw.flush();
    }
}