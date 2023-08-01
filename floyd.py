import time
INF = 99999

def min(a, b):
    return a if a < b else b

def floyds(p, n):
    for k in range(1, n+1):
        for i in range(1, n+1):
            for j in range(1, n+1):
                if i == j:
                    p[i][j] = 0
                else:
                    p[i][j] = min(p[i][j], p[i][k] + p[k][j])

def main():
    n = int(input("Enter the number of vertices: "))
    e = int(input("Enter the number of edges: "))
    
    p = [[INF for _ in range(n+1)] for _ in range(n+1)]

    for i in range(1, n+1):
        for j in range(1, n+1):
            if i == j:
                p[i][j] = 0

    print("Enter the edges with corresponding weights (source : destination : weight):")
    for _ in range(e):
        u, v, w = map(int, input().split())
        p[u][v] = w

    print("\nMatrix of input data:")
    for i in range(1, n+1):
        for j in range(1, n+1):
            if p[i][j] == INF:
                print("INF", end="\t")
            else:
                print(p[i][j], end="\t")
        print()
    start=time.time();
    floyds(p, n)
    end=time.time();
    print("\nTransitive closure:")
    for i in range(1, n+1):
        for j in range(1, n+1):
            print(p[i][j], end="\t")
        print()

    print("\nThe shortest paths are:")
    for i in range(1, n+1):
        for j in range(1, n+1):
            if i != j:
                print(f"\n {i}---->{j}={p[i][j]}", end="")
    print()            
    print("execution time = ",(end-start))
    print()

if __name__ == "__main__":
    main()
