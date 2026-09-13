import pandas as pd
import numpy as np

df = pd.read_json('../Data/jsondata.json')
pd.set_option('display.max_columns', None) #This will display all the columns in the dataframe instead of limiting it to a certain number. You can also use pd.set_option('display.max_rows', None) to display all the rows in the dataframe.
print(df.head())

df.to_json('../Data/to_json.json', orient='records', indent=4) #This will write the dataframe to a json file in the specified path. The orient parameter specifies the format of the json file. The lines parameter specifies whether to write the json file in a single line or multiple lines. If lines=True, the json file will be written in multiple lines. If lines=False, the json file will be written in a single line.
#indent parameter specifies the number of spaces to use for indentation in the json file. If indent=None, the json file will be written in a single line. If indent=4, the json file will be written in multiple lines with 4 spaces of indentation.

df = pd.json_normalize(pd.read_json('../Data/jsondata.json').to_dict('records'))
#Normalise semi-structured JSON data into a flat table. The to_dict('records') method converts the dataframe to a list of dictionaries, where each dictionary represents a row in the dataframe. The json_normalize() function then flattens the nested dictionaries into a flat table.
print(df.head())

