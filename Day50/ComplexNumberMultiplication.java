/*
Description: A complex number can be represented as a string on the form "real+imaginaryi" where:

real is the real part and is an integer in the range [-100, 100].

imaginary is the imaginary part and is an integer in the range [-100, 100].

i2 == -1.

Given two complex numbers num1 and num2 as strings, return a string of the complex number that represents their multiplications.
*/

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class Solution {

    public static void main(String[] args)
    {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String p = sc.next();

        // Separate real and imaginary parts of numbers
        String[] tokens1 = s.split("[+]");
        int real1 = Integer.parseInt(tokens1[0]);
        int imag1 = Integer.parseInt(tokens1[1].split("i")[0]);

        String[] tokens2 = p.split("[+]");
        int real2 = Integer.parseInt(tokens2[0]);
        int imag2 = Integer.parseInt(tokens2[1].split("i")[0]);

        // Obtain 4 product components
        int a = (real1 * real2);
        int b = (real1 * imag2);
        int c = (real2 * imag1);
        // Since i2 is -1, imaginary product is negated
        int d = (imag1 * imag2 * -1);

        int real = (a + d);
        int imag = (b + c);

        String result = real + "+" + imag + "i";

        System.out.println(result);
    }
}