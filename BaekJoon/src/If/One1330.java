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
public class One1330 {
        public static void main(String[] args) {

        int a, b;
        Scanner scan = new Scanner(System.in);

        a = scan.nextInt();
        b = scan.nextInt();
        if (a > b) {
            System.out.println(">");
        } else if (a == b) {
            System.out.println("==");
        } else {
            System.out.println("<");
        }
    }
}
