# Quant Project: C++ Backtesting Engine

This project is a simple algorithmic trading backtesting engine written in C++. It reads historical OHLCV market data, simulates trading strategies over time, evaluates portfolio performance, and exports the results as CSV files.

## What this project does

The project helps you answer one main question:

> If I had followed a trading rule in the past, how would my portfolio have performed?

It does this by:

- loading historical stock price data from a CSV file,
- applying trading strategies to that data,
- simulating buys and sells over time,
- tracking portfolio equity,
- calculating performance metrics,
- exporting results for analysis.

## What the project includes

The project currently supports two basic trading strategies:

1. SMA Crossover
   - Uses a short-term moving average and a long-term moving average.
   - Buys when the short moving average crosses above the long moving average.
   - Sells when the short moving average crosses below the long moving average.

2. RSI Mean Reversion
   - Uses the Relative Strength Index (RSI).
   - Buys when RSI becomes oversold.
   - Sells when RSI becomes overbought.

## How it works

The workflow is simple:

1. Load data
   - The program reads a CSV file containing historical OHLCV data.
   - Each row represents one time period, such as one day.

2. Run a strategy
   - For each bar in the dataset, the strategy decides whether to buy, sell, or hold.

3. Simulate trades
   - The backtester executes trades using the next available price.
   - The portfolio keeps track of cash, shares, and equity.

4. Measure performance
   - After the simulation, the project calculates key performance metrics.

5. Export results
   - The results are written to CSV files in the results folder.

## Input data format

The input file should be a CSV file with this structure:

```csv
date,open,high,low,close,volume
2020-01-02,100.00,102.00,99.50,101.20,1500000
```

Each column means:

- date: the trading date
- open: opening price
- high: highest price of the day
- low: lowest price of the day
- close: closing price
- volume: traded volume

## What the project calculates

The program calculates several common trading performance metrics:

### Total Return
This shows the overall gain or loss of the portfolio over the full simulation period.

- Example: if the portfolio grew from $100,000 to $120,000, the total return is 20%.

### Annualized Return
This converts the total return into a yearly rate.

It helps compare performance across periods of different lengths.

### Sharpe Ratio
This measures risk-adjusted return.

A higher Sharpe ratio generally means better return for the amount of risk taken.

- A Sharpe ratio above 1 is often considered good.
- A ratio below 1 may be considered weak.

### Maximum Drawdown
This measures the largest loss from a peak to a later trough.

It shows how much the portfolio could have fallen during a bad period.

### Total Trades
This is the number of trades executed during the simulation.

### Winning Trades
This is how many trades ended in profit.

### Win Rate
This is the percentage of trades that were profitable.

## Important note about the numbers

The metrics are based on a simple simulation and not a fully realistic trading environment.

This project does not include:

- transaction costs,
- slippage,
- taxes,
- market impact,
- real-world order execution delays.

So the results are best used for learning and comparing strategies, not for live trading decisions.

## Folder structure

```text
.
├── data/
│   └── sample_ohlcv.csv
├── results/
├── scripts/
│   └── generate_sample_data.py
├── src/
│   ├── Backtester.cpp
│   ├── Backtester.h
│   ├── CSVExporter.cpp
│   ├── CSVExporter.h
│   ├── DataLoader.cpp
│   ├── DataLoader.h
│   ├── main.cpp
│   ├── Metrics.cpp
│   ├── Metrics.h
│   ├── Portfolio.cpp
│   ├── Portfolio.h
│   ├── RSIStrategy.cpp
│   ├── RSIStrategy.h
│   ├── SMAStrategy.cpp
│   ├── SMAStrategy.h
│   ├── Strategy.h
│   └── Types.h
├── Makefile
└── README.md
```

## How to run the project

### Prerequisites

You need:

- a C++ compiler such as g++
- Python 3

### Run with one command

From the project folder, run:

```bash
make run
```

This command will:

1. compile the C++ program,
2. generate sample data if it does not already exist,
3. run the backtest,
4. write outputs to the results folder.

### Manual run

If you want to run it manually:

```bash
g++ -std=c++17 -O2 -Wall -Wextra src/*.cpp -o src/main
./src/main data/sample_ohlcv.csv results
```

## Output files

The program writes these files into the results folder:

- equity curve CSV for each strategy
- trade log CSV for each strategy
- summary CSV with all key metrics

## Why this project is useful

This project is a good beginner-friendly example of:

- object-oriented programming in C++,
- strategy pattern design,
- backtesting logic,
- portfolio simulation,
- financial metric calculation,
- CSV export and data analysis.

## Summary

In short, this project is a small educational trading simulator that shows how historical market data can be used to test simple investment rules and evaluate how they might have performed.
