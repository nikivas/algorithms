
public class InsertionSort {

	public InsertionSort() {
		
	}
	
	public static void sort (int[] a)
	{
		for (int i = 0; i < a.length; i++)
        {
          int temp = a[i];// запомним i-ый элемент
          int j =i-1;//будем идти начиная с i-1 элемента 
          while(j >= 0 && a[j] > temp)
          // пока не достигли начала массива 
          // или не нашли элемент больше i-1-го
          // который храниться в переменной temp
          {
            a[j + 1] = a[j];
            //проталкиваем элемент вверх
            j--;
          }
          a[j + 1] = temp;
          // возвращаем i-1 элемент 
        }    
	}

	public static void main(String[] args) {
		
		int a[] = {5,8,22,45,7,6,4,9,1,23,0,44};
		for (int v : a)
		    System.out.print(v + " ");
		sort(a);
		System.out.println();
		for (int v : a)
		    System.out.print(v + " ");
	}

}
