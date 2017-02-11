def chooseSort(array):
    m = 0
    for i in xrange(len(array)):
        m = i
        for j in xrange(i,len(array)):
            if array[j] < array[m]:
                m = j
        array[m], array[i] = array[i],array[m]
    return array
    
Massiv = [8,18,27,5,1,2,4,8,0,55,12,42,62,22,31,73,47]
print '  '.join(map(str,chooseSort(Massiv)))
