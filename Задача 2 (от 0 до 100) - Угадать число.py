import random

print("Для ывхода из программы введите: 1111")
Vvod = 0
while Vvod != 1111:
    print("Вам нужно угадать целое число от 0 до 100 (включительно) за 7 попыток - Удачи!")
    Chislo = random.randint(0, 100)
    Popitka = 0
    Vvod = 1
    while 7 > Popitka and Chislo != Vvod and Vvod != 1111:
        if Vvod == 1111:
            break
        Popitka += 1
        print("Попытка №", Popitka)
        try:
            Vvod = int(input("Введите число: "))
        except ValueError:
            print()
            print("Целое число выглядит не так, но ничего, все совершают ошибки - попробуй ещё раз")
            print()
            break
        if Vvod == Chislo:
            print()
            print("Вы угадали!!!")
            print("""░░░░░░░██████╗░███████╗██████╗░░
░░██╗░░██╔══██╗██╔════╝██╔══██╗░
██████╗██████╔╝█████╗░░██████╔╝░
╚═██╔═╝██╔══██╗██╔══╝░░██╔═══╝░░
░░╚═╝░░██║░░██║███████╗██║░░░░░░
░░░░░░░╚═╝░░╚═╝╚══════╝╚═╝░░░░░░""")
            print()
        if Vvod > Chislo and Vvod != 1111:
            print("Загаданное число меньше введенного")
            print()
        if Vvod < Chislo and Vvod != 1111:
            print("Загаданное число больше введенного")
            print()
        if Popitka == 7 and Vvod != Chislo:
            print("Проигрывать всегда больно...")
            print("Загаданное число было -", Chislo)
            print()
