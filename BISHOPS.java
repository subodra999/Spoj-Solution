/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;

/* Name of the class has to be "Main" only if the class is public. */
class Ideone
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		Scanner s = new Scanner(System.in);
		while (s.hasNextBigInteger()) {
    		BigInteger a = s.nextBigInteger();
    		if(a.equals(BigInteger.ONE))
    		{
    			System.out.println(a);
    		}
    		else
    		{
    			a = a.add(a);
				a = a.subtract(BigInteger.valueOf(2));
    			System.out.println(a);    		
    		}

		}

	}
}