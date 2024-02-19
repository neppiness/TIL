import java.io.*;
import java.util.*;

public class Main {

    static class Student implements Comparable<Student> {

        public String name;
        public int korean;
        public int english;
        public int math;

        public Student(String name, String korean, String english, String math) {
            this.name = name;
            this.korean = Integer.parseInt(korean);
            this.english = Integer.parseInt(english);
            this.math = Integer.parseInt(math);
        }

        @Override
        public int compareTo(Student rightTerm) {
            if (this.korean == rightTerm.korean) {
                if (this.english == rightTerm.english) {
                    if (this.math == rightTerm.math) {
                        return this.name.compareTo(rightTerm.name);
                    }
                    return rightTerm.math - this.math;
                }
                return this.english - rightTerm.english;
            }
            return rightTerm.korean - this.korean;
        }

    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Student[] students = new Student[n];

        StringTokenizer st;
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            String name = st.nextToken();
            String korean = st.nextToken();
            String english = st.nextToken();
            String math = st.nextToken();
            students[i] = new Student(name, korean, english, math);
        }

        Arrays.sort(students);
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            sb.append(students[i].name).append('\n');
        }
        System.out.print(sb);
    }

}

