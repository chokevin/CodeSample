from bs4 import BeautifulSoup
import requests
import re
import logging
import json

#Scrapes for specific stocks since each stock has its specific span id 
#Currently set up for scraping tech stocks

#Setting up the logger
logger = logging.getLogger('stockprices')
logger.setLevel(logging.DEBUG)
fh = logging.FileHandler('data/stockprices.log')
fh.setLevel(logging.DEBUG)
ch = logging.StreamHandler()
ch.setLevel(logging.ERROR)
formatter = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s')
fh.setFormatter(formatter)
ch.setFormatter(formatter)
logger.addHandler(fh)
logger.addHandler(ch)

#google finance scraper
def gfscraper():
    stockprices = {}

    url = 'https://www.google.com/finance?q=google'
    r = requests.get(url)
    soup = BeautifulSoup(r.text, 'html.parser')
    #print(soup.prettify())

    #Google Stock Location
    #Finds the div location by id and prints the span text 
    div = soup.find('div', {'id': 'price-panel'})
    span = div.find('span', attrs={'id':'ref_694653_l'})
    stockprices['google'] = span.text

    #Fitbit
    url = 'https://www.google.com/finance?q=fitbit'
    r = requests.get(url)
    soup = BeautifulSoup(r.text, 'html.parser')
    #print(soup.prettify())

    #Microsoft Stock Location
    #Finds the div location by id and prints the span text 
    div = soup.find('div', {'id': 'price-panel'})
    span = div.find('span', attrs={'id':'ref_764194243742232_l'})
    stockprices['fitbit'] = span.text

    with open('data/data.JSON', 'w') as outfile:
        json.dump(stockprices, outfile)

    logger.info('Completed Script Sequence')

gfscraper()
