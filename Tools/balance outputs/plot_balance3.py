# coding: utf-8
# Example code to read and plot Energy_zone.BAL.
# author     Yuichi Yasuda @ quattro corporate design
# copyright  2023 quattro corporate design. All right reserved.

import pandas as pd
import re
import plotly.graph_objs as go
import glob

from plotly.subplots import make_subplots

FILE_PATH = r'.\Project\SOLAR_WIN *.BAL'  # File path to read
OUTPUT_PATH = 'balance3_solar_win{surface_number: >5}.html'  # html file path to save
FIGURE_TITLE = 'Balance 3 - Solar balance for external window - Surface no. {surface_number: >5}' # Figure title, e.g. 'Energy balance for surface - surface no.0001'
Y_AXIS_RANGE = [-30000, 30000] # Y-axis range, e.g. [-30000, 30000]
Y_AXIS_TITLE = 'Solar Balance [kJ/h]' # Y-axis title, e.g. 'Energy [kWh]'
PLOT_START_TIME = 0 # Plot start time [h], e.g. 0
DATETIME_ORIGIN = '2021-01-01' # Calendar start date other than leap years, e.g. '2021-01-01'

# Function to split lines using both "｜" and spaces as delimiters
def custom_split(line):
    # First split by "｜"
    parts = line.split("|")
    # Then split each part by spaces
    parts = [re.split(r'\s+', part.strip()) for part in parts]
    # Flatten the list of lists
    return [item for sublist in parts for item in sublist]


if __name__ == '__main__':

    # folder_path = '.\\Project\\'
    # pattern = 'SOLAR_WIN *.BAL'

    # # List all files that match the pattern
    # files = glob.glob(os.path.join(folder_path, pattern))

    # List all files that match the pattern
    files = glob.glob(FILE_PATH)

    # Print the list of files
    for i, file in enumerate(files):
        print(f"{i+1}. {file}")

    # Ask the user to select a file
    selection = int(input("Select a file to open: ")) - 1

    # Open the selected file
    file_path = files[selection]

    # Extract the numbers from the file name
    numbers = re.findall(r'\d+', file_path)
    surface_number = int(numbers[-1])
    # print(f'File no. {numbers}')
    

    # Read the file line by line and apply custom splitting
    with open(file_path, 'r') as f:
        lines = f.readlines()

    # Extract header and data
    header_line = lines[0].strip().replace('=', ' ').replace('+', ' ').replace('-', ' ').replace(';', ' ')
    unit_line = lines[1].strip()
    data_lines = lines[2:]


    # Create DataFrame
    header = custom_split(header_line)
    units = custom_split(unit_line)
    data = [custom_split(line.strip()) for line in data_lines]

    
    # Convert to DataFrame
    df = pd.DataFrame(data, columns=header)

    # Convert all columns to float
    df = df.astype(float)

    # print(df.head(10))

    # Remove unnecessary symbols from column names
    df.columns = [re.sub(r'[-+=]', '', col) for col in df.columns]
    
    # Extracting data excluding the pre-calculation period.
    # In this example, we extract the data after 24h
    # df = df[df['TIME'].astype(float) >= 24]　# 24h以降のデータを抽出
    df = df[df['TIME'].astype(float) >= PLOT_START_TIME] # 0h以降のデータを抽出

    # Convert TIME column to date/time and set to the Index.
    df.index = pd.to_datetime(df['TIME'], unit='h', origin=DATETIME_ORIGIN)
    
    # Drop the TIME column
    df = df.drop('TIME', axis=1)

    solar_cols = ['B3_QSEXT','B3_QBGSHD','B3_QBFRM','B3_QBREFG','B3_QBABSG','B3_QSHFPR','B3_QSTRNS','B3_QISHVOUT']
    gtot_cols = ['gtot', 'fc_Gshade', 'fc_Eshade', 'gframe', 'gglas', 'fc_Ishade','fc_Ishade']
    positive_value_cols = gtot_cols.copy()
    positive_value_cols.extend(['TIME','Rel_BAL3','B3_QBAL','B3_QSEXT','AI'])

    # Reverse the sign of values in columns whose names do not contain "B3_QSEXT".
    for col in df.columns:
        if  not any(name in col for name in positive_value_cols):
            df[col] = -df[col]

    fig = make_subplots(
                        rows=3, cols=1, 
                        shared_xaxes=True, 
                        vertical_spacing=0.05,
                        row_heights=[0.5, 0.25, 0.25])

    # 1st row
    for col in df.columns:
        if any(name in col for name in solar_cols):
            fig.add_trace(go.Scatter(x=df.index, y=df[col], name=col), row=1, col=1)

    fig.update_yaxes(range=Y_AXIS_RANGE, title_text=Y_AXIS_TITLE, row=1, col=1,
                    exponentformat='none', # disable 'e' notation
                    separatethousands=True # Enable comma
                     )

    # 2nd row
    for col in df.columns:
        if any(name in col for name in gtot_cols):
            fig.add_trace(go.Scatter(x=df.index, y=df[col], name=col), row=2, col=1)

    fig.update_yaxes(range=[0, 1], title_text='g-value [-]', row=2, col=1)

    # 3rd row
    for col in df.columns:
        if 'AI' in col:
            fig.add_trace(go.Scatter(x=df.index, y=df[col], name=col), row=3, col=1)

    fig.update_xaxes(tickformat='%b %d %H:%M', row=3, col=1)
    fig.update_yaxes(range=[0, 90], title_text='Angle of incidence [deg]', row=3, col=1)

    fig.update_layout(height=800, title=FIGURE_TITLE.format(surface_number=surface_number), xaxis_title='DateTime')

    # Show the plot
    fig.show()

    # Save the plot as an HTML file
    fig.write_html(OUTPUT_PATH.format(surface_number=surface_number))

    # 【第39回PYTHON講座】PlotlyのグラフをWordPressで表示(HTML出力)
    # https://opty-life.com/study/program/python/python-lecture-39/
    # 
    # # Save the plot as an HTML file for Wordpress.
    # with open('lightweight_html_for_wordrepss.txt', 'w') as f:
    #     f.write(fig.to_html(include_plotlyjs='cdn',full_html=False))

