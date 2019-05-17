#Daniel Charua A01017419

import numpy as np

dim = 8
item = 1000
cost = 0
completados = 0

state = np.zeros((dim,dim))

machineA =      [0, .93, 0, 0, 0, 0, .07, 0]
inspectorA =    [.04, 0, .94, 0, .0, 0, .02, 0]
machineB =      [0, 0, 0, .95, 0, 0, .05, 0]
inspectorB =    [0, 0, .03, 0, .96, 0, .01, 0]
machineC =      [0, 0, 0, 0, 0, .97, .03, 0]
inspectorC =    [0, 0, 0, 0, .01, 0, .01, .98]
leftover =      [0, 0, 0, 0, 0, 0, 1, 0]
packing =       [0, 0, 0, 0, 0, 0, 0, 1]

items = [item, 0, 0, 0, 19, 0, 0, 0]
vector = np.array(items)

hour = [3, .25, 2.5, .25, 1.5, .25, 0, .1]
hour_cost = [10, 10, 10, 10, 12, 10, 0, 8]
expenses = []

for h, c in zip(hour, hour_cost):
    expenses.append(h*c)

for x in range(dim):
    state[0,x] = machineA[x]
    state[1,x] = inspectorA[x]
    state[2,x] = machineB[x]
    state[3,x] = inspectorB[x]
    state[4,x] = machineC[x]
    state[5,x] = inspectorC[x]
    state[6,x] = leftover[x]
    state[7,x] = packing[x]

c1 = 0

while(int(vector[-1] < item)):
    if(int(vector[-1]) < item and round(vector[-1] + vector[-2], 0) >= item):
        vector[0] += 1
    cost += (vector.dot(expenses) - (c1 * expenses[-1]))
    c1 = int(vector[-1])
    vector = vector.dot(state)

print('Se necesita {} articulos para producir {}\n'
    'Con un costo de: ${}'
    .format(int(vector[-1] + vector[-2]), item, round(cost,2))
    )