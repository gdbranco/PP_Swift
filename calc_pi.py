#!/usr/bin/python3.4
import sys

def main():
    argc = len(sys.argv)
    n_f = int(sys.argv[1])
    medias = 0
    while argc > 2:
        with open(sys.argv[argc - 1], "r") as inp_file:
            medias += int(inp_file.read())
        argc -= 1
    print(4.0*medias/n_f)

    #return medias*4;

if __name__ == "__main__":
    main()
