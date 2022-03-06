import string
import random

#This problem was asked by Microsoft.

#Implement a URL shortener with the following methods:
#shorten(URL), which shortens the URL into a six-character alphanumeric string, such as zLg6wl.
#restore(short), which expands the shortened string into the original URL. If no such shortened string exists, return null.

#Hint: What if we enter the same URL twice?
#   should we just have the shortener generate two different strings?
#   LET'S DO BOTH!

#assumptions:

# - There exists a dictionary that contains all URLs that HAVE been shortened. This dict is called URL_dict.
# - We should implement both a redundant shortening method and a nonredundant shortening method.

URL_dict = dict()

# define an alphanumeric array where we can choose from:

alpha_low = string.ascii_lowercase
alpha_high = string.ascii_uppercase
num = "0123456789"

alphanum = alpha_high + alpha_low + num

def createShortURL():
    # create randomized string for short URL
    # if it exists already as a key in URL_dict, then try again.
    
    short = ""  # define string, "short"
    while short == "":
        for i in range(6):
            short += random.choice(alphanum)

        if short in URL_dict.keys():
            short == ""

    return short

def shortenRedundant(longURL):
    short = createShortURL()
    # don't forget to add the URL into the dict!
    URL_dict[short] = longURL
    return short

def shortenNonRedundant(longURL):
    #if the longURL is found in URL_dict, then return its key!
    for key in URL_dict.keys():     # traversing all shortURL's to check for existing longURL
        if longURL == URL_dict[key]:
            return key
    # otherwise, just create shortURL and add it to dict
    short = createShortURL()
    URL_dict[short] = longURL
    return short

def restoreShort(shortURL):
    if shortURL in URL_dict.keys():
        return URL_dict[shortURL]
    else: return None


def main():
    URLs = ["www.sokoglam.com", "www.google.com", "www.sokoglam.com"]

    print("\nNon-redundant shortening:")

    for URL in URLs:
        print("\nOG URL: ", URL)
        short = shortenNonRedundant(URL)
        print("shortened URL: ", short)
        print("Restored long URL: ", restoreShort(short))

    print("\nRedundant shortening:")

    for URL in URLs:
        print("\nOG URL: ", URL)
        short = shortenRedundant(URL)
        print("shortened URL: ", short)
        print("Restored long URL: ", restoreShort(short))

main()
        




