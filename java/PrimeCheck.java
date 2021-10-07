import java.util.*;
public class Bubble
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner (System.in);
		System.out.println("Enter a number");
		int n=sc.nextInt();
		int c = 0;

        if(n%2==0)
            c++;
        
        for(int i =3 ; i <= Math.sqrt(n);i+=2){
            if(n%i==0)
                c++;
            if(c>0)
              break;    
        }
        System.out.println( c==0?"Prime":"not prime" );
	}
}