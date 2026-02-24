import asyncio
import time
import os
import sys

print(sys.argv[1])

async def main():
    os.system("./bin/brainfuckd " + sys.argv[1] + "|| echo $?")
    await asyncio.sleep(2)
    os.system("pkill brainfuckd")

asyncio.run(main())
