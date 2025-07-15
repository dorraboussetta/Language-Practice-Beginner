import typer

print("Game rule: " + 
      "Type the words and hit enter within the time limit!")

# Asking the user to choose the difficulty level.
difficulty_level = typer.choose_difficulty()

# Choosing the appropriate level based on the difficulty level.
current_level = typer.choose_current_level(difficulty_level)

# Each round is 10 seconds long by default.
# There are two round durations: 10s and 8s.
# The user can choose the round duration before the game and when it restarts.
seconds = typer.choose_round_duration()

total_score = 0


# Main game loop: handles levels, tries, scoring, and difficulty progression.
while True: 
    # The loop exits when there are no more levels to play.
    while current_level <= 6 :
        print(f"Onto level {current_level}! ")
    
        tries = 1
        # The user is allowed 3 tries per level before the game end.
        while tries <= 3:
            passed = typer.wins_level(seconds, difficulty_level, current_level)
            if passed: 
                print(f"You nailed level {current_level}!") 
                total_score += 1
                print(f"Total score: {total_score}!")
                print("-------------------------")
                break
            else: 
                if tries < 3: 
                    print(f"Ooops! Let's try level {current_level} again!")
                    tries += 1
                    
                else: 
                    print("You have no more tries left!")
                    break
            
        # Leveling up the user who passed the current level. 
        if passed and current_level != 6:
        
            if difficulty_level != "hard" and current_level in (2, 4):
                difficulty_level = typer.level_up_difficulty(difficulty_level)
    
            current_level += 1
        else: 
            # The loop exits when there are no more levels to play.
            if current_level == 6 and passed:
                print ("You finished the game!")
                break
            # The loop exits when the user ran out of tries.
            elif  not passed and tries <= 3: 
                 break 
        
    
    # Printing the total score.
    print("Your total score is: " + str(total_score))
    print("Thanks for playing!")
    print("----------------------")
    
    # The game restarts if desired by the user.
    print("Do you want to play the game again?")
    again = typer.get_yes_or_no()
    if again == "yes":

        # Resetting the game back to level 1 if the user wants to.
        print("Do you want to try the same level?")
        same_level = typer.get_yes_or_no()
        if same_level == "no":
            current_level = 1
            difficulty_level = "easy"
            total_score = 0
        else: 
            print(f"Your total score remains {total_score}.")
            print(f"You're restarting level {current_level}. ")
        
        seconds = typer.new_round_duration(seconds)
        print("-------------------------")
    else: 
        #Ending the program if the user wants to quit.
        print("Alright! Please come again!")
        break 
