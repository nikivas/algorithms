def SSort(array):
    for i in xrange(len(array)-1):
        j = i+1
        while j > 0 and array[j] < array[j-1]:
            array[j],array[j-1] = array[j-1],array[j]
            j-=1

    return array


    
Massiv = [8,18,27,5,1,2,4,8,0,55,12,42,62,22,31,73,47]
print '  '.join(map(str,SSort(Massiv)))
