import pandas as pd
import numpy as np

#read xml file
df = pd.read_xml('../Data/xmldata.xml')
print(df)
print('---------------------------------------')

#read xml file with namespace
df = pd.read_xml('../Data/xmlnamespacedata.xml', xpath='.//s:student', namespaces={'s': 'http://example.com/student'})
print(df)

#Convert dataframe to xml file
df.to_xml('../Data/to_xml.xml', index=False) #This will write the dataframe to a xml file in the specified path. The index parameter specifies whether to write the index to the xml file. If index=True, the index will be written to the xml file. If index=False, the index will not be written to the xml file.