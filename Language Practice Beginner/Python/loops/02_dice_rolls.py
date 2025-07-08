# This is a dice rolls program challenge in Khan Academy.
# I was given 6 lines and asked to complete the code per some instructions.
# Purpose: Practicing using loops.
# What I learned:
# - try/except
# - I used the loop function in a new way this time.

import random

num_rolls = 0
sum_all_rolls = 0
requested_sum = int(input("What sum total do you want to reach? "))

# Asks the user for the number of dice they want to roll.
# Then makes sure that the user only enters a strictly positive integer.
while True: 
    print("How many dice do you want to roll?")
    num_dice = input("Please enter a positive integer: ")
    try: 
        num_dice = int(num_dice)
        if num_dice > 0:
            break 
        else:
            print("The number must be greater than 0.")
    except ValueError:
        print("That is not a valid integer. Please try again.")


# Rolling the requested number of dice.
while sum_all_rolls < requested_sum: 
    num_rolls += 1
    dice_rolled = 0
    dice_sum = 0
    while dice_rolled < num_dice:
        dice_rolled += 1
        die_value = random.randint(1, 6)
        print("Dice " + str(dice_rolled) + ": " + str(die_value))
        dice_sum += die_value

    # The total sum of rolls could go over the requested sum.
    # This part asks the user if they want to continue rolling. 
    if requested_sum - sum_all_rolls < num_dice * 6:
        prompt_user = input("Your total sum so far is " + 
                            str(sum_all_rolls) +  
                            ". You could go over the total. " + 
                            "Continue? (yes/no) ")
        if prompt_user == "no":
            break
            
    
    # Making sure the grammar's correct in the output.
    if dice_sum in (8, 11): 
        print("You rolled an " + str(dice_sum) + "!")
    else: 
        print("You rolled a " + str(dice_sum) + "!")
    sum_all_rolls += dice_sum

# Calculating the average sum of each roll.
average = sum_all_rolls / num_rolls
average = round(average, 2)

# Printing the number of rolls, the requested sum, and the average.
print("You rolled " + str(num_rolls) + 
      " times to get to a total sum of " + str(sum_all_rolls) + "!")
print("The average of all rolls is: " + str(average))
