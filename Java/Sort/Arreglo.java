//Daniel Charua    A01017419

import java.util.Scanner;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.FileReader;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;


public class Arreglo{
    public int[] data;
    public int size;

    // Lee los data de una archivo cuyo nombre recibe como parámetro
    void lecturaDatos(String file){
        int i=0;
        boolean first = true;
        try (BufferedReader br = new BufferedReader(new FileReader(file))) {
    			String sCurrentLine;
    			while ((sCurrentLine = br.readLine()) != null) {
                    //Si es el primer elemento del arichivo (tamaño del arreglo)
                    if(first){
                        //Guardar tamaño en size y crear arreglo de ese tamaño
                        size = Integer.parseInt(sCurrentLine);
                        data = new int[size];
                        first = false;
                    }
                    else{
                        //guarda los elementos en el nuevo arreglo
                        data[i] =Integer.parseInt(sCurrentLine);
                        i++;
                    }
    			}
    		} catch (IOException e) { // Caso Error
    			e.printStackTrace();
    	}
    }

    void escribeDatos(String archivo, int num, int modo) throws FileNotFoundException, IOException {
      BufferedWriter bw = null;
      try {
             //Specify the file name and path here
       File file = new File(archivo);

       /* This logic will make sure that the file
        * gets created if it is not present at the
        * specified location*/
        if (!file.exists()) {
           file.createNewFile();
        }

        FileWriter fw = new FileWriter(file);
        bw = new BufferedWriter(fw);

        bw.write(num + "\n");

        int numero;
        if (modo == 1){
            for (int i=0; i<num; i++) {
             bw.write(i + "\n");
         }
     }
     else if (modo == 2){
         for (int i=0; i<num; i++) {
          bw.write(num-i + "\n");
        }
    }
    else if (modo == 3){
        for (int i=0; i<num; i++) {
        numero = (int) (Math.random() * num*2) + 1;
          bw.write(numero + "\n");
       }
    }
          //System.out.println("File written Successfully");

          } catch (IOException ioe) {
         ioe.printStackTrace();
      }
      finally
      {
         try{
            if(bw!=null)
         bw.close();
         }catch(Exception ex){
             System.out.println("Error in closing the BufferedWriter"+ex);
          }
      }

    }

    void bubbleSort(){
        System.out.println("bubbleSort");
         for(int i=0; i < size; i++){
                 for(int j=1; j < (size-i); j++){
                          if(data[j-1] > data[j]){
                                 swap(j, j-1);
                         }
                 }
         }
    }

    void selectionSort(){
        System.out.println("selectionSort");
        for (int i = 0; i < size - 1; i++)
       {
           int index = i;
           for (int j = i + 1; j < size; j++){
               if (data[j] < data[index]){
                   index = j;//searching for lowest index
               }
           }
           int smallerNumber = data[index];
           data[index] = data[i];
           data[i] = smallerNumber;
       }
    }

    void insertionSort(){
        System.out.println("insertionSort");
       for (int j = 1; j < size; j++) {
           int key = data[j];
           int i = j-1;
           while ( (i > -1) && ( data [i] > key ) ) {
               data [i+1] = data[i];
               i--;
           }
           data[i+1] = key;
       }
    }

    void quickSort(){
        System.out.println("quickSort");
        quickSort(0, size-1);
    }
    private void quickSort(int lowerIndex, int higherIndex) {

        int i = lowerIndex;
        int j = higherIndex;
        // calculate pivot number, I am taking pivot as middle index number
        int pivot = data[lowerIndex+(higherIndex-lowerIndex)/2];
        // Divide into two arrays
        while (i <= j) {
            /**
             * In each iteration, we will identify a number from left side which
             * is greater then the pivot value, and also we will identify a number
             * from right side which is less then the pivot value. Once the search
             * is done, then we exchange both numbers.
             */
            while (data[i] < pivot) {
                i++;
            }
            while (data[j] > pivot) {
                j--;
            }
            if (i <= j) {
                swap(i, j);
                //move index to next position on both sides
                i++;
                j--;
            }
        }
        // call quickSort() method recursively
        if (lowerIndex < j)
            quickSort(lowerIndex, j);
        if (i < higherIndex)
            quickSort(i, higherIndex);
    }

    void mergeSort(){
        System.out.println("mergeSort");
        mergeSort(0, size);
    }
    private void mergeSort(int low, int high)
    {
        int N = high - low;
        if (N <= 1)
            return;
        int mid = low + N/2;
        // recursively sort
        mergeSort(low, mid);
        mergeSort(mid, high);
        // merge two sorted subarrays
        int[] temp = new int[N];
        int i = low, j = mid;
        for (int k = 0; k < N; k++)
        {
            if (i == mid)
                temp[k] = data[j++];
            else if (j == high)
                temp[k] = data[i++];
            else if (data[j]<data[i])
                temp[k] = data[j++];
            else
                temp[k] = data[i++];
        }
        for (int k = 0; k < N; k++)
            data[low + k] = temp[k];
    }

    // Ordena los elemento del arreglo de la clase usando el algoritmo Heap Sort.
    void heapSort(){
        System.out.println("heapSort");
        heapify();
       for (int i = size; i > 0; i--)
       {
           swap(0, i);
           size--;
           maxheap(0);
       }
    }

    private void heapify(){
        size= data.length -1;
        for (int i = size/2; i >= 0; i--)
            maxheap(i);
    }
    private void maxheap(int i){
        int left = 2*i ;
        int right = 2*i + 1;
        int max = i;
        if (left <= size && data[left] > data[i])
            max = left;
        if (right <= size && data[right] > data[max])
            max = right;

        if (max != i)
        {
            swap(i, max);
            maxheap(max);
        }
    }

    void radixSort(){
        System.out.println("radixSort");
        //Declaracion de variables y contruccion de los 10 arreglos dobles, un arreglo para cada digito (0-9) "categoria"
        int length = size ;
        int max = data[0];
        int e =1;
        List<Integer>[] digit = new ArrayList[10];
        for (int i = 0; i <10; i++) {
            digit[i] = new ArrayList<Integer>();
        }

        //Se busca el elemento mas grande
        for(int j=1; j<length; j++){
        if (data[j]>max)
            max = data[j];
        }
        //se encuentra el maximo y se obtiene la cantidad de digitos
        max= Integer.toString(max) .length();

        //primer loop, se realiza el numero de digitos que tiene el mayor
        while(max>0){
            //loop para acomodar los numeros en la "categoria" que pertenece, de acuerdo al digito significativo
            //Se divide el numero entre un exponete de la potencia de 10, empezando en 1 y se le saca mod 10 para obetener el digito
            for (Integer num : data) {
                digit[num/e % 10].add(num);
            }
            // Se aumenta el expoenete a la siguente poetencia de 10 y se declara el contador para el arreglo final
            e*=10;
            int a = 0;
            //loop para buscar en todas las "categorias"
            for (int i = 0; i < 10; i++) {
                //loop para acomodar los numeros de cada "categoria" en el arreglo final
                for (Integer num : digit[i]) {
                    data[a++] = num;
                }
                // se limpia la "categoria"
                digit[i].clear();
            }
            // se decrese el digito del max, si no es 0, se vuelve a hacer el loop con el siguiente digito
            max--;
        }
   }

   //Imprime el arreglo
    void imprimeArreglo(){
        System.out.println("-----------");
        for (int i=0; i<data.length; i++){
            System.out.println(data[i]);
        }
        System.out.println("-----------");
    }

    //Hace un swap dentro del arreglo
    private void swap(int a, int b){
        int tmp = data[a];
        data[a] = data[b];
        data[b] = tmp;
    }
}
