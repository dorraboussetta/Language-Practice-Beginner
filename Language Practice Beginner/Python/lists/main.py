import heart_rates
import metrics

age = metrics.get_age()
mhr = metrics.get_max_heart_rate(age)

days = ["sunday", "monday", "tuesday"]

for day in days: 
    if day == "sunday": 
        heart_data = heart_rates.sunday
    elif day == "monday":
        heart_data = heart_rates.monday
    else:
        heart_data = heart_rates.tuesday

    print (f"Your results for {day} are: ")
    # Rest can be sleep or relaxation (<= 40% maximum heart rate).
    rest_minutes = metrics.count_minutes_in_zone(heart_data, 0, mhr * .4)
    print("Rested for a total of " + str(rest_minutes) + " minutes")
    
    # Vigorous exercise is considered at or above 70% maximum heart rate.
    exercise_minutes = metrics.count_minutes_in_zone(heart_data, mhr * .7, mhr)
    print("In exercise zone for " + str(exercise_minutes) + " minutes")
    
    peak_index = metrics.find_peak_index(heart_data)
    peak_time = metrics.convert_index_to_time(peak_index)
    print("Reached peak heart rate at " + peak_time)
    
    # Sleep session can span from Sunday evening to late Monday morning.
    sleep_session = heart_rates.sunday[1000:] + heart_rates.monday[:700]
    longest_sleep = metrics.find_longest_streak(sleep_session, 0, mhr * .35)
    print("Longest deep sleep lasted " + str(longest_sleep) + " minutes")

    print("----------------------------")
