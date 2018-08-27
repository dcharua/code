//Daniel Charua A01017419            11/05/17

// El algoritmo de programación dinámica se construyó con la ayuda del codigo por Tushar Roy, recuperado de:
// https://github.com/mission-peace/interview/blob/master/src/com/interview/graph/TravelingSalesmanHeldKarp.java

import java.util.*;
import java.io.*;

class Travel {
    private static ArrayList<City> bestRoute;
    private static float cost = Float.MAX_VALUE;
    private static int size;

    public static void TSPFB(ArrayList<City> city) {
        ArrayList<City> route = new ArrayList<City>();
        bruteForceFindBestRoute(route, city);
        System.out.println(bestRoute);
        System.out.println("Cost = "+ cost);
    }

    public static void bruteForceFindBestRoute (ArrayList<City> r, ArrayList<City> citiesNotInRoute){
        if(!citiesNotInRoute.isEmpty()){
            for(int i = 0; i<citiesNotInRoute.size(); i++){
                City justRemoved = (City) citiesNotInRoute.remove(0);
                ArrayList<City> newRoute =(ArrayList<City>) r.clone();
                newRoute.add(justRemoved);

                bruteForceFindBestRoute(newRoute, citiesNotInRoute);
                citiesNotInRoute.add(justRemoved);
            }
        }
        if(citiesNotInRoute.isEmpty() && isBestRoute(r))
            bestRoute = r;
    }

    private static boolean isBestRoute(ArrayList<City> r) {
        float costemp=0;
        City first = r.get(0);
        for(int i = 0; i<r.size(); i++){
            if(i!=r.size()-1)
                costemp += r.get(i).getCost( r.get(i+1));
            else
                costemp += r.get(i).getCost( first);
    }
    if (cost > costemp){
        cost = costemp;
        return true;
    }
        else return false;
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
           while ((sCurrentLine = br.readLine()) != null){
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

   public static float TSPDP(ArrayList<City> city) {
       Map<String, Float> minCostDP = new HashMap<String, Float>();
       Map<String, Integer> parent = new HashMap<String, Integer>();
       List<Set<Integer>> allSets = powerSet(size);

           for(Set<Integer> set : allSets){
               for(int cityNo = 1; cityNo < size; cityNo++) {
                  if(set.contains(cityNo)) {
                      continue;
                  }
                  String key = generateKey(set, cityNo);
                  float minCost = Float.MAX_VALUE;
                  int minPrevVertex = 0;
                  Set<Integer> copySet = new HashSet<>(set);
                  for(int prevCity : set) {
                      float cost =  city.get(prevCity).getCost(city.get(cityNo)) + getCost(copySet, prevCity , minCostDP);
                      if(cost < minCost) {
                          minCost = cost;
                          minPrevVertex = prevCity;
                      }
                  }
                  if(set.size() == 0) {
                      minCost = city.get(0).getCost(city.get(cityNo));
                  }
                  minCostDP.put(key, minCost);
                  parent.put(key, minPrevVertex);
              }
          }
            Set<Integer> set = new HashSet<>();
            for(int i=1; i < size; i++) {
                set.add(i);
            }
            float finalCost = Float.MAX_VALUE;
            int prevCity = -1;
            Set<Integer> copySet = new HashSet<>(set);
            for(int k : set) {
                float cost = city.get(k).getCost(city.get(0)) + getCost(copySet, k, minCostDP);
                if(cost < finalCost) {
                    finalCost = cost;
                    prevCity  = k;
                }
            }
            String key = generateKey(set, 0);
            parent.put(key, prevCity);
            printCities(parent, city);
            return finalCost;
   }

   public static List<Set<Integer>> powerSet(int n){
   Set<Integer> set = new HashSet<>();
   for(int i=1; i < n; i++)
       set.add(i);
   return powerSet(set);
   }

   public static List<Set<Integer>> powerSet(Set<Integer> originalSet) {
    List<Set<Integer>> sets = new ArrayList<>();
    if (originalSet.isEmpty()) {
        sets.add(new HashSet<Integer>());
        return sets;
    }
    List<Integer> list = new ArrayList<Integer>(originalSet);
    Integer head = list.get(0);
    Set<Integer> rest = new HashSet<Integer>(list.subList(1, list.size()));
    for (Set<Integer> set : powerSet(rest)) {
        Set<Integer> newSet = new HashSet<Integer>();
        newSet.add(head);
        newSet.addAll(set);
        sets.add(newSet);
        sets.add(set);
    }
    Collections.sort(sets, new SetSizeComparator());
    return sets;
    }

    private static class SetSizeComparator implements Comparator<Set<Integer>>{
    @Override
    public int compare(Set<Integer> o1, Set<Integer> o2) {
        return o1.size() - o2.size();
    }
 }

  public static String generateKey(Set<Integer> set,float n) {
       int[] unsorted = new int[set.size()];
       int i=0;
       for(Integer element:set) {
           unsorted[i++] = element;
       }
       Arrays.sort(unsorted);
       StringBuilder sb = new StringBuilder();
       for(int element:unsorted)
           sb.append(element);
       return sb.toString() + n;
   }

  private static  float getCost(Set<Integer> set, int prevVertex, Map<String, Float> minCostDP) {
      set.remove(prevVertex);
      float cost = minCostDP.get(generateKey(set, prevVertex));
      set.add(prevVertex);
      return cost;
  }

  private static void printCities(Map<String, Integer> parent, ArrayList<City> city) {
       ArrayList<City> bestRoute = new ArrayList<City>();
       Set<Integer> set = new HashSet<>();
       for(int i=0; i < size; i++) {
           set.add(i);
       }
       Integer cityNo = 0;
       while(true) {
           set.remove(cityNo);
           cityNo = parent.get(generateKey(set, cityNo));
           if(cityNo == null) {
               break;
           }
           bestRoute.add(city.get(cityNo));
       }
       System.out.println(bestRoute);
   }
}
