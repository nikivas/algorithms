def mergeSort(array, left, right):
    if (left < right):
        q = int((right-left)/2)
        mergeSort(array,left,q)
        mergeSort(array,q+1,right)
        merge(array,left, q , right)

def merge(array, lb, mid , rb ):
    c = []    
    p1 = lb
    p2 = mid
    while( p1 != mid and p2 != rb):
        if(array[p1] > array[p2]):
            c.append(array[p1])
            p1+=1
        else:
            c.append(array[p2])
            p2+=1
    if(p1 != mid):
        while (p1 != mid):
            c.append(array[p1])
            p1+=1
    elif(p2 != rb):
        while (p2 != rb):
            c.append(array[p2])
            p2+=1
    for i in range(lb, rb):
        array[i] = c[i-lb]
            


    
Massiv = [8,18,27,5,1,2,4,8,0,55,12,42,62,22,31,73,47]
print '  '.join(map(str,mergeSort(Massiv, 0, len(Massiv)-1)))
