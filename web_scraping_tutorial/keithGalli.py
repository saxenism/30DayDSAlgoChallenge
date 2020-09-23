import requests
from bs4 import BeautifulSoup as bs

# Load our first page
r = requests.get("https://keithgalli.github.io/web-scraping/example")

soup = bs(r.content, features = "html.parser")

#print(soup.prettify())

# find(finds the first matching element) and find_all are the most frequently used bs4 functions
first_header = soup.find("h2")
# print(first_header)

headers = soup.find_all("h2")
# print(headers)

#We can also pass in a list to these functions
first_found_header = soup.find(["h1", "h2"])
headers_list = soup.find_all(["h1", "h2"])
# print(first_found_header, "\n",  headers_list)

# We can pass attributes to these functions as well
# Find a paragraph with id == paragraph-id
id_para = soup.find_all("p", attrs = {"id":"paragraph-id"})
# print(id_para)

# We can nest our find and find_all calls
body = soup.find("body")
#print(body)
div = body.find("div")
#print(div)
header_of_div = div.find("h1")
#print(header_of_div)

# we can also use match exact string or string patters(using re{regular expression})
import re
paragraph = soup.find_all("p", string = re.compile("Some"))
print(paragraph)