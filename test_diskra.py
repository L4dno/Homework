def inp(x,y,z):
    return ((x==y)and(y==z))<=(x==z)

def outp(x,y,z):
    return (x and not y) or (not x and y) or (not y and z) or (not z and y) or (not y and not x) or (y and x)

for x in [0,1]:
    for y in [0,1]:
        for z in [0,1]:
            if (inp(x,y,z)!=outp(x,y,z)):
                print(x,y,z,inp(x,y,z), outp(x,y,p))

print(6)
