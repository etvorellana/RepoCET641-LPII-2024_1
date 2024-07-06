
def main():
    a = 10
    b = 20
    print("a = %d, b = %d\n" % (a, b))
    troca_1(a, b)
    #lista = [a, b]
    #troca_2(lista)
    #a = lista[0]
    #b = lista[1]
    #dupla = (a, b)
    #dupla = troca_3(dupla)
    #a = dupla[0]
    #b = dupla[1]
    #dupla = (a, b)
    #troca_4(dupla)
    #a = dupla[0]
    #b = dupla[1]
    #dic = {'a': a, 'b': b}
    #troca_5(dic)
    #a = dic['a']
    #b = dic['b']
    print("a = %d, b = %d\n" % (a, b))

def troca_1(a, b):
    temp = a
    a = b
    b = temp

def troca_2(lista):
    temp = lista[0]
    lista[0] = lista[1]
    lista[1] = temp


def troca_3(dupla):
    dupla = (dupla[1], dupla[0])
    return dupla

def troca_4(dupla):
    a = dupla[0]
    b = dupla[1]
    temp = a
    a = b
    b = temp
    dupla = (a, b)

def troca_5(dic):
    temp = dic['a']
    dic['a'] = dic['b']
    dic['b'] = temp


def main_():
    a = 10
    b = 20
    print("a = %d, b = %d\n" % (a, b))
    #trocar os valores de a e b
    print("a = %d, b = %d\n" % (a, b))

if __name__ == "__main__":
    main()



