#pragma once
#include "Types.h"
#include "Strategy.h"
#include "Portfolio.h"
#include<vector>
#include<memory>
using namespace std;

struct BacktestResult {
    string strategyName;
    vector<Trade> trades;
    vector<EquityPoint> equityCurve;
    double initialEquity = 0.0;
    double finalEquity = 0.0;
};
class Backtester {
public:
    explicit Backtester(double initialCash = 100'000.0);
    BacktestResult run(Strategy& strategy, const vector<OHLCV>& data);
private:
    double m_initialCash;
};
