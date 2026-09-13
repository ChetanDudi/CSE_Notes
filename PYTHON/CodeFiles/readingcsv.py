import pandas as pd
import numpy as np

df = pd.read_csv('../Data/commadata.csv')
print(df.head())

df = pd.read_csv('../Data/commadata.csv',usecols=['Id', ' Name', ' FavSports'])
print(df.head())

df = pd.read_csv('../Data/commadata.csv',usecols=['Id', 'Name', 'FavSports'], skipinitialspace=True)
print(df.head())

df.to_csv('../Data/to_csv.csv', index=False, header=True) #This will create a new CSV file with the specified columns and without row numbers.
#index=False  → Don't save row numbers
#header=True  → DO save column names

df = pd.read_csv('../Data/commadata.csv', skipinitialspace=True, dtype={'Id': str, 'Name': str, 'Age': int, 'FavSports': str}) #This will read the CSV file and convert the 'Id' and 'Name' columns to strings, the 'Age' column to integers, and the 'FavSports' column to strings.
print(df.head())

df = pd.read_csv('../Data/commadata.csv', index_col=['Id'], skipinitialspace=True) #This will read the CSV file and set the 'Id' column as the index of the DataFrame.
print(df.head()) #or index_col=0 , we can give the index number of that column which we want to set as index. In this case, 'Id' is the first column, so we can use index_col=0.

print('hello')

df = pd.read_csv('../Data/tabdata.csv', sep='\t', index_col=['ID']) #This will read the CSV file and use a tab character as the delimiter instead of a comma.
print(df.head())