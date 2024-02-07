import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int n, m, ans;
    static Integer[] cr;
    static LinkedList<Integer> box;

    static void setup() throws IOException {
        n = Integer.parseInt(br.readLine());
        cr = new Integer[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++)
            cr[i] = Integer.parseInt(st.nextToken());
        Arrays.sort(cr, Collections.reverseOrder());

        m = Integer.parseInt(br.readLine());
        box = new LinkedList<>();

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < m; i++)
            box.add(Integer.parseInt(st.nextToken()));
        box.sort(Collections.reverseOrder());
    }

    static void solve() {
        if (cr[0] < box.get(0)) { ans = -1; return; }

        ans = 0;
        while(!box.isEmpty()) {
            int cridx = 0;
            Iterator<Integer> boxIterator = box.iterator();
            while (cridx < n  && boxIterator.hasNext()) {
                // 크레인 용량이 박스 무게보다 작을 경우 다음 박스를 본다.
                if (cr[cridx] < boxIterator.next()) continue;
                // 크레인 용량이 박스 무게보다 크기 때문에 현 박스 인덱스를 지운다.
                boxIterator.remove();
                // 크레인을 사용했기 때문에 크레인 인덱스를 증가시킨다.
                cridx++;
            }
            // 크레인을 다 썼거나, 더 이상 확인할 박스가 없다면 한 턴을 추가한다.
            ans++;
        }
    }

    public static void main(String args[]) throws IOException {
        setup();
        solve();
        bw.write(String.valueOf(ans));
        bw.flush();
    }
}