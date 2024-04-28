import static java.lang.Integer.parseInt;
import static java.time.temporal.ChronoUnit.DAYS;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.time.LocalDate;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        LocalDate today = LocalDate.of(
                parseInt(st.nextToken()),
                parseInt(st.nextToken()),
                parseInt(st.nextToken())
        );
        st = new StringTokenizer(br.readLine());
        LocalDate dDay = LocalDate.of(
                parseInt(st.nextToken()),
                parseInt(st.nextToken()),
                parseInt(st.nextToken())
        );
        if (!today.plusYears(1000L).isAfter(dDay)) {
            System.out.println("gg");
            return;
        }
        long ans = DAYS.between(today, dDay);
        System.out.println("D-" + ans);
    }

}

