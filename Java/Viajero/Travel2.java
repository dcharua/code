//Daniel Charua A01017419 11/05/17

// La clase Travel2 fue obtenida casi en su totalidad del código de Adita Nugroho, recuperado de:
// 	https://github.com/evandrix/SPOJ/blob/master/DP_Main112/Solving-Traveling-Salesman-Problem-by-Dynamic-Programming-Approach-in-Java.pdf

import java.util.*;
import java.io.*;

class Travel2 {
    private static float cost = Float.MAX_VALUE;
    private static int size;
    private static int sizePow;
    private static ArrayList<Integer> outputArray = new ArrayList<Integer>();
    private static float g[][], d[][];
    private static int p[][];

    public static void main(String[] args) throws IOException{
        ArrayList<City> city = new ArrayList<City>();
        city = readCities("P4tsp25.txt");
        System.out.println("TSP 25: ");
        long lStartTime = System.currentTimeMillis();
        float p = computeTSP(city);
        long lEndTime = System.currentTimeMillis();
        long output = lEndTime - lStartTime;
        System.out.println("Elapsed time in minutes: " + output/60000);
        System.out.println("");


    }

    public static ArrayList<City> readCities(String file) throws IOException{
        ArrayList<City> cities = new ArrayList<City>();
       float x, y;
       int i=0;
       String sCurrentLine;
       String[] line;
       BufferedReader br = new BufferedReader(new FileReader(file));
           sCurrentLine = br.readLine();
           size =  Integer.parseInt(sCurrentLine);
           while ((sCurrentLine = br.readLine()) != null) {
           // trim newline when comparing with lineToRemove
           line = sCurrentLine.split(" ");
                       x= Float.parseFloat(line[0]);
                       y = Float.parseFloat(line[1]);
                       City c= new City(x, y, i);
                       cities.add(c);
                       i++;
               }
           br.close();
           return cities;
   }

   public static float computeTSP(ArrayList<City> ciudades){
       sizePow = (int) Math.pow(2,size);
       g = new float[size][sizePow];
       p = new int[size][sizePow];
       float  [][]inputMatrix = createMatrix(size, ciudades);
       d= inputMatrix;
       int i, j, k, l, m,s;

       for (i =0; i<size; i++){
           for(j=0; j<sizePow; j++){
               g[i][j] = -1.0f;
               p[i][j] = -1;
           }
       }
       for(i=0; i<size; i++){
           g[i][0] =inputMatrix[i][0];
       }
       float cost = tsp(0, sizePow -2);
       outputArray.add(0);
       pPath(0, sizePow-2);
        System.out.println(outputArray);
       System.out.println(cost);
       return cost;
   }
   private static float tsp(int start, int set){
       int masked, mask;
       float result = -1.0f;
       float temp;
       if(g[start][set] != -1.0){
           return g[start][set];
       }else{
           for(int x =0; x<size; x++){
               mask= sizePow-1-(int)Math.pow(2,x);
               masked = set & mask;
               if(masked !=set){
                   temp = d[start][x] + tsp(x, masked);
                   if(result ==-1 || result>temp){
                       result = temp;
                       p[start][set] = x;
                   }
               }
           }
           g[start][set] = result;
           return result;
       }
   }

   private static void pPath(int start, int set){
       if(p[start][set] ==-1){
           return;
       }
       int x = p[start][set];
       int mask = sizePow -1 -(int) Math.pow(2, x);
       int masked = set & mask;

       outputArray.add(x);
       pPath(x, masked);
   }

   public static float[][] createMatrix(int size, ArrayList<City> ciudades){
       float g[][] = new float[size][size];
       for(int i=0; i<size; i++){
           for(int j=0; j<size; j++){
               g[i][j]= ciudades.get(i).getCost(ciudades.get(j));
           }
       }
       return g;
   }
}
