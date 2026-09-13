import pandas as pd
import numpy as np
from io import StringIO

data = ('col1,col2,col3\n'
        'a,b,c\n'
        'd,e,f\n'
        'g,h,i\n')
df = pd.read_csv(StringIO(data))
print(df.head())