def bsort(array):
    for i  in xrange(len(array)):
        for j in xrange(len(array)-i-1):
            if array[j] > array[j+1]:
                array[j], array[j+1] = array[j+1], array[j]
    return array

Massiv = [8,18,27,5,1,2,4,8,0,55,12,42,62,22,31,73,47]
print '  '.join(map(str,bsort(Massiv)))
