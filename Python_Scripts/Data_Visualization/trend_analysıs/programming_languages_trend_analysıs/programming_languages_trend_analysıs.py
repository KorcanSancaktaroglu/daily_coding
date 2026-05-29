"""
========================================================================
PROGRAMMING LANGUAGE TRENDS ANALYSIS
Data Sourcing, Processing & Visualization Pipeline
========================================================================

DESCRIPTION:
This script programmatically fetches historical search interest data from 
Google Trends via the Pytrends API for major programming languages. 
It analyzes the trend dynamics using Pandas, identifies the exact historical 
cross-over point where Python overtook Java, saves the raw dataset to Excel, 
and generates a publication-quality visualization using Matplotlib.

DEPENDENCIES:
- pandas
- matplotlib
- pytrends
- openpyxl (for Excel exportation)

TIME COMPLEXITY  : O(N) for data transformations and visualization parsing.
SPACE COMPLEXITY : O(N) where N is the number of data points retrieved.
========================================================================
"""

import pandas as pd 
import matplotlib.pyplot as plt
from pytrends.request import TrendReq as pt

def run_trend_analysis():
    print("Starting analysis, fetching Google Trends data...")
    
    # 1. Initialize Google Trends API connection
    pytrends = pt()
    
    # 2. Keywords to compare (Cleaned data context)
    kw_list = ["python", "java", "javascript", "visual basic", "c programming"]
    
    # 3. Configure API parameters
    pytrends.build_payload(kw_list=kw_list, timeframe='2010-01-01 2026-05-29')
    
    # 4. Fetch time-series data
    df = pytrends.interest_over_time()
    
    if df.empty:
        print("Error: Failed to fetch data. Please check your internet connection or API limits.")
        return

    # 5. Save cleaned data to disk in Excel format
    excel_filename = "us_prog_lang_trends.xlsx"
    df.to_excel(excel_filename)
    print(f"-> Raw data successfully saved: '{excel_filename}'")
    
    # 6. Algorithmic Analysis: Find the exact moment Python overtook Java
    try:
        crossover_condition = df['python'] >= df['java']
        crossover_date = df[crossover_condition].index[0]
        formatted_date = crossover_date.strftime('%d-%m-%Y')
        print(f"\n[ANALYSIS RESULT] The first date Python dethroned Java: {formatted_date}\n")
    except IndexError:
        print("\n[ANALYSIS RESULT] Python did not overtake Java in the specified timeframe.\n")

    # 7. Matplotlib Data Visualization Pipeline
    print("Generating chart...")
    plt.figure(figsize=(18, 8))
    
    # Plot time-series for each language (Marker: Star)
    plt.plot(df.index, df['python'], 'k*', label='Python')
    plt.plot(df.index, df['java'], 'r*', label='Java')
    plt.plot(df.index, df['javascript'], 'b*', label='JavaScript')
    plt.plot(df.index, df['visual basic'], 'g*', label='Visual Basic')
    plt.plot(df.index, df['c programming'], 'm*', label='C')
    
    # Chart Design and Aesthetic Configuration
    plt.title("Global Programming Language Trend Analysis (2010 - 2026)", fontsize=16, fontweight='bold', pad=15)
    plt.xlabel("Year", fontsize=12, fontweight='bold')
    plt.ylabel("Search Interest (Normalized)", fontsize=12, fontweight='bold')
    plt.legend(loc='upper right', shadow=True, fontsize=10)
    plt.grid(True, linestyle='--', alpha=0.6)
    
    print("Displaying chart...")
    plt.show()

if __name__ == "__main__":
    run_trend_analysis()
