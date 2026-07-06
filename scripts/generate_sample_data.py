from datetime import date, timedelta
import random

start = date(2010, 1, 1)
rows = []
price = 100.0
for i in range(10000):
    while start.weekday() >= 5:
        start += timedelta(days=1)
    open_p = price * (1 + random.uniform(-0.01, 0.01))
    high_p = open_p * (1 + random.uniform(0.0, 0.015))
    low_p = open_p * (1 - random.uniform(0.0, 0.015))
    close_p = random.uniform(low_p, high_p)
    volume = random.randint(100000, 1000000)
    rows.append((start.isoformat(), open_p, high_p, low_p, close_p, volume))
    price = close_p
    start += timedelta(days=1)
with open('data/sample_ohlcv.csv', 'w') as f:
    f.write('date,open,high,low,close,volume\n')
    for row in rows:
        f.write(','.join([row[0], f'{row[1]:.2f}', f'{row[2]:.2f}', f'{row[3]:.2f}', f'{row[4]:.2f}', str(row[5])]) + '\n')
print(f'Created data/sample_ohlcv.csv with {len(rows)} rows')
