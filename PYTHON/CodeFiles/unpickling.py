import pandas as pd
import seaborn as sns
import pickle as pkl

df = pkl.load(open('../Data/to_pkl.pkl', 'rb')) #This will unpickle the DataFrame from the file named 'to_pkl.pkl' in the '../Data/' directory.
print(df.head())
