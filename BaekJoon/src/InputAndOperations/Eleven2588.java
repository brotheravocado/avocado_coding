/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package InputAndOperations;

import java.util.Scanner;

/**
 *
 * @author dbswl
 */
public class Eleven2588 {
public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int a, b, c, a1, a2, a3;
        a = scan.nextInt();
        b = scan.nextInt();

        c = b - b / 10 * 10;
        a1 = (a / 100) * c * 100 + c * (a / 10 - a / 100 * 10) * 10 + c * (a - a / 10 * 10);
        System.out.println(a1);
        c = (b / 10) % 10;
        a2 = (a / 100) * c * 100 + c * (a / 10 - a / 100 * 10) * 10 + c * (a - a / 10 * 10);
        System.out.println(a2);
        c = b / 100;
        a3 = (a / 100) * c * 100 + c * (a / 10 - a / 100 * 10) * 10 + c * (a - a / 10 * 10);
        System.out.println(a3);
        System.out.println(a1+a2*10+a3*100);

    }
}
