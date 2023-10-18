# coding: utf-8
# Example code to read and plot Energy_zone.BAL.
# author     Yuichi Yasuda @ quattro corporate design
# copyright  2023 quattro corporate design. All right reserved.

import pandas as pd
import re
import plotly.graph_objs as go

FILE_PATH = r'.\Project\SUMMARY.BAL'  # File path to read
OUTPUT_PATH = 'balance9_summary.html'  # html file path to save
FIGURE_TITLE = 'Balance 9 - Summary, Energy balance per zone and Sum of all zones' # Figure title, e.g. 'Energy balance for surface - surface no.0001'
X_AXIS_TITLE = 'Zones' # X-axis title, e.g. 'DateTime'
# Y_AXIS_RANGE = [-30000, 30000] # Y-axis range, e.g. [-30000, 30000]
Y_AXIS_TITLE = 'Energy Balance [kJ/h]' # Y-axis title, e.g. 'Energy [kWh]'
#PLOT_START_TIME = 0 # Plot start time [h], e.g. 0
#DATETIME_ORIGIN = '2021-01-01' # Calendar start date other than leap years, e.g. '2021-01-01'

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

    # Remove the first two lines
    lines = lines[2:]

    # Extract zone data and sum data
    zone_lines = []
    sum_lines = []
    zone_flag = True

    for line in lines:
        if 'Energy balance for sum of all zone' in line:
            zone_flag = False
            continue
        if zone_flag: 
            # Energy balance per Zone.
            zone_lines.append(line)
        else:
            # Energy balance for sum of all zone.
            sum_lines.append(line)

    # Extract header and data
    header_line = zone_lines[0].strip().replace('=', ' ').replace('+', ' ').replace('-', ' ')
    unit_line = zone_lines[1].strip()
    data_lines = zone_lines[2:]

    # Create DataFrame
    header = custom_split(header_line)
    units = custom_split(unit_line)
    data = [custom_split(line.strip()) for line in data_lines]

    # Convert to DataFrame
    df = pd.DataFrame(data, columns=header)

    df_sum = pd.DataFrame([custom_split(sum_lines[0].strip())], columns=header)
    # print(df_sum.head(10))

    # Concatenate df and df_sum
    df_all = pd.concat([df, df_sum], ignore_index=True)
    # print(df_all.head(10))

    # Convert all columns to float
    df_all = df_all.astype(float)
    # print(df.head(10))

    # Columns to plot
    balance_cols = ['DQAIRdt','QHEAT','QCOOL','QINF','QVENT','QCOUPL','QTRANS','QGAININT','QWGAIN','QSOLGAIN','QSOLAIR']
    # Columns with positive values
    positive_value_cols = ['Zonenr','Rel_BAL','BAL_ENERGY','QHEAT','QINF','QVENT','QCOUPL','QTRANS','QGAININT','QWGAIN','QSOLGAIN','QSOLAIR']
   

    # Reverse the sign of values in columns containing "DQAIRdt" or "QCOOL" in their name
    for col in df_all.columns:
        if  not any(name in col for name in positive_value_cols):
        # if 'DQAIRdt' in col or 'QCOOL' in col:
            df_all[col] = -df_all[col]

    # # remove unused columns from the df_all
    # df_all2= df_all.drop('Zonenr', axis=1)  
    # df_all2 = df_all2.drop('Rel_BAL', axis=1)
    # df_all2 = df_all2.drop('BAL_ENERGY', axis=1)

    # plot the chart
    fig = go.Figure()
    zone_list = ['Zone no. ' + str(int(zone)) for zone in df['Zonenr']]
    zone_list.append('sum of all zone')

    # Create a bar chart for each column
    for col in df_all.columns:
        if any(name in col for name in balance_cols): # plot only balance_cols
            # fig.add_trace(go.Bar(name=str(col),x=zone_list, y=df[col], hovertemplate='%{x}: %{y} (%{name})'))
            fig.add_trace(go.Bar(name=str(col),x=zone_list, y=df_all[col], text=str(col), textposition='auto'))

    fig.update_layout(
        title=FIGURE_TITLE,
        xaxis={
            'title': X_AXIS_TITLE,
 
        },
        yaxis={
            'title': Y_AXIS_TITLE,
            # 'range': [-30000, 30000], # Y-axis range
            'exponentformat': 'none', # disable 'e' notation
            'separatethousands': True # Enable comma
        },  
        barmode='relative',
    )

    fig.update_traces(hovertemplate='%{x}: %{y}')
    
    # Show the plot
    fig.show()

    # Save the plot as an HTML file
    fig.write_html(OUTPUT_PATH)

    # 【第39回PYTHON講座】PlotlyのグラフをWordPressで表示(HTML出力)
    # https://opty-life.com/study/program/python/python-lecture-39/
    # 
    # # Save the plot as an HTML file for Wordpress.
    # with open('lightweight_html_for_wordrepss.txt', 'w') as f:
    #     f.write(fig.to_html(include_plotlyjs='cdn',full_html=False))

