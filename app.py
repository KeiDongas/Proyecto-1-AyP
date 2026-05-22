def Polindromo(argumento: int):
    for nums in str(argumento):
        print(nums)

def tocamiento():
    while True:
        try:
            num = int(input("Digita un nu65mero: "))
            try:
                Polindromo(num)
                break
            except TypeError:
                print(f'{num} No es un numero iterable, intenta con un numero mas grande')
        except ValueError:
            print("digita un numero entero!") 


tocamiento()