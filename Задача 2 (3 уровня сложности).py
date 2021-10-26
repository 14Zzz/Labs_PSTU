import random
import time

# Это прост так, НИХОТЮ по ней отчет делать, сделаю по 0-100))

def Igra(n):  # n - число попыток
    p = 0
    x = 123
    if n == 7:
        r = random.randint(1, 101)
    elif n == 19:
        r = random.randint(1, 500001)
    else:
        r = random.randint(1, 2049)
    start_time = time.time()

    while n > p and r != x:
        if time.time() - start_time > 60 and n == 11:
            print("Тик - так, тик - так...")
            print("КАКАЯ ЖАЛОСТЬ, ТЫ ПРОИГРАЛ")
            time.sleep(2)
            break
        p += 1
        print("Попытка №", p, "Прошедшее время -", int(time.time() - start_time), "сек")
        try:
            x = int(input("Введите число: "))
        except ValueError:
            print()
            print("Целое число выглядит не так, но ничего, все совершают ошибки - попробуй ещё раз")
            print()
            time.sleep(2)
            break
        if x == r:
            print()
            print("Вы угадали число за", int(time.time() - start_time), "сек")
            print("""░░░░░░░██████╗░███████╗██████╗░░
░░██╗░░██╔══██╗██╔════╝██╔══██╗░
██████╗██████╔╝█████╗░░██████╔╝░
╚═██╔═╝██╔══██╗██╔══╝░░██╔═══╝░░
░░╚═╝░░██║░░██║███████╗██║░░░░░░
░░░░░░░╚═╝░░╚═╝╚══════╝╚═╝░░░░░░""")
            print()
            time.sleep(2)
        elif x > r:
            print("Загаданное число меньше введенного")
            print()
        else:
            print("Загаданное число больше введенного")
            print()
        if p == n and x != r:
            print("Проигрывать всегда больно...")
            print("Загаданное число было -", r)
            time.sleep(2)
            print()


while True:
    print("""Выберите сложность:
*Для выбора введите номер сложности*
    1) Нормал - числа от 1 до 100, 7 попыток
    2) Хардкор - числа от 1 до 500 000, 19 попыток
    3) РОФАН ПОМИНКИ - числа от 1 до 2048, 11 попыток, НО ВАШ ПРОТИВНИК - САМО ВРЕМЯ""")
    try:
        slownost = int(input("Я выбираю: "))
        if slownost not in range(1, 4):
            print("Некоректный ввод номера сложности (Нужно ввести число от 1 до 3)")
            print()
            time.sleep(2)
        elif slownost == 1:
            Igra(7)
            r = random.randint(1, 101)
        elif slownost == 2:
            Igra(19)
            r = random.randint(1, 500001)
        else:
            Igra(11)
            r = random.randint(1, 2049)
            start_time = time.time()
    except ValueError:
        print("Некоректный ввод номера сложности (Нужно ввести число от 1 до 3)")
        time.sleep(2)
        print()
