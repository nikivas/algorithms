n = raw_input()
dc, dcc = bin(int(n))[2:], ''
for  i in dc:
    if i =='0':
        dcc+='1'
    else:
        dcc+= '0'
print   int(n) > 0 and (str(bin(int(n)))[2:]).rjust(8,'0') or (bin( int(dcc,2)+1 )[2:]).rjust(8,'0')
