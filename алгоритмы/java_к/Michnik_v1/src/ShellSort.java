
public class ShellSort {

	public ShellSort() {
		
	}
	public static void sort (int[] a)
	{
		int step = a.length / 2;//инициализируем шаг.
		while (step > 0)//пока шаг не 0
		{
			for (int i = 0; i < (a.length - step); i++)
            {
				int j = i;
                    //будем идти начиная с i-го элемента
                	while (j >= 0 && a[j] > a[j + step])
                    //пока не пришли к началу массива
                    //и пока рассматриваемый элемент больше
                    //чем элемент находящийся на расстоянии шага
                    {
                        //меняем их местами
                        int temp = a[j];
                        a[j] = a[j + step];
                        a[j + step] = temp;
                        j--; 
                    }
             }
                step = step / 2;//уменьшаем шаг
       }  
	}
	public static void main(String[] args) {
		int a[] = {5,8,22,45,7,6,4,9,1,23,0,44,28};
		for (int v : a)
		    System.out.print(v + " ");
		sort(a);
		System.out.println();
		for (int v : a)
		    System.out.print(v + " ");

	}

}
