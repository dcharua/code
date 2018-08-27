//Daniel Charua  A01017419    09/04/17

/** @author: Tim Wahls
    @version: 9/14/2012
    purpose: implement a weighted undirected graph using the adjacency
             list representation */


//users.dickinson.edu/~wahlst/332/hw4files/WeightedGraph.java

import java.io.*;
import java.util.*;

public class WeightedGraph {

  public static int eSize, vSize;
  public static final int DefaultSize = 100;
  private List<Edge>[] edges;      // edges of the graph
  public static Edge [] eOneWay;

  /** post: intialize graph of default size (number of vertices) */
  public WeightedGraph() {
    this(DefaultSize);
  }

  /** post: intialize graph of indicated size
            display error message if size is invalid */
  public WeightedGraph(int size) {
    if (size > 0) {
      edges = new ArrayList [size];
      for (int i = 0; i < size; i++) {
        edges[i] = new ArrayList<Edge>();
      }
    } else {
      System.out.println("Error: invalid number of verticies.");
    }
  }

//Inicio de las funciones agregadas
    //get edges back and forth
  public Edge []  getAllEdges(){
      Iterator<Edge> iter;
      Edge [] e = new Edge[eSize*2];
      int k =0;
      for (int i = 0; i < edges.length; i++) {
        iter = getIncidentEdges(i);
        while (iter.hasNext()) {
          e[k] = iter.next();
          k++;
        }
      }
      return e;
  }

  //get edges
   public Edge []  getEdgesOneWay(){
       return eOneWay;
   }

   //get numbern of edges
   public int eSize(){
      return eSize;
   }

 //get number of verticies
   public int vSize(){
      return vSize;
   }

   //get neighbors return an array of edges
   public int[] getNeighbor(int v){
       int i=0;
       int [] neighbors = new int[edges[v].size()];
       Iterator<Edge> it = getIncidentEdges(v);
       while (it.hasNext()) {
         Edge e = it.next();
         neighbors[i] = e.getVertex2();
         i++;
       }
       return neighbors;
   }

   //get neighbors return a queue of edges
   public PriorityQueue<Edge> getNeighborHeap(int v){
       PriorityQueue<Edge> heap = new PriorityQueue<>(10, Collections.reverseOrder(new sortHeap()));
       Iterator<Edge> it = getIncidentEdges(v);
       while (it.hasNext()) {
         Edge e = it.next();
         heap.add(e);
       }
       return heap;
   }

   //read file
  public static WeightedGraph readGraph(String file) throws IOException{
     int from, to, weight;
     int i=0;
     String currentLine;
     BufferedReader br = new BufferedReader(new FileReader(file));
         String sCurrentLine;
         sCurrentLine = br.readLine();
         String[] line = sCurrentLine.split(" ");
         vSize = Integer.parseInt(line[0]);
         eSize = Integer.parseInt(line[1]);
         WeightedGraph graph = new WeightedGraph(eSize);
          eOneWay = new Edge[eSize];
         while ((sCurrentLine = br.readLine()) != null) {
         // trim newline when comparing with lineToRemove
         line = sCurrentLine.split(" ");
                     from = Integer.parseInt(line[0]);
                     to = Integer.parseInt(line[1]);
                     weight = Integer.parseInt(line[2]);
                     graph.addEdge(from, to, weight);
                     Edge e= new Edge(from, to, weight);
                     eOneWay[i] = e;
                     i++;
             }
         br.close();
     return graph;
 }
 //Fin de las funciones agregadas

  /** post: add edge from vertex #v1 to #v2 with the specified weight
            if both vertex numbers are valid */
  public void addEdge(int v1, int v2, int weight) {
    if (v1 == v2) {
      System.out.println("Error: self loops not allowed.");
    } else if (v1 < 0 || v2 < 0 || v1 >= edges.length || v2 >= edges.length) {
      System.out.println("Error: invalid vertex.");
    } else if (hasEdge(v1, v2)) {
      System.out.println("Error: edge already exists.");
    } else {
      edges[v1].add(new Edge(v1, v2, weight));
      edges[v2].add(new Edge(v2, v1, weight));
    }
  }


  /**  @return true iff v1 and v2 are valid and adjacent  */
  public boolean hasEdge(int v1, int v2) {
    if(getWeight(v1, v2) != 0 )
    return true;
    else return false;
  }

  public boolean hasVertix(int v){
      Iterator<Edge> it = getIncidentEdges(v);
      if (it.hasNext())
        return true;
    else return false;
  }

  /** @return the weight of the edge from v1 to v2, or infinity if
              no such edge exists */
  public int getWeight(int v1, int v2) {
    if (v1 < 0 || v2 < 0 || v1 >= edges.length || v2 >= edges.length) {
      return 0;
    } else {
      Iterator<Edge> it = getIncidentEdges(v1);
      while (it.hasNext()) {
        Edge e = it.next();
        if (e.getVertex2() == v2) {
          return e.getWeight();
        }
      }
      return 0;
    }
  }

  /** @return an iterator over all edges incident on vertex # vNum */
  public Iterator<Edge> getIncidentEdges(int vNum) {
    if (vNum < 0 || vNum >= edges.length) return null;
    else return edges[vNum].iterator();
  }

  /** @return all information about the graph (edges and weights) in
              a human readable form */
  public String toString() {
    String res = "Edges:\n";
    Iterator<Edge> iter;
    Edge e;
    boolean first;
    for (int i = 0; i < edges.length; i++) {
      res += "  from " + i + " to: [";
      iter = getIncidentEdges(i);
      first = true;
      while (iter.hasNext()) {
        e = iter.next();
        if (first) first = false;
        else {
          res += ", ";
        }
        res += e.getVertex2() + " weight: " + e.getWeight();
      }
      res += "]\n";
    }
    return res;
  }
}
