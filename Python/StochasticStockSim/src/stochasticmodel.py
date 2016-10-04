import math as m

def stochasticModel(annualreturn, annualstddev, startprice, iterator):
    return startprice + startprice*(annualreturn/255 + annualstddev/m.sqrt(255)*iterator)

