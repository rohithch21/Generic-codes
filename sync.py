import time

start = time.time()

def func1():
    print("Starting function 1")
    time.sleep(2)
    print("Closing funtion 1")

def func2():
    print("Starting function 2")
    time.sleep(4)
    print("Closing funtion 2")


f = [func1(),func2()]
for i in f:
    fn = i
end = time.time()
print("Time consumed : ",end-start)
