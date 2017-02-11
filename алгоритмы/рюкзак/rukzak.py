def knapSack(W, wt, val, n):
    Ans = 0
    str_Ans = ''
    dn_max = 2**(len(wt))
    for i in range(dn_max):
        #print i, ' - ',
        dn = str(bin(i))[2:].rjust(len(wt),'0') # 5 => 000101 ... e.t.c.
        print dn
        summ = 0
        buf_ans = 0
        for j in range(len(dn)):
            if (dn[j] == '1'):
                if (summ + wt[j] > W):
                    break
                summ+=wt[j]
                buf_ans += val[j]
        if(buf_ans > Ans):
            Ans = buf_ans
            str_Ans = dn
    print 'Max price  - when we take:'
    for i in range(len(str_Ans)):
        if( str_Ans[i] == '1'):
            print 'Item number: ',(i+1)
    print 'total sum is: ', Ans



val = [1,6,4,7,6]
wt = [3,4,5,8,9]
W = 13
n = 5
print(knapSack(W, wt, val, n))

