import csv
import math as m
from sys import stdin

#Cleared

lat = list()
lon = list()
phone = list()
time = list()
readin = input()
answer = list();
r = 6378.137
coord = readin.split(",")
rad = input()
rad = float(rad)
readin = input()
for line in stdin:

    data = line.split(",")
    if data[3].rstrip('\n') in phone :
        i = phone.index(data[3].rstrip('\n'))
        if data[0] > time[i] :
            time[i] = data[0]
            lat[i] = m.radians(float(data[1]))
            lon[i] = m.radians(float(data[2]))
    else :
        time.append(data[0])
        lat.append(m.radians(float(data[1])))
        lon.append(m.radians(float(data[2])))
        phone.append(data[3].rstrip('\n'))

for index,value in enumerate(phone):
    sinelat = m.sin((m.radians(float(coord[0]))-float(lat[index]))/2)
    sinelat = m.pow(sinelat,2)
    sinelon = m.sin((m.radians(float(coord[1]))-float(lon[index]))/2)
    sinelon = m.pow(sinelon,2)
    d = 2*r*m.asin(m.sqrt(sinelat+(m.cos(m.radians(float(coord[0])))*m.cos(float(lat[index]))*sinelon)))
    if d < rad:
        answer.append(value)

answer.sort()

strans = ""
for info in answer:
    strans += str(info) + ","

strans = strans[:-1]
print(strans)
