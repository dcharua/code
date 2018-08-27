//Programa to read Fibonacci Numbers
import java.util.Scanner;

//Regresion
public class Fibonacci {
  public static int fib1(int n){
    if ((n == 0)|| (n == 1)) return n;
    else return fib1(n-1) + fib1(n-2);
  }

//Interation
  public static int fib2(int n){
    int [] f = new int[n+1];
    if ((n == 0)|| (n == 1)) return n;
    else{
      f[0] = 0;
      f[1] = 1;
      for (int i=2; i < n+1; i++)
        f[i] = f[i-1] + f[i-2];
      }
      return f[n];
    }
  public static void main(String arg[]){
    Scanner in = new Scanner(System.in);
    System.out.print("numero: ");
    int n = in.nextInt();
    System.out.println("Resultado: " + fib2(n));
    in.close();
  }
}
