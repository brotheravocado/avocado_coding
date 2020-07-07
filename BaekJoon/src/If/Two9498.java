/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package If;
import java.util.Scanner;
/**
 *
 * @author dbswl
 */
public class Two9498 {
        public static void main(String[] args) {

        int score;
        Scanner scan = new Scanner(System.in);
        score = scan.nextInt();
        if (score >= 90) {
             System.out.println("A");
        } else if (score >= 80) {
            System.out.println("B");
        } else if (score >= 70) {
            System.out.println("C");
        } else if (score >= 60) {
            System.out.println("D");
        } else {
            System.out.println("F");
        }
    }
}
