"""Analyzes heart rate patterns in readings measured once per minute."""

def count_minutes_in_zone(heart_rates, zone_min, zone_max):
    """Returns the total minutes with a heart rate within the zone bounds."""
    minutes = 0
    for rate in heart_rates: 
        if zone_min <= rate <= zone_max:
            minutes += 1
    return minutes

def find_peak_index(heart_rates):
    """Returns the index of the highest heart rate in the given list."""
    previous_rate = 0
    peak_rate = 0
    peak_index = -1
    for i in range(len(heart_rates)):
        if heart_rates[i] > previous_rate and heart_rates[i] > peak_rate:
            peak_rate = heart_rates[i]
            peak_index = i
        previous_rate = heart_rates[i]
    
    return peak_index

def find_longest_streak(heart_rates, zone_min, zone_max):
    """Returns the duration of the longest consecutive period in the zone."""
    i = 0 
    highest_streak = 0
    while i < len(heart_rates):
        new_streak = 0
        
        if not (zone_min <= heart_rates[i] <= zone_max):
            i+= 1
            continue 
        while i < len(heart_rates):
            if zone_min <= heart_rates[i] <= zone_max:
                new_streak += 1
                i += 1
            else:
                break

        
        if new_streak > highest_streak: 
            highest_streak = new_streak
        
    
    return highest_streak

def get_max_heart_rate(age):
    """Estimates the highest heart rate a person should reach based on age."""
    return 208 - (0.7 * age)

def convert_index_to_time(index):
    """Converts the given index to a clock time, where index 0 is 0:00."""
    hour = index // 60
    minutes = round(index % 60)

    # Add a leading zero if the minute is a single digit.
    minute_string = str(minutes)
    if len(minute_string) == 1:
       minute_string = "0" + minute_string

    return str(hour) + ":" + minute_string

def get_age():
    """Returns a valid age."""
    print("How old are you? ")

    while True:
        try: 
            age = int(input("Please enter your age here: "))
            if age > 0: 
                return age 
            else: 
                print("That's not a valid age number.")
        except ValueError:
            print("That's not a number.")
            
