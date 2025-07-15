"""Plays a game where the user types random words within a time limit."""

import random
import time
import word_bank

def wins_level(seconds, difficulty_level, current_level):
    """ Returns true if the user won the level."""
    round_num = 0

    if current_level % 2 != 0: 
        num_words = 1
    else:
        num_words = 3
        
    for i in range(num_words, num_words + 3):
        round_num += 1
        print("Round " + str(round_num))
        
        words_to_type = pick_random_words(i, difficulty_level)
        passed = play_round(words_to_type, seconds)
        if not passed:
            return False
        elif i < num_words +2:
            continue
        else:
            return True 
    

def play_round(words, seconds):
    """Returns True if the user successfully completed the round."""
    # Run a stopwatch for the time it takes the user to respond.
    start = time.time()
    response = input("(" + str(seconds) + " seconds) " + words + "\n")
    response = response.lower().strip()
    stop = time.time()

    # Fail the round if a word is mispelled or if time runs out.
    within_time_limit = stop - start < seconds
    return response == words and within_time_limit

def pick_random_words(num_words, difficulty):
    """Returns a random phrase containing the given number of words.""" 
    words = ""
    for word in range(num_words):
        word = get_random_word(difficulty)
        words = words + " " + word

    return words.strip()

def get_random_word(mode):
    """Returns a random word with a word length based on the given mode."""
    if mode == "hard":
        words = word_bank.hard_words
    elif mode == "medium":
        words = word_bank.medium_words
    else:
        words = word_bank.easy_words

    return random.choice(words)

def new_round_duration(seconds):
    """ Changes the round duration per user preference.""" 
    if seconds == 10: 
        print("You can play each round for 8 seconds this time! " + 
             "Would you like to try that? ")
        answer = get_yes_or_no()
    
        if answer == "yes":
            return 8
        else: 
            return 10
    else: 
        print("Would you like each round to be 10 seconds long again?")
        answer = get_yes_or_no()

        if answer == "yes":
            return 10
        else: 
            return 8

def choose_round_duration():
    """Returns the round duration chosen by the user."""
    print("Do you want each round duration to be 10 or 8 seconds? ")

    while True:
        try:
            duration = int(input("Please enter 10 or 8: "))
            if duration in (8, 10):
                break 
            else: 
                print("Invalid choice")

        except ValueError:
            print("That's not an integer.")

    return duration

def choose_difficulty():
    """Returns the difficulty level chosen by the user."""
    print("Do you want the easy, medium, or hard mode? ")
    print("Please enter easy, medium, or hard: ")
    difficulty_level = input().lower().strip()
    while difficulty_level not in ("easy", "medium", "hard"):
        difficulty_level = input("Please enter easy, difficult or hard: ")
        difficulty_level = difficulty_level.lower().strip()
        
    return difficulty_level

def choose_current_level(difficulty_level):
    """ Returns the level number based on the difficulty level. """
    if difficulty_level == "easy":
        current_level = 1
    elif difficulty_level == "medium":
        current_level = 3
    else: 
        current_level = 5

    return current_level

def level_up_difficulty(difficulty_level):
    """Returns the new level of difficulty if the user levels up."""
    if difficulty_level == "easy":
        return "medium"
    elif difficulty_level == "medium":
        return "hard"

def get_yes_or_no():
    """Returns yes or no after validating user input."""
    prompt = input("Please answer yes or no: ").lower().strip()
    while prompt not in ("yes", "no"):
        prompt = input("Please answer yes or no: ").lower().strip()

    return prompt

