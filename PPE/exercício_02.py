str = "agiu desproporcionadamente"
cont = 0
tam = 26
def main():
    global cont
    for i in range(tam):
        if (str[i] == 'a'):
            cont += 1
    
    print(f"A letra 'a' aparece {cont} vezes na string {str}")

if __name__ == "__main__":
    main()





