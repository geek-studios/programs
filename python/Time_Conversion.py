#Given a time in 12-hour AM/PM format, convert it to military (24-hour) time.
print("Enter time in 12:01:00PM format:")
time = input().strip()
h, m, s = map(int, time[:-2].split(':'))
p = time[-2:]
h = h % 12 + (p.upper() == 'PM') * 12
print(('%02d:%02d:%02d') % (h, m, s))