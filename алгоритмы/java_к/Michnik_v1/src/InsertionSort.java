
public class InsertionSort {

	public InsertionSort() {
		
	}
	
	public static void sort (int[] a)
	{
		for (int i = 0; i < a.length; i++)
        {
          int temp = a[i];// �������� i-�� �������
          int j =i-1;//����� ���� ������� � i-1 �������� 
          while(j >= 0 && a[j] > temp)
          // ���� �� �������� ������ ������� 
          // ��� �� ����� ������� ������ i-1-��
          // ������� ��������� � ���������� temp
          {
            a[j + 1] = a[j];
            //������������ ������� �����
            j--;
          }
          a[j + 1] = temp;
          // ���������� i-1 ������� 
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
