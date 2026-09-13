import pandas as pd
import numpy as np  

df = pd.read_html('../Data/htmldata.html')
print(df)
print()#this is for a blank line between the two outputs.

print(df[0]) #It will print the first table in the html file.
print()

#For printing all tables using loop
for tables in df:
    print(tables)
    print()

#Showing the only matching table using the match parameter
df = pd.read_html('../Data/htmldata.html', match='Player')
print(df[0]) #It will print the first table in the html file.

#Converting back to html from dataframe
df[0].to_html('../Data/to_htmldata.html')
