#!/usr/bin/python3.4
import sys
import random
def main():
    argc = len(sys.argv)
    if argc < 2:
        return 1;
    total = int(sys.argv[1])
    x = float()
    y = float()
    distancia = float()
    dentro = int(0)
    while total > 0:
        x = random.random()
        y = random.random()
        distancia = x**2 + y**2
        if distancia <= 1:
            dentro+=1
        total -=1

    print (dentro)
if __name__ == "__main__":
    main()
