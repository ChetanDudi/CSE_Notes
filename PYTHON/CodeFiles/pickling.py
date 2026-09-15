import pandas as pd
import seaborn as sns
import pickle as pkl

df = pd.read_csv('../Data/commadata.csv', skipinitialspace=True, dtype={'Id': str, 'Name': str, 'Age': int, 'FavSports': str}) #This will read the CSV file and convert the 'Id' and 'Name' columns to strings, the 'Age' column to integers, and the 'FavSports' column to strings.
print(df.head())

pkl.dump(df, open('../Data/to_pkl.pkl', 'wb')) #This will pickle the DataFrame and save it to a file named 'commadata.pkl' in the '../Data/' directory.
