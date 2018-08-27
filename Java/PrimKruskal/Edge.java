//Daniel Charua  A01017419    09/04/17

public class Edge{
    int from, to, weight;

    Edge(int f, int t, int w){
        from = f;
        to = t;
        weight = w;
    }
    int getVertex1(){
        return from;
    }

    int getVertex2(){
        return to;
    }
    int getWeight(){
        return weight;
    }
}
