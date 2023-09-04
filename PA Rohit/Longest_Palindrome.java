import java.util.*;

public class Longest_Palindrome{


    // ab$cba  -> "ab$cba"
    public static List<String> longestPallindromeSubstring(String str) {

        int maxLength = 0;
        List<String> answer = new ArrayList<>();
        // odd Pallindroms
        for (int i = 0; i < str.length(); i++) {

            if(!isValidCharacter(str.charAt(i))) {
                continue;
            }
            answer = AddValidSubstring(str, i - 1, i + 1, maxLength, answer);
            if (answer.size() != 0) {
                maxLength = answer.get(0).length();
            }

        }


        // even Pallindroms
        for (int i = 0; i < str.length(); i++) {

            if(!isValidCharacter(str.charAt(i))) {
                continue;
            }

            int j = i + 1;

            while(j < str.length() && !isValidCharacter(str.charAt(j))) {
                j++;
            }

            if(!(j < str.length() && areCharactersEqual(str.charAt(i) , str.charAt(j)))) {
                continue;
            }

            answer = AddValidSubstring(str, i - 1, j + 1, maxLength, answer);
            if (answer.size() != 0) {
                maxLength = answer.get(0).length();
            }

        }

        return answer;
    }

    public static List<String> AddValidSubstring(String str, int L , int R, int maxLength, List<String> answer) {
        L = decrementL(L , str);
        R = incrementR(R,  str);


        while((L >= 0 && R < str.length()) && (str.charAt(L) == str.charAt(R))) {

            if ((R - L + 1) > maxLength) {
                maxLength = R - L + 1;
                answer = new ArrayList<>();
                answer.add(str.substring(L, R + 1));
            } 
            else if ((R - L  + 1) == maxLength) {
                answer.add(str.substring(L, R + 1));
            }

            L = decrementL(L - 1, str);
            R = incrementR(R + 1, str);
        }

        return answer;
    }

    public static boolean isValidCharacter(char ch) {
        if ((ch >= 'A' && ch <= 'Z') ||
                (ch >= 'a' && ch <= 'z') ||
                (ch >= '0' && ch <= '9')) {
            return true;
        }
        return false;
    }

    public static int decrementL(int L, String str) {
        while(L >= 0 && !isValidCharacter(str.charAt(L)) ) {
            L--;
        }

        return L;
    }

    public static int incrementR(int R, String str) {
        while(R < str.length() && !isValidCharacter(str.charAt(R)) ) {
            R++;
        }
        return R;
    }

    public static boolean areCharactersEqual(char ch , char ch2) {
        ch = convertLowerCase(ch);
        ch2 = convertLowerCase(ch2);

        return ch == ch2;
    }

    public static char convertLowerCase(char ch) {
        if(ch >= 'A' && ch <= 'Z') {
            return (char)(ch + 32);
        }
        return ch;
    }



    public static void main(String[] args) {
        System.out.println(longestPallindromeSubstring("@3$AA!!AA@@@")); // "AA"  A ->  ! ! ! "A"
    }
}


