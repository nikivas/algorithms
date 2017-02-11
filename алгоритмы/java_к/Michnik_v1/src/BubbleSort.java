
public class BubbleSort {

	public BubbleSort() {
		    
	}

	public static void sort (int[] arr)
	{
		for(int i = arr.length-1 ; i > 0 ; i--){
	        for(int j = 0 ; j < i ; j++){
	            /*Сравниваем элементы попарно, 
	              если они имеют неправильный порядок, 
	              то меняем местами*/
	            if( arr[j] > arr[j+1] ){
	                int tmp = arr[j];
	                arr[j] = arr[j+1];
	                arr[j+1] = tmp;
	            }
	        }
	    }
	}
	
	
	public static void main(String[] args) {
		int arr[] = {5,7,6,4,9,1,23,0,44};
		for (int v : arr)
		    System.out.print(v + " ");
		sort(arr);
		System.out.println();
		for (int v : arr)
		    System.out.print(v + " ");

	}

}
