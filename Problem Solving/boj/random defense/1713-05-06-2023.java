import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();

    static int n, m;
    static int[] cnt = new int[102];
    static TreeMap<Integer, FrameInfo> frame = new TreeMap<>();

    static class FrameInfo implements Comparable<FrameInfo> {
        public int noOfRec, registeredTurn;

        FrameInfo(int noOfRec_, int registeredTurn) {
            this.noOfRec = noOfRec_;
            this.registeredTurn = registeredTurn;
        }

        @Override
        public int compareTo(FrameInfo rt) {
            if (this.noOfRec == rt.noOfRec)
                return this.registeredTurn - rt.registeredTurn;
            return this.noOfRec - rt.noOfRec;
        }
    }

    public static void main(String[] args) throws IOException {

        n = Integer.parseInt(br.readLine()); // 사진틀 개수 제한
        m = Integer.parseInt(br.readLine());

        for (int turn = 1; turn <= m; turn++) {
            int x = Integer.parseInt(br.readLine());
            if (frame.size() <= n) {
                FrameInfo frinfo = frame.get(x);
                if (frinfo == null) frame.put(x, new FrameInfo(1, turn));
                else frinfo.noOfRec++;
            }
            
            // 현재까지 추천 받은 횟수가 가장 적은 학생이 두 명 이상일 경우에는
            // 그러한 학생들 중 게시된 지 가장 오래된 사진을 삭제한다.
        }

        for (Map.Entry<Integer, FrameInfo> entry : frame.entrySet()) {
            sb.append(entry.getValue());
        }
    }
}