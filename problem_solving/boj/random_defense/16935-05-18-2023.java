import java.io.*;
import java.util.*;
import static java.lang.Integer.parseInt;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static StringTokenizer st;

    static int m, n, r; // m: no of rows, n: no of cols
    static int[][] b = new int[102][102];
    static int[][] tmp = new int[102][102];

    static void copy() {
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) 
                b[i][j] = tmp[i][j];
    }

    static void swap() {
        int t = m;
        m = n;
        n = t;
    }

    static void verticallyInvert() {
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                tmp[i][j] = b[m - i - 1][j];
        copy();
    }

    static void horizontallyInvert() {
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                tmp[i][j] = b[i][n - j - 1];
    }

    static void rotateCW() {
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                tmp[j][m - 1 - i] = b[i][j];
        swap();
        copy();
    }

    static void rotateCCW() {
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                tmp[n - 1 - j][i] = b[i][j];
        swap();
        copy();
    }

    static void divideAndRotateCW() {
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (i / (m / 2) == 0) {
                    if (j / (n / 2) == 0) tmp[i][j + (n / 2)] = b[i][j];
                    else tmp[i + (m / 2)][j] = b[i][j];
                } else {
                    if (j / (n / 2) == 0) tmp[i - (m / 2)][j] = b[i][j];
                    else tmp[i][j - (n / 2)] = b[i][j];
                }
            }
        copy();
    }

    static void divideAndRotateCCW() {
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (i / (m / 2) == 0) {
                    if (j / (n / 2) == 0) tmp[i + (m / 2)][j] = b[i][j];
                    else tmp[i][j - (n / 2)] = b[i][j];
                } else {
                    if (j / (n / 2) == 0) tmp[i][j + (n / 2)] = b[i][j];
                    else tmp[i - (m / 2)][j] = b[i][j];
                }
            }
        copy();
    }

    static void operate(int com) {
        switch (com) {
            case 1: verticallyInvert(); break;
            case 2: horizontallyInvert(); break;
            case 3: rotateCW(); break;
            case 4: rotateCCW(); break;
            case 5: divideAndRotateCW(); break;
            default: divideAndRotateCCW();
        }
        copy();
    }

    public static void main(String[] args) throws IOException {

        st = new StringTokenizer(br.readLine());
        m = parseInt(st.nextToken());
        n = parseInt(st.nextToken());
        r = parseInt(st.nextToken());

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++)
                b[i][j] = parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < r; i++) {
            int com = parseInt(st.nextToken());
            operate(com);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                sb.append(b[i][j]).append(' ');
            sb.append('\n');
        }
        System.out.print(sb);
    }
}