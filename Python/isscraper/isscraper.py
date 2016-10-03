from bs4 import BeautifulSoup
import requests
import re
import csv
import unicodedata

url = 'http://www.intern.supply'
r = requests.get(url)
soup = BeautifulSoup(r.text, 'html.parser')
i = 0;
data = list()

for link in soup.find_all('a'):
    if i > 5:
        data.append( unicodedata.normalize('NFKD',((link.get('href'))) ).encode('ascii','ignore'))
    i += 1

for x in xrange(0,5):
    print data[x]
    print type(data[x])
with  open('internlinks.csv', 'wb') as myfile:
    wr = csv.writer(myfile, dialect = 'excel');
    for item in data:
        wr.writerow([item,])
