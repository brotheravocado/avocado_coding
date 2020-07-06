/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package newpackage;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 *
 * @author dbswl
 */
public class NewClass {
    public static void main(String[]args) throws IOException{
        File myFile = new File("C:\\테스트.txt");
        
        FileInputStream fileInputStream = new FileInputStream(myFile);
        BufferedReader bufferedReader = null;
        bufferedReader = new BufferedReader(new InputStreamReader(fileInputStream,"UTF-8"));
        
        String   str = bufferedReader.readLine();
        
        System.out.println(str);
        
    }
}
