n = str(float(raw_input('vvedi desyati4noe 4islo: ') ))
tk = int(str(n).find('.'))
exp = 0
ZNAK = '0'
if(n[0] == '-'):
    ZNAK = '1'

mantissa = str(bin(int(n[0:tk])))[2:]

other = n[tk+1:]
L = len(other)
ost = ''
other = int(other)
RANGE = 100
while(True):
    f = 0
    if(RANGE <= 0):
        break
    if(other == 0):
        break
    other = other*2
    if(len(str(other)) > L):
        f = 1
        other = int(str(other)[1:])
    ost += str(f)
    RANGE -= 1

IS_IT_NULL = 0
if(mantissa != '0'):
    exp += len(mantissa)-1
else:
    if(ost.find('1') == -1):
        IS_IT_NULL = 1
    exp -= (ost.find('1')+ 1)
    
mantissa = mantissa[1:]
MANTISA = mantissa+ost
for i in [[127, 23], [1023,52], [16383, 64]] :
    print ZNAK+'    ', str(bin(int(exp)+i[0]))[2:] ,'   ',(MANTISA[:i[1]]).ljust(i[1],'0')
#print str(bin(exp))

n=raw_input('vvedi dvoi4noe 4islo (len = 32|64 |80 ) : ')
FLAG = 1
size = len(n)

ZNAK = 1
if(n[0] =='1'):
    ZNAK = -1

exp = 0
if(size == 32):
    exp = int(n[1:9],2)-127 #10
    man = n[9:]    #2

elif(size == 64):
    exp = int(n[1:12],2)-1023
    man = n[12:]


elif(size == 80):
    exp = int(n[1:16],2)-16383
    man = n[16:]

else:
    print 'NE PO NORME VVEL TI 4iselku'
    FLAG = 0
if FLAG ==1 :
    ansM = ''
    ma1 = '1'.rjust(100,'0')
    ma2 = man
    if (exp < 0):
        ans = '0.' + ansM
        #print '-'
        ansM += '0'*((-1*exp)+1) + ma2
    elif exp > 0:
        #print '+'
        ansM = '1'+ma2[:exp]+'.'+ma2[exp:]
    else:
        ansM = '1.'+ma2
    f = 0
    count = 0.0
    idx_f = ansM.find('.')
    for i in range(len(ansM)-idx_f-1):
        count += int(ansM[i+1+idx_f]) * (2**(-i-1))
    Lcount = float(int(ansM[:idx_f],2))

    print ZNAK*(Lcount + count)



    

