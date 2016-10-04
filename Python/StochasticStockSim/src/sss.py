# Author: Kevin Cho
# Creates a plot for the simulation of stock X which can be manipulated through various variables
# Utilizes R-like Python functions to create the graph

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import math as m
import stochasticmodel as sm

df = pd.DataFrame

mu, sigma = 0, 1 #mean and standard deviation

randnorm = np.random.normal(mu, sigma, 255)
annualreturn = .30 #expected Annual Return (30%)
annualstddev = .2 #Expected annual standard deviation (20%)
startprice = 100 #Expected Starting Price
price = []

for i in randnorm:
    newprice = sm.stochasticModel(annualreturn, annualstddev, startprice, i)
    price.append(newprice)
    startprice = newprice

df = df(price)
print(df.describe())
plt.plot(range(0, 255),price)
plt.xlabel('time (t)')
plt.ylabel('price ($)')
plt.title('Time series stock X')
plt.show()

