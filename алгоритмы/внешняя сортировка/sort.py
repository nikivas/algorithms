fin = open("input.txt","r")
fout = open("out.txt","w")
buf = []
f = 0
for line in fin:
    if(len(buf) < 1024):
        buf.append(line[:len(buf)-2])
        continue
    f = 1

if f == 0:
    fout.write('\n'.join(sorted(buf)))
