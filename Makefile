CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra
SRC = src/main.cpp src/Backtester.cpp src/DataLoader.cpp src/CSVExporter.cpp src/Metrics.cpp src/Portfolio.cpp src/RSIStrategy.cpp src/SMAStrategy.cpp
TARGET = src/main
DATA = data/sample_ohlcv.csv
RESULTS = results

.PHONY: all build run sample clean

all: build

build: $(TARGET)

$(TARGET): $(SRC)
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $^ -o $@

run: build sample
	mkdir -p $(RESULTS)
	./$(TARGET) $(DATA) $(RESULTS)

sample: $(DATA)

$(DATA): scripts/generate_sample_data.py | data
	python3 $<

data:
	mkdir -p data

clean:
	rm -f $(TARGET)
