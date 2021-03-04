# -*- coding: utf-8 -*-
# блок определения таблицы переходов
if __name__ == '__main__':
    table_perehod = [['A', '2', 'B'],
                    ['A', '1', 'F'],
                    ['A', 'b', 'L'],
                    ['B', '1', 'C'],
                    ['C', 'b', 'A'],
                    ['E', '1', 'F'],
                    ['E', 'b', 'L'],
                    ['F', '1', 'G'],
                    ['G', '2', 'H'],
                    ['H', 'b', 'E'],
                    ['K', 'b', 'L'],
                    ['L', '1', 'M'],
                    ['M', '2', 'N'],
                    ['N', '2', 'K']]
    nachaln_simv='A' #начальный символ он у Вас скорее всего 'A'
    kol_perehodov=len(table_perehod)
    print("Дано регулярное выражение (21b)* (112b)* (b122)*")
    ex="none"
    while ex!="exit":
        stroka = input("Введите строку символов: ")
        length = len(stroka)
        n = 0
        ok = True
        neterm = nachaln_simv
        while ok and (n < length):
            i = 0
            sym = stroka[n]
            n += 1
            ok = False
            while True:
                if (table_perehod[i][0] == neterm) and (table_perehod[i][1] == sym):
                    ok = True
                    neterm = table_perehod[i][2]
                i += 1
                if not((not ok) and (i < kol_perehodov)):
                    break
         #терминальные символы они у Вас скорее всего 'A'  'E' 'K'
        if ((neterm == 'A') or (neterm == "E") or (neterm == 'K')) and ok:
            print("Данная строка принадлежит языку")
        else:
            print("Данная строка не принадлежит языку")
        ex=input("Нажмите ENTER для продолжения или exit для выхода: ")
