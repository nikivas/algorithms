a = [ [999, 10, 25, 25, 10],
      [1, 999, 10, 15, 2  ],
      [8, 9, 999, 20, 10  ],
      [14, 10, 24, 999, 15],
      [10, 8, 25, 27, 999 ] ]

min_sum = 0

for i in range(len(a)):
    min_el = min(a[i])
    for j in range(len(a[i])):
        a[i][j] -= min_el
    min_sum += min_el

for i in range(len(a[0])):
    min_el = 999
    for j in range(len(a)):
        min_el = min(min_el, a[j][i])
    if min_el == 0:
        continue
    for j in range(len(a)):
        a[j][i] -= min_el
    min_sum += min_el
        


for i in range(len(a)):
    for j in range(len(a[i])):
        print a[i][j],' ',
    print
print min_sum







