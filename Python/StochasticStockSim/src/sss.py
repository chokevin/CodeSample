# Author: Kevin Cho
# Creates a plot for the simulation of stock X which can be manipulated through various variables
# Utilizes R-like Python functions to create the graph

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import math as m

df = pd.DataFrame

mu, sigma = 0, 1 #mean and standard deviation

Z = np.random.normal(mu, sigma, 255)
u = .30 #expected Annual Return (30%)
sd = .2 #Expected annual standard deviation (20%)
s = 100 #Expected Starting Price
a = 2
price = []

for i in Z:
    S = s + s*(u/255 + sd/m.sqrt(255)*i)
    price.append(S)
    s = S
    a += 1

df = df(price)
print(df.describe())
plt.plot(range(0, 255),price)
plt.xlabel('time (t)')
plt.ylabel('price ($)')
plt.title('Time series stock X')
plt.show()

