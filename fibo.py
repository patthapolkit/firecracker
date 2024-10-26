import time
import sys

def fibonacci(n):
    a = 0
    b = 1
    
    if n < 0:
        return "Incorrect input"
    elif n == 0:
        return 0
    elif n == 1:
        return b
    else:
        for _ in range(1, n):
            c = a + b
            a = b
            b = c
        return b

if __name__ == "__main__":
    n = int(sys.argv[1])
    start_time = time.time()
    fibonacci(n)
    end_time = time.time()
    time_used = end_time - start_time
    print(f"{n},{time_used}")