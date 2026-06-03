def nim_sum(gomile):
    rezultat = 0
    for x in gomile:
        rezultat ^= x
    return rezultat


def prikazi_gomile(gomile):
    print("\nTrenutne gomile:")
    for i, x in enumerate(gomile):
        print(f"{i + 1}. gomila: {x}")


def potez_racunara(gomile):
    xor = nim_sum(gomile)

    if xor == 0:
        # Nema pobedničkog poteza
        for i in range(len(gomile)):
            if gomile[i] > 0:
                gomile[i] -= 1
                print(f"Računar je uzeo 1 iz gomile {i + 1}")
                return

    for i in range(len(gomile)):
        cilj = gomile[i] ^ xor

        if cilj < gomile[i]:
            uzima = gomile[i] - cilj
            gomile[i] = cilj
            print(f"Računar je uzeo {uzima} iz gomile {i + 1}")
            return


broj_gomila = int(input("Unesite broj gomila: "))

gomile = []
for i in range(broj_gomila):
    x = int(input(f"Broj kamenčića u gomili {i + 1}: "))
    gomile.append(x)

igrac_na_potezu = True

while sum(gomile) > 0:
    prikazi_gomile(gomile)

    if igrac_na_potezu:
        while True:
            gomila = int(input("Izaberite gomilu: ")) - 1

            if 0 <= gomila < len(gomile) and gomile[gomila] > 0:
                break

            print("Neispravna gomila")

        while True:
            uzima = int(input("Koliko uzimate "))

            if 1 <= uzima <= gomile[gomila]:
                break

            print("Neispravan broj")

        gomile[gomila] -= uzima

        if sum(gomile) == 0:
            print("\nPobedili ste")
            break

    else:
        potez_racunara(gomile)

        if sum(gomile) == 0:
            print("\n Racunar pobedjuje ")
            break

    igrac_na_potezu = not igrac_na_potezu