import asyncio
import os
import sys

print(sys.argv[1])

async def main():
    os.system("./bin/brainfuck " + sys.argv[1] + "|| echo $?")
    await asyncio.sleep(2)
    os.system("pkill brainfuck")

asyncio.run(main())
