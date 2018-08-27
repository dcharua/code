//Daniel Charua  A01017419    09/04/17

import java.io.IOException;
import java.util.concurrent.TimeUnit;


public class Main{
    public static void main(String arg[]) throws IOException {

    WeightedGraph wg = new WeightedGraph().readGraph("P2Edges.txt");
    MST mst = new MST();

    long lStartTime = System.currentTimeMillis();
    System.out.println("Prim");
    System.out.println("Total weight: "+ mst.prim(wg, 1 ));
    long lEndTime = System.currentTimeMillis();
    long output = lEndTime - lStartTime;
    System.out.println("Elapsed time in milliseconds: " + output);
    System.out.println("");

    lStartTime = System.currentTimeMillis();
    System.out.println("PrimHeap");
    System.out.println("Total weight: "+ mst.primHeap(wg, 1));
    lEndTime = System.currentTimeMillis();
    output = lEndTime - lStartTime;
    System.out.println("Elapsed time in milliseconds: " + output);
    System.out.println("");

    lStartTime = System.currentTimeMillis();
    System.out.println("Kruskal");
    System.out.println("Total weight: "+ mst.kruskal(wg));
    lEndTime = System.currentTimeMillis();
    output = lEndTime - lStartTime;
    System.out.println("Elapsed time in milliseconds: " + output);
    System.out.println("");

    lStartTime = System.currentTimeMillis();
    System.out.println("Kruskal Union-Find");
    System.out.println("Total weight: "+ mst.kruskalUF(wg));
    lEndTime = System.currentTimeMillis();
    output = lEndTime - lStartTime;
    System.out.println("Elapsed time in milliseconds: " + output);
    System.out.println("");
    }
}
