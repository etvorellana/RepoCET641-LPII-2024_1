
from random import randint

def geraSeq(N):
    seq = []
    cont = 0
    while (cont < N):
        nSeq = randint(1, N)
        if nSeq in seq:
            continue
        seq.append(nSeq)
        cont += 1
    return seq


def main():
    equipes = {"Equipe1":["ARTHUR ARAUJO BRITO", "BRUNO CARDOSO DE JESUS", 
                      "JOÃO PEDRO FRANÇA CHAVES OLIVEIRA", "VINICIUS DANIEL RAMOS CUNHA",
                      "LUCAS VIEIRA DE ALMEIDA"],
                "Equipe2":["BRUNO GABRIEL LEITE DE MATOS", "PEDRO VITOR MOURA DE ARAUJO BARROS",
                      "GABRIEL ROSA GALDINO", "YOHANAN SANTOS DE SANTANA"],
                "Equipe3":["ANTONIO HENRIQUE OLIVEIRA SANTOS", "ARIEL PINA RIBEIRO",
                      "STÊNIO CARVALHO SANTOS FILHO", "STELLA DA SILVA RIBAS" ],  
                "Equipe4":["HENRIQUE SOUSA BRITO", "ANA BEATRIZ SOUZA ALMEIDA", 
                      "DIOGO SANTOS CERQUEIRA", "TIAGO SANTOS ALCANTARA"]}
    print("Primeira Rodada:")
    seq = geraSeq(4)
    for i in range(4):  
        print(f"Equipe: {}"



 #GLEISON FONSECA DE PAULA

 
 


 

