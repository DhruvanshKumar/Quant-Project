#include"CSVExporter.h"
#include<fstream>
#include<iostream>
#include<algorithm>
#include<stdexcept>
using namespace std;

CSVExporter::CSVExporter(const string& outputDir)
    : m_outputDir(outputDir) {}
string CSVExporter::safeFilename(const string& name) {
    string safe = name;
    replace_if(safe.begin(), safe.end(), [](char c){ return c=='(' || c==')' || c==',';},'_');
    return safe;
}
void CSVExporter::exportEquityCurve(const BacktestResult& result) const {
    string path = m_outputDir + "/" + safeFilename(result.strategyName) + "_equity.csv";
    ofstream file(path);
    if (!file.is_open()) {
        throw runtime_error("CSVExporter: cannot write: " + path);
    }
    file << "date, equity \n";
    for (const auto& ep: result.equityCurve) {
        file << ep.date << "," << ep.equity << "\n";
    }
    cout << "[Export] Equity curve ->" << path << "\n";
}
void CSVExporter::exportTradeLog(const BacktestResult& result) const {
    string path = m_outputDir + "/" + safeFilename(result.strategyName) + "_trades.csv";
    ofstream file(path);
    if (!file.is_open()) {
        throw runtime_error("CSVExporter: cannot write: " + path);
    }
    file << "date, action, price, shares, pnl \n";
    for(const auto& t: result.trades){
        string action = (t.action == Signal::BUY) ? "BUY" : "SELL";
        file << t.date << "," << action << "," << t.price << "," << t.shares << "," << t.pnl << "\n";
    }
    cout << "[Export] Trade log ->" << path << "\n";
}
void CSVExporter::exportSummary(const BacktestResult& result, const PerformanceMetrics& metrics) const {
    string path = m_outputDir + "/summary.csv";
    bool needsHeader = false;
    {
        ifstream check(path);
        needsHeader = !check.good();
    }
    ofstream file(path, ios::app);
    if(!file.is_open()) {
        throw runtime_error("CSVExporter: cannot write: " + path);
    }
    if(needsHeader) {
        file<< "strategy, total_return_pct, annualized_return_pct, sharpe_ratio, max_drawdown_pct, total_trades, winning_trades, win_rate_pct \n";
    }
    file << result.strategyName << "," << metrics.totalReturnPct << "," << metrics.annualizedReturnPct << "," << metrics.sharpeRatio << "," << metrics.maxDrawdownPct << "," << metrics.totalTrades << "," << metrics.winningTrades << "," << metrics.winRatePct << "\n";
    cout << "[Export] Summary ->" << path << "\n";
}