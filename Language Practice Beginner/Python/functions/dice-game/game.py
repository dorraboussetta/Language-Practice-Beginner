"""Supports a round of dice between a user and the computer. 
The user can choose a target score. """

import die

def get_name(total, target_score):
    """Returns the name for the given roll total."""
    if total == target_score:
        return "perfect roll"
    elif total > target_score:
        return "bust"
    else:
        return str(total)

def get_round_winner(user_total, computer_total, target_score):
    """Returns the name of the winner based on the roll totals."""
    
    if computer_total > target_score and user_total > target_score:
        return "no one"
    if computer_total == user_total:
        return "no one"
    elif user_total > target_score:
        return "computer"
    elif computer_total > target_score:
        return "user"
    elif computer_total > user_total:
        return "computer"
    else:
        return "user"

def get_grand_winner(computer_wins_count, user_wins_count):
    """Returns the winner of the whole match, or a tie if there is one."""
    
    if computer_wins_count < user_wins_count:
        return "The user won the match"
    elif computer_wins_count > user_wins_count:
        return "The computer won the match!"
    else: 
        return "it's a tie!"

def play_user_turn(target_score):
    """Plays the user's turn and returns their final roll total."""
    
    total = die.roll()
    while should_user_roll_again(total, target_score):
        total = total + die.roll()

    return total

def play_computer_turn(user_total, target_score):
    """Plays the computer's turn and returns their final roll total."""
    
    total = die.roll()
    while should_computer_roll_again(total, user_total, target_score):
        total = total + die.roll()

    return total

def should_user_roll_again(total, target_score):
    """Prompts the user and returns True if they choose to roll again."""
    
    # Skipping the prompt if they've already reached target score.
    if total >= target_score:
        return False

    display_total = "Your total is " + str(total) + "."
    prompt = "Roll again? (yes/no): "

    roll_again = input(display_total + " " + prompt).lower().strip()
    while roll_again not in ("yes", "no"):
        roll_again = input("Please enter yes or no: ")
        
    return roll_again == "yes"

def should_computer_roll_again(total, user_total, target_score):
    """Returns True if the computer should roll again."""
    
    if user_total > target_score:
        return False
        
    return total < user_total

def choose_target_score():
    """Returns the target score of the user's choosing"""

    # Validating that the user enters an integer >= 21.
    while True:
        try:
            target_score = int(input("Choose a target score (at least 21): "))
            if target_score >= 21:
                return target_score
            else:
                print("Please choose 21 or more.")
        except ValueError:
            print("That's not a integer. Please choose 21 or more.")


    return target_score
