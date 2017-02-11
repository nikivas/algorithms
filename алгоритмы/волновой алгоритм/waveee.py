#~coding: utf-8~
def wave():
    

    N = randrange(5,20) # 
    M = randrange(5,20) #рандомно выбираем размерность массива

    #zapolnyaem labirint
    def inout(N,M):
        field = []
        field_side = []
        for i in range(N):
            for j in range(M):
                field_side.append(-1) # сначала все забиваем как -1
            field.append(field_side)
            field_side=[]
            
        quitt = len(field[0])*len(field)+1 # значение которое будет лежать в координате выхода (m*n+1)
        
        for i in range(1,N-1):
            for j in range(1,M-1):   # все кроме стенок = 0
                field[i][j]=0
                
        for i in range(1,N-1):       # рандомно забиваем карту
            for j in range(1,M-1):
                randrand = randrange(5,20)  # рандом в промежутке
                if randrand>=15:
                    field[i][j]=-1
                    
        randomside=randint(1,2)         # выбираем стороны на которых будет вход\выход (левая-правая) либо (верхняя - нижняя)
        
        for i in range(N):              
                    ii = randint(-1,0) # ii - это вход
                    iii = randint(-1,0) # iii - это выход
                    for j in range(M):
                            jj = randint(0,M-1) # это 
                            jjj = randint(0,M-1)
                            
        for i in range(N):
                    ii = randint(0,N-1)
                    iii = randint(0,N-1)
                    for j in range(M):
                           jj = randint(-1,0)
                           jjj = randint(-1,0)
                           
        field[ii][jj] = 1           #
        field[iii][jjj] = quitt     #непосредственно забиваем 1 во вход и quit в выход
        
        return field, field[iii][jjj] # возвращаем массив и число в координате выхода

        
    field,quitt=inout(N,M) # field - наш заполненный массив, quit - наше число в координате выхода

    z= 0
    z=1

    wave=1 # наша "волна"
    
    f1=0        # флаг на то что мы все еще где-то есть 0
    f2=0        # флаг на то нашли ли мы выход
    idx,idy = 0,0
    
    while z==1:                                                 # непосредственно наша "волна" - О(n**3)
        f = 0
        for i in range(0,N):                                    # проходимся по строкам
            for j in range(0,M):                                # проходимся по столбцам
                    if field[i][j]==wave:               # ЕСЛИ НАШЛИ ЭЛЕМЕНТ СОДЕРЖАЩИЙ ВОЛНУ
                                                        # проходимся по всем близлежащим клеткам и:
                        if(i>0 and j>0):                       # первые условия чтобы не выйти за границу массива (лево-верх)
                            if field[i-1][j-1]==0:              # если нашли клетку куда можно пойти и где мы еще не были - ходим
                                field[i-1][j-1]=wave+1
                                f=1
                            elif field[i-1][j-1]==quitt:        # если нашли выход, то записываем в idx и idy его координаты а в сам выход текущую волну, взводим флаг что выход есть 
                                field[i-1][j-1]=wave+1
                                f2=1
                                idx = i-1
                                idy = j-1
                        if(i>0):                                # далее все то же самое поэтому оставлю только направление сдвига относительно нашей клетки (верх)
                            if field[i-1][j]==0:
                                field[i-1][j]=wave+1
                                f=1
                            elif field[i-1][j]==quitt:
                                field[i-1][j]=wave+1
                                f2=1
                                idx = i-1
                                idy = j
                        if (i>0 and j<M-1):
                            if field[i-1][j+1]==0:              # (верх-право)
                                field[i-1][j+1]=wave+1
                                f=1
                            elif field[i-1][j+1]==quitt:
                                field[i-1][j+1]=wave+1
                                f2=1
                                idx = i-1
                                idy = j+1

                                
                        if (i<N-1 and j>0):
                            if field[i+1][j-1]==0:              # (низ-лево)
                                field[i+1][j-1]=wave+1
                                f=1
                            elif field[i+1][j-1] == quitt:
                                field[i+1][j-1]=wave+1
                                f2=1
                                idx = i+1
                                idy = j-1
                        if (i<N-1):
                            if field[i+1][j]==0:                # (низ)
                                field[i+1][j]=wave+1
                                f=1
                            elif field[i+1][j]==quitt:
                                field[i+1][j]=wave+1
                                f2=1
                                idx = i+1
                                idy = j
                        if (i<N-1 and j<M-1):
                            if field[i+1][j+1]==0:                # (низ-право)
                                field[i+1][j+1]=wave+1
                                f=1
                            elif field[i+1][j+1]==quitt:
                                field[i+1][j+1]=wave+1
                                f2=1
                                idx = i+1
                                idy = j+1

                                
                        if (j>0):
                            if field[i][j-1]==0:                 # (лево)
                                field[i][j-1]=wave+1
                                f=1
                            elif field[i][j-1]==quitt:
                                field[i][j-1]=wave+1
                                f2=1
                                idx = i
                                idy = j-1
                        
                        if (j<M-1):
                            if field[i][j+1]==0:                 # (право)
                                field[i][j+1]=wave+1
                                f=1
                            elif field[i][j+1]==quitt:
                                field[i][j+1]=wave+1
                                f2=1
                                idx = i
                                idy = j+1
                            
        wave +=1

        
        
        if f2:      # если выход найден, то выходим
            break
        
        if f==0:    # если все клетки с 0 закончились то выходим
            break
                    

    
    Ans = [ [],  []  ]                  # тут мы будем хранить координаты выхода
    Ans[0].append(idx)                  #
    Ans[1].append(idy)                  #забиваем найденые в волновом алгоритме координаты выхода

    while wave > 0:                                 # берем наши координаты и ищем ближайшую точку со значением wave-1
        flagg = 1
        if idx >0 and idy>0 and flagg:              # вот это чтобы не вылезти за границы массива (лево-верх)
            if field[idx-1][idy-1]==wave -1:        # если нашли , то уменьшаем волну (wave--;), "переходим" в нее, делаем idx и idy равными ее координатам, и уже относительно нее будем искать wave -1
                Ans[0].append(idx-1)
                Ans[1].append(idy-1)
                idx -= 1
                idy -= 1
                flagg = 0
        if idx > 0 and flagg:
            if field[idx-1][idy]==wave -1:          # (верх)
                Ans[0].append(idx-1)
                Ans[1].append(idy)
                idx-=1
                flagg = 0
        
        if idx > 0 and idy < M-1 and flagg:
            if field[idx-1][idy+1]==wave -1:        # (верх - право)
                Ans[0].append(idx-1)
                Ans[1].append(idy+1)
                idx-=1
                idy+=1
                flagg = 0
        if idx<len(field)-1 and idy>0 and flagg:    # (низ - лево)
            if field[idx+1][idy-1]==wave -1:
                Ans[0].append(idx+1)
                Ans[1].append(idy-1)
                idx+=1
                idy-=1
                flagg = 0
        if idx<len(field)-1 and flagg:
            if field[idx+1][idy]==wave -1:          # (низ)
                Ans[0].append(idx+1)
                Ans[1].append(idy)
                idx+=1
                flagg = 0
        if idx < len(field) -1 and idy<M-1 and flagg:
            if field[idx+1][idy+1]==wave -1:          # (низ-право)
                Ans[0].append(idx+1)
                Ans[1].append(idy+1)
                idx += 1
                idy += 1
                flagg = 0
        if idy>0 and flagg:
            if field[idx][idy-1]==wave -1:          # (лево)
                Ans[0].append(idx)
                Ans[1].append(idy-1)
                idy-=1
                flagg = 0
        if idy<M-1 and flagg:
            if field[idx][idy+1]==wave-1:           # (право)
                Ans[0].append(idx)
                Ans[1].append(idy+1)
                idy+=1
                flagg = 0
        wave-=1


        
    
    return field, Ans
from random import *
#
#
#
#
#
while 1==1:
    field, Ans=wave()
    k =0
    for i in range(len(field)):
        for j in range(len(field[i])):                       #просто вывод на консольку  всего этого говна, наговнокодили они тут знатно..
            if field[i][j]!=len(field)*len(field[0])+1:
                k+=1
   
    if k == len(field)*len(field[0]):
        break
    else:
        field, Ans=wave()

for i in range(len(Ans[0])-1,-1,-1):
        print "x coordinate: ",Ans[0][i],"  y coordinate: ",Ans[1][i]

for i in range(len(field)):
    for j in range(len(field[i])):
        field[i][j] = str(field[i][j])
for i in range(len(field)):
            print '\t'.join(field[i])

for i in range(len(field)):
    for j in range(len(field[i])):
        field[i][j] = int(field[i][j])



#
#графоний
#
from Tkinter import *
root = Tk()

canv = Canvas(root,width=500,height=500,bg="lightblue") # канва - т.е. сама форма


size = 30

for i in range(len(field)):
    for j in range(len(field[i])):
        
                    but1 = Button(root,text=str(field[i][j]), bg='white',width=1,height=1)  #рисуем обычное полу
                    but1.grid(row=i,column=j)
                
for i in range(len(Ans[0])):
    
    but = Button(root,text=str(field[ Ans[0][i] ][ Ans[1][i] ]), bg='red',width=1,height=1)  #рисуем красненький путь к выходу
    but.grid(row=Ans[0][i],column=Ans[1][i])
        
root.mainloop() # залупим по полной эту херь
