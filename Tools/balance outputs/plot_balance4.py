# coding: utf-8
# Example code to read and plot Energy_zone.BAL.
# author     Yuichi Yasuda @ quattro corporate design
# copyright  2023 quattro corporate design. All right reserved.

import pandas as pd
import re
import plotly.graph_objs as go
from plotly.subplots import make_subplots

# file_path = '.\Project\Energy_zone.BAL'
# # file_path = '.\Energy_zone - summer.BAL'
# output_path = 'balance4_energy_zone.html'

FILE_PATH = r'.\Project\Energy_zone.BAL'  # File path to read
OUTPUT_PATH = 'balance4_energy_zone - Zone no. {selected_group_name}.html'  # html file path to save
FIGURE_TITLE = 'Balance 4 - Sensible energy balance of Zones - Zone no. {selected_group_name}'# Figure title, e.g. 'Energy balance for surface - surface no.0001'
Y_AXIS_RANGE = [-30000, 30000] # Y-axis range, e.g. [-30000, 30000]
Y_AXIS_TITLE = 'Sensible Energy Balance [kJ/h]' # Y-axis title, e.g. 'Energy [kWh]'
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
    # Read the file line by line and apply custom splitting
    with open(FILE_PATH, 'r', encoding='utf-8') as f:
        lines = f.readlines()

    # Extract header and data
    header_line = lines[0].strip().replace('=+', '').replace('=-', '')
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

    # print(df.head())

    # Remove unnecessary symbols from column names
    df.columns = [re.sub(r'[-+=]', '', col) for col in df.columns]

    # substitute 'B4_QCOUP' with '_B4_QCOUP' in column names
    df.columns = [re.sub(r'B4_QCOUP', '_B4_QCOUP', col) for col in df.columns]
    
    # Extracting data excluding the pre-calculation period.
    # In this example, we extract the data after 24h
    df = df[df['TIME'].astype(float) >= PLOT_START_TIME] 

    # Convert TIME column to date/time and set to the Index.
    df.index = pd.to_datetime(df['TIME'], unit='h', origin=DATETIME_ORIGIN)
    

    # Columns to plot
    balance_cols =  ['B4_DQAIRdT', 'B4_QHEAT','B4_QCOOL','B4_QINF','B4_QVENT',
                           'B4_QCOUP','B4_QTRANS','B4_QGINT','B4_QWGAIN','B4_QSOL','B4_QSOLAIR']
    # Columns with positive values
    positive_value_cols = ['TIME', 'REL_BAL_ENERGY', 'B4_QBAL', 'B4_QHEAT','B4_QINF','B4_QVENT',
                           'B4_QCOUP','B4_QTRANS','B4_QGINT','B4_QWGAIN','B4_QSOL','B4_QSOLAIR']

    # Reverse the sign of values in columns containing "B4_QCOOL" in their name
    for col in df.columns:
        if  not any(name in col for name in positive_value_cols):
            df[col] = -df[col]

    # Group columns that start with a number followed by an underscore
    groups = {}
    for col in df.columns:
        match = re.match(r'^(\d+)(_B)?', col)
        if match:
            group_name = match.group(1)
            if group_name not in groups:
                groups[group_name] = []
            groups[group_name].append(col)
    # Ask the user to select a group
    print('Please select a group to plot:')
    for i, group_name in enumerate(groups.keys()):
        print(f'{i+1}. Zone no. {group_name}')
    selection = int(input()) - 1
    selected_group_name = list(groups.keys())[selection]
    selected_group_cols = groups[selected_group_name]

    # Create subplots for the selected group
    fig = make_subplots(rows=1, cols=1, shared_xaxes=True)

    # Plot each column in the selected group
    for col in selected_group_cols:
        if any(name in col for name in balance_cols):
            fig.add_trace(go.Scatter(x=df.index, y=df[col], name=col))

    # Set the title and axis labels
    fig.update_layout(title=FIGURE_TITLE.format(selected_group_name=selected_group_name), xaxis_title='DateTime')
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
    # fig.update_layout(xaxis=dict(rangeslider=dict(visible=True), type='date'))
    # fig.update_layout(xaxis=dict(rangeslider=dict(visible=True), type='date', tickformat='%m/%d %H:%M'))
    fig.update_layout(xaxis=dict(rangeslider=dict(visible=True), type='date', tickformat='%b %d %H:%M'))

    # Show the plot
    fig.show()

    # Save the plot as an HTML file
    fig.write_html(OUTPUT_PATH.format(selected_group_name=selected_group_name))

    # 【第39回PYTHON講座】PlotlyのグラフをWordPressで表示(HTML出力)
    # https://opty-life.com/study/program/python/python-lecture-39/
    # 
    # # Save the plot as an HTML file for Wordpress.
    # with open('lightweight_html_for_wordrepss.txt', 'w') as f:
    #     f.write(fig.to_html(include_plotlyjs='cdn',full_html=False))

