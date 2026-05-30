import pandas as pd
from pytrends.request import TrendReq
import time

print("Fetching Google Trends data, please wait...")

# 1. Initialize Pytrends object — with timeout and retry mechanisms
pytrends = TrendReq(
    hl='en-US',
    tz=180,            # Timezone offset (e.g., UTC+3)
    timeout=(10, 25),
    retries=3,
    backoff_factor=0.5
)

# 2. Configure payload — using a short and standard timeframe format
pytrends.build_payload(
    kw_list=['python'],
    timeframe='today 5-y',   # ✅ Safe format
    geo='US'
)

# ==========================================
# RELATED TOPICS
# ==========================================
print("\n--- RELATED TOPICS ---")

try:
    df_rt = pytrends.related_topics()
    python_data = df_rt.get('python')  # ✅ Safe access using .get()

    if python_data is not None:
        rising_df = python_data.get('rising')

        # ✅ Check for both None AND empty DataFrame
        if rising_df is not None and not rising_df.empty:
            print("Fastest Rising Topics:")
            print(rising_df[['topic_title', 'value']].head())
        else:
            print("No rising trend data found for 'python'.")
    else:
        print("Google Trends returned no data for 'python'.")

except Exception as e:
    print(f"Error fetching related topics: {e}")

# Google rate-limit protection
time.sleep(1)

# ==========================================
# RELATED QUERIES
# ==========================================
print("\n--- RELATED QUERIES ---")

try:
    df_rq = pytrends.related_queries()
    python_queries = df_rq.get('python')  # ✅ Safe access using .get()

    if python_queries is not None:
        top_queries = python_queries.get('top')

        # ✅ Check for both None AND empty DataFrame
        if top_queries is not None and not top_queries.empty:
            print("\nTop Queries (Top 5):")
            print(top_queries.head())
        else:
            print("No query data found.")
    else:
        print("No query data returned for 'python'.")

except Exception as e:
    print(f"Error fetching related queries: {e}")
