#Выполнил: Короленко Иван Романович
#Студент: ККМТ П2-18.

'''Задание 1. Array112. Дан массив A размера N.
Упорядочить его по возрастанию методом сортировки
простым обменом («пузырьковой» сортировкой):
просматривать массив, сравнивая его соседние элементы
(A0 и A1, A1 и A2 и т. д.) и меняя их местами,
если левый элемент пары больше правого; повторить описанные
действия N  1 раз. Для контроля за выполняемыми действиями
выводить содержимое массива после каждого просмотра.
Учесть, что при каждом просмотре количество анализируемых
пар можно уменьшить на 1.'''

from random import randint

arr = []
N = int(input())
for i in range(N):
    arr.append(randint(1, 99))
print('Начальный массив\n',arr)


for i in range(1,N) :
    print(arr)
    for j in range(0,N-i) :
        if arr[j] > arr[j+1] :
            arr[j], arr[j+1] = arr[j+1], arr[j]   

print('\nКонечный массив\n',arr)
