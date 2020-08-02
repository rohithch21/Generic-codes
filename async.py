import asyncio
import time

start = time.time()

async def func1():
    print("Starting function 1")
    await asyncio.sleep(2)
    print("Closing function 1")
    return "func1"

async def func2():
    print("Starting function 2")
    await asyncio.sleep(4)
    print("Closing function 2")
    return "func2"

async def main():
    await asyncio.gather(func1(),func2())
    end = time.time()
    print("Time consumed : ", end - start)

asyncio.run(main())