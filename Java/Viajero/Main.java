//Daniel Charua  A01017419    09/04/17

import java.util.*;
import java.io.*;

public class Main{
    public static void main(String arg[]) throws IOException {

    Travel t = new Travel();
    Travel2 t2 = new Travel2();

    ArrayList<City> city = new ArrayList<City>();
    int op;
    long lStartTime, lEndTime, output;

    System.out.println("");
    System.out.println("===          Menu              ===");
    System.out.println("=== 1. FB y PD con 10 ciudades ===");
    System.out.println("=== 2. PD con 25 ciudades      ===");
    System.out.println("");
    Scanner s = new Scanner(System.in);
    op=s.nextInt();
    switch (op) {
        case 1:
            System.out.println("TSP Fuerza Bruta 10: ");
            city = t.readCities("P4tsp10.txt");
            lStartTime = System.currentTimeMillis();
            t.TSPFB(city);
            lEndTime = System.currentTimeMillis();
            output = lEndTime - lStartTime;
            System.out.println("Elapsed time in milliseconds: " + output);
            System.out.println("");

            System.out.println("TSP Programacion dinamica 10: ");
            lStartTime = System.currentTimeMillis();
            System.out.println("Cost = " + t.TSPDP(city));
            lEndTime = System.currentTimeMillis();
            output = lEndTime - lStartTime;
            System.out.println("Elapsed time in milliseconds: " + output);
            System.out.println("");
        break;

        case 2:
            city = t2.readCities("P4tsp25.txt");
            System.out.println("TSP Programacion dinamica 25: ");
            lStartTime = System.currentTimeMillis();
            float p = t2.computeTSP(city);
            lEndTime = System.currentTimeMillis();
            output = lEndTime - lStartTime;
            System.out.println("Elapsed time in minutes: " + output/60000);
            System.out.println("");
        break;
        
        default:
            System.out.println("Numero invalido");
        break;
        }

    }
}
