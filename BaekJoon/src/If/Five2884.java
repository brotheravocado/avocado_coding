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
public class Five2884 {
   
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int hour, minute;
        hour = scanner.nextInt();
        minute = scanner.nextInt();

        if (minute - 45 < 0) {
            if (hour == 0) {
                hour = 24;
            }
            hour--;
            minute = 60 + (minute - 45);
        } else {
            minute = minute - 45;
        }
        System.out.println(hour+" "+minute);
    }
}


