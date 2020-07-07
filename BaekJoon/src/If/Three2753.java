/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package If;

/**
 *
 * @author dbswl
 */
import java.util.Scanner;

public class Three2753 {
    public static void main(String[]args){
        Scanner scanner = new Scanner(System.in);
        
        int year;
        year = scanner.nextInt();
        
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
            System.out.println("1");
            }
        else{
            System.out.println("0");
        }
        }
    }

