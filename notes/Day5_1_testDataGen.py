import random

min = 0
max = 1000


for i in range(0, 20):
	tmp = random.randint(min, max)
	tmp2 = random.randint(tmp, tmp+10)
	
	print(f"{tmp}-{tmp2}")

print()

for i in range(0, 50):
	print(f"{random.randint(min, max)}")