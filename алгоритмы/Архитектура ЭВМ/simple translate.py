number = int(raw_input())
additional_code = bin(number)[2:]
additional_code2 = ''
second_additional_code = bin(int((-1*number-1)))[2:]

for  i in second_additional_code:
    if i =='0':
        additional_code2 = additional_code2 +'1'
    elif i == '1':
        additional_code2 = additional_code2 +'0'

if ( number > 0):
    print (bin(number)[2:len(bin(number))]).rjust(8,'0')
elif(number == 0):
    print '0'
else:
    print additional_code2.rjust(8,'1')
           
