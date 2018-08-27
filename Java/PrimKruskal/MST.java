//Daniel Charua  A01017419    09/04/17

import java.util.*;


public class MST{

 public static int prim (WeightedGraph G, int first) {
 int total = 0;
 final int [] weight = new int [G.vSize()+1];  // array to keep the weights
 final int [] vertex = new int [G.vSize()+1];  // array to keep the next vertex
 final boolean [] visited = new boolean [G.vSize()+1]; //boolean array to mark visited

      // loop to mark weight as maximun posible value
      for (int i=0; i<weight.length ; i++) {
          weight[i] = Integer.MAX_VALUE;
       }
       weight[first] = 0;

     for (int i=0; i<weight.length; i++) {
         // get best neighbor
        final int next = minVertex (weight, visited);
        if(next !=0){
            visited[next] = true;
            final int [] n = G.getNeighbor (next);
            //loop to find the cheapest weight
            for (int j=0; j<n.length; j++) {
                final int v = n[j];
                final int w = G.getWeight(next,v);
                if (weight[v] > w) {
                    weight[v] = w;
                    vertex[v] = next;
                }
            }
        // System.out.print( "From:" + vertex[next]  + " To:" + next + " Weight: " + G.getWeight(next,vertex[next]) + "  ");
         total +=  G.getWeight(next,vertex[next]);
       }
    }
    return total;
}

    //function to find best neighbor
    private static int minVertex (int [] weight, boolean [] visited) {
       int minWeight = Integer.MAX_VALUE;
       int bestNb = 0;
       for (int i=0; i<weight.length ; i++) {
          if (!visited[i] && weight[i]<minWeight) {
              bestNb = i;
              minWeight = weight[i];
          }
       }
    //   System.out.println(bestNb);
     return bestNb;
    }

 public static int primHeap (WeightedGraph G, int first) {
    int vSize = G.vSize();
    int eSize = G.eSize();
    int total = 0;
    int i =0;
    PriorityQueue<Edge> heap = new PriorityQueue<>(eSize*2, Collections.reverseOrder(new sortHeap())); //Queue with weight Priority
    final boolean [] visited = new boolean [vSize+1]; //boolean array to mark visited

    //Add neighbors from first vertex to the heap
    heap.addAll(G.getNeighborHeap (first));
    Edge e = heap.remove();
    visited[first] = true;
    total +=  e.getWeight();
    heap.addAll(G.getNeighborHeap ( e.getVertex2()));

    //loop to find mst, until the edges are vertex size -1
    while(i<vSize-2){
      visited[e.getVertex2()] = true;
      e = heap.remove();
      if(!visited[e.getVertex2()]){
          heap.addAll(G.getNeighborHeap ( e.getVertex2()));
           //System.out.print( "From:" + e.getVertex1()  + " To:" + e.getVertex2() + " Weight: " +e.getWeight() + "  ");
           total +=  e.getWeight();
           i++;
            }
        }
    return total;
 }

 public static int kruskal(WeightedGraph G){
     int vSize = G.vSize();
     int eSize = G.eSize();
     int  i = 0;
     int  total = 0;
     int [] path = new int[vSize +1]; //array to keep mst
     PriorityQueue<Edge> heap = new PriorityQueue<>(eSize, Collections.reverseOrder(new sortHeap())); //Queue with weight Priority
     //Loop to add all edges to the heap
     for (Edge e : G.getEdgesOneWay()) {
         heap.add(e);
     }
     //loop to Initialize path as 0
     for (int k=1; k<=vSize; k++) {
     path[k] = 0;
   }
   //loop to find mst, until the edges are vertex size -1
   while (i<vSize-1 ) {
     Edge e = heap.remove();
     if (checkCycle(e, path)) { //if edge doesnt create a cycle in mst
       total += e.getWeight();
       i++;
     }
   }
   return total;
 }

//function to check if edges make a Cycle
 public static boolean checkCycle(Edge e, int [] path) {
   int v1 = e.getVertex1();
   int v2 = e.getVertex2();

   while (path[v1] > 0) // if path in vertex 1 already has a path
     v1 = path[v1];

   while (path[v2] > 0) // if path in vertex 2 already has a path
     v2 = path[v2];

   if (v1 != v2) {
     path[v1] = v2; //if path is different make path of v1, v2
     return true;
   }
   return false; //if they are the same path
 }

 public static int kruskalUF(WeightedGraph G) {
     int i=0;
     int total =0;
     int vSize = G.vSize();
     int eSize = G.eSize();
    PriorityQueue<Edge> heap = new PriorityQueue<>(eSize, Collections.reverseOrder(new sortHeap())); //Queue with weight Priority
    //Loop to add all edges to the heap
    for (Edge e :G.getEdgesOneWay()) {
        heap.add(e);
    }

    // Union-Find structure
        UF uf = new UF(vSize+1);
        //loop to find mst, until the edges are vertex size -1
        while (i<vSize-1) {
            Edge e = heap.remove();
            int v = e.getVertex1();
            int w = e.getVertex2();
            if (!uf.connected(v, w)) { // v-w does not create a cycle
                uf.union(v, w);  // merge v and w components
                total += e.getWeight();
                i++;
            }
        }
        return total;
    }
}

//modifier to make heap remove the edge with the smallest weight
class sortHeap implements Comparator<Edge>{
    @Override
    public int compare (Edge a, Edge b){
        return Integer.compare( b.getWeight(), a.getWeight());
    }
}
