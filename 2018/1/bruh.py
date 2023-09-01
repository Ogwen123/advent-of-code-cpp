changes = []
frequencies = []
with open('2018/1/input.txt') as f:
    changes = f.read().split("\n")
i = 1
j = 1
frequencies.append(int(changes[0]))
while True:
    frequencies.append(frequencies[j-1] + int(changes[i]))
    if frequencies[-1] in frequencies[0:len(frequencies)-1] and j > 0:
        print(frequencies[j])
        print(len(frequencies))
        break
    if i == len(changes)-1:
        i=0
    else:
        i+=1
    j+=1