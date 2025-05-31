# This is a date validation practice exercise from Khan Academy.
# I was given 5 lines of code and I was asked to complete the program.

import sys

day = int(input("Enter a day (1-31): "))
if day < 1 or day > 31:
    print("Error. Day must be between 1 and 31.")
    sys.exit()

month = int(input("Enter a month (1-12): "))
if month < 1 or month > 12: 
    print("Error. Month must be between 1 and 12.")
    sys.exit()

thirty_days_month = month in [4, 6, 9, 11] and day == 31

# This is to account for the months that only have 30 days.
if thirty_days_month:
    print("Error. Day must be within the month. ")
    sys.exit()
    
# This part makes sure that the year entered is realistic.
year = int(input("Enter a year (four digits): "))
current_year = 2025
earliest_year = current_year -120
latest_year = current_year - 15
if not( year >= earliest_year  and year <= latest_year): 
    print("Error. Enter a realistic year.")
    sys.exit()

# This part handles leap years and the number of days in February.
leap_year = (year % 4 == 0 and year % 100 != 0) or year % 400 == 0
if (not leap_year) and month == 2 and day == 29:
    print("Error. February only has 29 days in leap years.")
