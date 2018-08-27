//Daniel Charua  A01017419    11/05/17

public class City{
    float xCrd, yCrd;
    int number;

    City(float x, float y, int n){
        xCrd= x;
        yCrd = y;
        number = n;
    }
    float getX(){
        return xCrd;
    }

    float getY(){
        return yCrd;
    }
    public float getCost(City city) {
        float x = Math.abs(getX() - city.getX());
        float y =  Math.abs(getY() - city.getY());
       return (float) Math.sqrt(Math.pow(x, 2) + Math.pow(y, 2));
   }

   public float getCosts(City city, City city2) {
      float x =  Math.abs(city.getX() - city2.getX());
      float y =  Math.abs(city.getY() - city2.getY());
      return (float) Math.sqrt(Math.pow(x, 2) + Math.pow(y, 2));
  }

   public String toString() {
       return "City " + number;
   }

}
