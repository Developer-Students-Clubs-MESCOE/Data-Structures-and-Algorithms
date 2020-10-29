import java.lang.reflect.Array;
import java.util.Arrays;

public class InsertionSort {

    static void insertionSort(int[] array) {
        for(int i=0; i< array.length; i++) {
            int tmp = array[i];
            int j = i;
            while(j>0 && array[j-1] > tmp) {
                array[j] = array[j-1];
                j--;
            }
            array[j] = tmp;
        }
    }

    public static void main(String args[]) {
        int[] array = new int[] {72,45,9,4,0,65,7,99,1};
        System.out.println("Original list: " + Arrays.toString(array));
        insertionSort(array);
        System.out.println("Sorted list: " + Arrays.toString(array));
    }

}

