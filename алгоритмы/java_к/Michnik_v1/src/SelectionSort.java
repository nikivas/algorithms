
public class SelectionSort {

	public SelectionSort() {
		
	}

	public static void sort (int[] arr) {
		 for (int min=0;min<arr.length-1;min++) {
		 	int least = min;
		 	for (int j=min+1;j<arr.length;j++) {
		 	    if(arr[j] < arr[least]) {
		 			least = j;
		 		}
		 	}
		 	int tmp = arr[min];
			arr[min] = arr[least];
			arr[least] = tmp;
		 }
	}
	
	public static void main (String[] args) {
		int arr[] = {5,7,6,4,9,1,23,0};
		for (int v : arr)
		    System.out.print(v + " ");
		sort(arr);
		System.out.println();
		for (int v : arr)
		    System.out.print(v + " ");
	
	}
	
}
