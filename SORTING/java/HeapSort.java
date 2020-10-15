/*
*  @author Laukik Chavan
*
* Use Java-14 To run 😎
* This is Generic Heap Sort Program demostrate -
*   Integer Heap Sort
*   Character Heap Sort
*   Double Heap Sort
*   String Heap Sort
* */

// Heap Sort Class using T data type as place holder and extends Comparable Class to compare two generic class
public class HeapSort<T extends Comparable<T>> {

    private T data[];
    private int length;

    HeapSort(T data[]) {
        this.data = data;
        this.length = this.data.length;
    }

    public T[] buildMaxHeap(T[] tempData) {
        for(int i = (int) Math.floor(length/2); i >= 0 ; i--) {
            tempData = heapify(tempData, i);
        }
        return tempData;
    }

    public T[] heapify(T[] tempData, int node) {
        int leftNode = node*2+1;
        int rightNode = node*2+2;

        int maxNode = node;

        if(leftNode < length) {
            if(tempData[leftNode].compareTo(tempData[maxNode]) > 0){
                maxNode = leftNode;
            }
        }

        if(rightNode < length) {
            if((tempData[rightNode].compareTo(tempData[maxNode])) > 0) {
                maxNode = rightNode;
            }
        }

        if(maxNode != node) {
            T temp = tempData[node];
            tempData[node] = tempData[maxNode];
            tempData[maxNode] = temp;
            tempData = heapify(tempData, maxNode);
        }
        return tempData;
    }

    public void sort(){
        this.data = buildMaxHeap(this.data);
        while(length > 0) {
            this.length--;

            T temp = this.data[0];
            this.data[0] = this.data[length];
            this.data[length] = temp;

            this.data = heapify(this.data, 0);
        }
    }

    public void printData() {
        for(T i : this.data) {
            System.out.print(i + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        /* Sorting Integer Data using Heap Sort */
//        Integer[] dataToBeSorted = {2, 8, 5, 3, 9, 1};
//        HeapSort heapSort = new HeapSort<Integer>(dataToBeSorted);

        /* Sorting Double Data using Heap Sort */
//        Double[] dataToBeSorted = {1.2, 4.3, 6.7, 7.1, 3.9};
//        HeapSort heapSort = new HeapSort<Double>(dataToBeSorted);

        /* Sorting Character Data using Heap Sort */
//        Character[] dataToBeSorted = {'b', 'a', 'z', 'v', 'T'};
//        HeapSort heapSort = new HeapSort<Character>(dataToBeSorted);

        /* Sorting String Data using Heap Sort */
        String[] dataToBeSorted = {"laukik", "varun", "karan", "prem", "pratik", "dhruvil", "gaurav", "kaif", "sakashi", "tanya"};
        HeapSort heapSort = new HeapSort<String>(dataToBeSorted);

        System.out.println("Given Data - ");
        heapSort.printData();

        heapSort.sort();

        System.out.println("Sorted Data - ");
        heapSort.printData();
    }
}
