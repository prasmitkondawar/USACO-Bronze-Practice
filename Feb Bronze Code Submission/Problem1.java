import java.util.Scanner;

public class Problem1 {
    public static void main(String[] args) {
        Scanner kboard = new Scanner(System.in);
        int t = kboard.nextInt();
        String s = "";
        for(int i = 0; i < t; i++) {
            s = kboard.next();

            boolean pali = true;
            for(int j = 0; j < s.length(); j++) {
                if(s.charAt(j) != s.charAt(s.length() - 1 - j)) {
                    pali = false;
                    break;
                }
            }

            boolean solved = false;
            if(s.length() < 2 || pali) {
                System.out.println("B");
                solved = true;
            }
            if(!solved) {
                if (s.charAt(s.length() - 1) == '0') System.out.println("E");
                else System.out.println("B");
            }
        }
    }
}