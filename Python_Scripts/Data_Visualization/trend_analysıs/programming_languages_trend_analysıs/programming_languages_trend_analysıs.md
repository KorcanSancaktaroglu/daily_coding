# Google Trends: Programming Language Popularity Pipeline

This repository contains an automated Python data pipeline that fetches, analyzes, and visualizes global search interest trends for major programming languages over a 16-year span (2010–2026) using the Google Trends API.

## 📊 Key Insights & Analytics
- **Cross-over Event Detected:** The system dynamically processes the data frame to locate the exact historical moment Python's popularity index overtook Java.
- **Data Cleanup applied:** Handled specific context filtering (e.g., querying `c programming` instead of raw keyword `c` to prevent noise from search trends like Vitamin C).

## 🛠️ Tech Stack & Libraries
- **Language:** Python 3.13
- **Data Sourcing:** `pytrends` (Google Trends API wrapper)
- **Data Manipulation:** `pandas` (DataFrames, masking, conditional filtering)
- **Data Visualization:** `matplotlib` (Time-series plot with customized grid & markers)
- **Data Export:** `openpyxl` / `pandas` (Excel output engine)

## 🚀 Getting Started

### Prerequisites
Ensure you have Python 3.x installed on your environment.

### Installation
1. Clone this repository:
   ```bash
   git clone [https://github.com/YOUR_USERNAME/YOUR_REPO_NAME.git](https://github.com/YOUR_USERNAME/YOUR_REPO_NAME.git)
   cd YOUR_REPO_NAME
