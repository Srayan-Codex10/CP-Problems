def pileUp(size: int, cubes: list) -> str:
    pile_stack = []
    bottom = 0
    track = 0
    for i in range(size-1,-1,-1):
        if(track != i):
            if(len(pile_stack) == 0):
                if (cubes[i] >= cubes[bottom]):
                    pile_stack.append(cubes[i])
                if(cubes[bottom] > cubes[i] or cubes[bottom] == cubes[i]):
                    pile_stack.append(cubes[bottom])
                    bottom += 1
            else:
                if(cubes[i] <= pile_stack[track]):
                    pile_stack.append(cubes[i])
                    track += 1 
                if(cubes[bottom] <= pile_stack[track]):
                    pile_stack.append(cubes[bottom])
                    bottom += 1
                    track += 1
        else:
            break

    if(len(pile_stack) == size):
        return 'Yes'
    else:
        return 'No'


inputs = {}
t = int(input())
for i in range(t):
    n = int(input())
    inputs[n] = list(map(int, input().strip().split()))

for key,val in inputs.items():
    print(pileUp(key, val))