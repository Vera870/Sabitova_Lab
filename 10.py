text = "Первый аккорд — и время будто замирает. Мелодия, мелодия обнимает, уносит, заставляет сердце биться чуть быстрее. В этих звуках прячется целый океан чувств, который каждый слышит по-своему"

print(text)

proposal = text.split('.')

print(proposal[0])
print(proposal[::-1])

word = text.replace('.', '').replace(',', '').replace(' — ', '').lower().split(' ')
print(word)

my_list = []
max = 1
min = 100
M=0
m=0
for i in word:
    if word.count(i)>1:
        my_list.append(i)
    if len(i)>max:
        M = i
        max = len(i)
    if len(i) < min:
        m = i 
        min = len(i)

print(set(my_list))
print(M)
print(m)
print(text.replace('а', 'о').replace('А', 'О'))