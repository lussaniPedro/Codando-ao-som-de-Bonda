import os
import msvcrt

player = ({
    "Nome": "Python",
    "x": 0,
    "y": 0
})

def andar(direcao):
    if direcao == "d":
        player['x'] += 1
    elif direcao == 'a':
        player['x'] -= 1
    elif direcao == 's':
        player['y'] += 1
    elif direcao == 'w':
        player['y'] -= 1

def captura_tecla():
    return msvcrt.getch().decode('utf-8').lower()

while True:
    os.system('cls')

    print("------------------------")
    for y in range(5):
        print("\n")
        for x in range(10):
            if player['x'] == x and player['y'] == y:
                print("🤺", end="")
            else:
                print("🟩", end="")
    print("\n\n\n------------------------")

    print("Digite (w, a, s, d): ")
    direcao = captura_tecla()

    if direcao in ['w', 'a', 's', 'd']:
        andar(direcao)
    elif direcao == 'e':
        os.system('cls')
        print("Saindo...")
        break
    else:
        os.system('cls')
        print("Tecla inválida. Use W/A/S/D para andar.")
        print("Pressione qualquer tecla para continuar...")
        msvcrt.getch().decode('utf-8').lower()