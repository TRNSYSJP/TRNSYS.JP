# coding: utf-8
# Example code to read and plot Energy_zone.BAL.
# author     Yuichi Yasuda @ quattro corporate design
# copyright  2023 quattro corporate design. All right reserved.

import pandas as pd
import re
import glob
import plotly.graph_objs as go
from plotly.subplots import make_subplots

FILE_PATH = r'.\Project\ENERGY_SURF_*.BAL'  # File path to read
OUTPUT_PATH = 'balance6_energy_surf_{surface_number:04d}.html'  # html file path to save
FIGURE_TITLE = 'Balance 6 - Energy balance for surfaces - surface no.{surface_number:04d}' # Figure title, e.g. 'Energy balance for surface - surface no.0001'
Y_AXIS_RANGE = [-30000, 30000] # Y-axis range, e.g. [-30000, 30000]
Y_AXIS_TITLE = 'Energy Balance [kJ/h]' # Y-axis title, e.g. 'Energy [kWh]'
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

    # List all files that match the pattern
    files = glob.glob(FILE_PATH)

    # Print the list of files
    for i, file in enumerate(files):
        print(f"{i+1}. {file}")

    # Ask the user to select a file
    selection = int(input("Select a file to open: ")) - 1

    # Open the selected file
    FILE_PATH = files[selection]

    # Extract the numbers from the file name
    numbers = re.findall(r'\d+', FILE_PATH)
    surface_number = int(numbers[-1])
    # print(f'File no. {numbers}')
    
    # Read the file line by line and apply custom splitting
    with open(FILE_PATH, 'r') as f:
        lines = f.readlines()

    # Extract header and data
    # Remove unnecessary symbols from header_line
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

    # Extracting data excluding the pre-calculation period.
    # In this example, we extract the data after 24h
    # df = df[df['TIME'].astype(float) >= 24]　# 24h以降のデータを抽出
    df = df[df['TIME'].astype(float) >= PLOT_START_TIME] # 0h以降のデータを抽出

    # Convert TIME column to date/time and set to the Index.
    df.index = pd.to_datetime(df['TIME'], unit='h', origin=DATETIME_ORIGIN)
    
    # Drop the TIME column
    df = df.drop('TIME', axis=1)

    # Columns to plot
    energy_cols = ['B6_DQWALLdt','B6_QCOMI','B6_QCOMO','B6_QRADGI','B6_QRADGO','B6_QALG']
    # Columns with positive values
    positive_value_cols = ['REL_BAL_ESurf','B6_BAL','B6_QCOMO','B6_QRADGI','B6_QRADGO']

    # Reverse the sign of values in columns whose names do not contain positive_value_cols.
    for col in df.columns:
        if  not any(name in col for name in positive_value_cols):
            df[col] = -df[col]
    
    # plot the chart
    fig = go.Figure()
    for col in df.columns:
        if any(name in col for name in energy_cols): # plot only energy_cols
            fig.add_trace(go.Scatter(x=df.index, y=df[col], name=col))

    # Set the title and axis labels
    fig.update_layout(title=FIGURE_TITLE.format(surface_number=surface_number), xaxis_title='DateTime')
    # Y-axis values (non-'k' notation, separated by commas)
    fig.update_layout(
        yaxis={
            'title': Y_AXIS_TITLE, # Y-axis title
            'range': Y_AXIS_RANGE, # Y-axis range
            'exponentformat': 'none', # disable 'e' notation
            'separatethousands': True, # Enable comma
            'fixedrange': False # Enable zoom
        }
    )

    # Add a range slider
    # fig.update_layout(xaxis=dict(rangeslider=dict(visible=True), type='date', tickformat='%m/%d %H:%M'))
    fig.update_layout(xaxis=dict(rangeslider=dict(visible=True), type='date', tickformat='%b %d %H:%M'))
    #fig.update_layout(xaxis=dict(rangeslider=dict(visible=True), type='date'))
    

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

