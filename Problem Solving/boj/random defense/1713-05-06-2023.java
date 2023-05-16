import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static StringTokenizer st;

    static int n, m;
    static int[] cnt = new int[102];
    static TreeSet<FrameInfo> frame = new TreeSet<>();

    static class FrameInfo implements Comparable<FrameInfo> {
        public int noOfRec, registeredTurn, studentNo;

        FrameInfo(int noOfRec_, int registeredTurn_, int studentNo_) {
            this.noOfRec = noOfRec_;
            this.registeredTurn = registeredTurn_;
            this.studentNo = studentNo_;
        }

        @Override
        public int compareTo(FrameInfo rt) {
            if (this.noOfRec == rt.noOfRec)
                return this.registeredTurn - rt.registeredTurn;
            return this.noOfRec - rt.noOfRec;
        }
    }

    static FrameInfo findByStudentNo(int no) {
        for (FrameInfo frInfo : frame)
            if (frInfo.studentNo == no) return frInfo;
        return null;
    }

    public static void main(String[] args) throws IOException {

        n = Integer.parseInt(br.readLine());
        m = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());

        for (int turn = 1; turn <= m; turn++) {
            int x = Integer.parseInt(st.nextToken());
            FrameInfo foundFi = findByStudentNo(x);

            if (foundFi == null) {
                if (frame.size() == n)
                    frame.pollFirst();
                frame.add(new FrameInfo(1, turn, x));
            } else {
                frame.remove(foundFi);
                foundFi.noOfRec++;
                frame.add(foundFi);
            }
        }

        ArrayList<Integer> studentNos = new ArrayList<>();
        for (FrameInfo frInfo : frame)
            studentNos.add(frInfo.studentNo);
        Collections.sort(studentNos);
        for (int sn : studentNos) sb.append(sn).append(' ');
        System.out.print(sb);
    }
}