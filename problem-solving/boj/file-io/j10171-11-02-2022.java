import java.io.BufferedWriter;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String args[]) throws Exception {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write("\\    /\\\n");
        bw.write(" )  ( ')\n");
        bw.write("(  /  )\n");
        bw.write(" \\(__)|\n");
        bw.flush();
    }
}