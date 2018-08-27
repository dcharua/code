import java.util.concurrent.TimeUnit;
import java.io.IOException;


public class Main{
public static void main(String arg[]) throws IOException {
    Arreglo arr = new Arreglo();
    arr.lecturaDatos(arg[0]);
    long lStartTime = System.currentTimeMillis();
    arr.bubbleSort();
    long lEndTime = System.currentTimeMillis();
    long output = lEndTime - lStartTime;
    System.out.println("Elapsed time in milliseconds: " + output);
    System.out.println("");


    arr.lecturaDatos(arg[0]);
    lStartTime = System.currentTimeMillis();
    arr.selectionSort();
    lEndTime = System.currentTimeMillis();
    output = lEndTime - lStartTime;
    System.out.println("Elapsed time in milliseconds: " + output);
    System.out.println("");


    arr.lecturaDatos(arg[0]);
    lStartTime = System.currentTimeMillis();
    arr.insertionSort();
    lEndTime = System.currentTimeMillis();
    output = lEndTime - lStartTime;
    System.out.println("Elapsed time in milliseconds: " + output);
    System.out.println("");

    arr.escribeDatos("datos.txt", 100000, 3);
    arr.lecturaDatos("datos.txt");
    lStartTime = System.currentTimeMillis();
    arr.quickSort();
    lEndTime = System.currentTimeMillis();
    output = lEndTime - lStartTime;
    System.out.println("Elapsed time in milliseconds: " + output);
    System.out.println("");


    arr.lecturaDatos(arg[0]);
    lStartTime = System.currentTimeMillis();
    arr.mergeSort();
    lEndTime = System.currentTimeMillis();
    output = lEndTime - lStartTime;
    System.out.println("Elapsed time in milliseconds: " + output);
    System.out.println("");


    arr.lecturaDatos(arg[0]);
    lStartTime = System.currentTimeMillis();
    arr.heapSort();
    lEndTime = System.currentTimeMillis();
    output = lEndTime - lStartTime;
    System.out.println("Elapsed time in milliseconds: " + output);
    System.out.println("");


    arr.lecturaDatos(arg[0]);
    lStartTime = System.currentTimeMillis();
    arr.radixSort();
    lEndTime = System.currentTimeMillis();
    output = lEndTime - lStartTime;
    System.out.println("Elapsed time in milliseconds: " + output);
    System.out.println("");
    }
}
