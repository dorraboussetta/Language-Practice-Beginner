# This is a python flashcards program challenge from Khan Academy.
# I was given 6 lines and asked to complete the program. 
# Purpose: Practicing using if, elif, and else.
# I wanted to play with the challenge a bit more and added loops to it.
# My goal was to let the user keep trying different answers.
# The user is allowed a different number of tries depending on the question.
# What I learned: How to use "while".
# I also got better at using conditionals and user input.

score = 0
mistake = 0

# First Question.
answer = input("What data type is the value 6.3? ")

# The user can make up to 4 mistakes (1 before the loop + 3 inside).
if answer != "float": 
    mistake += 1
    
# The user already made 1 mistake, this loop allows 3 more tries (total 4).
# The loop stops when the user gets the answer right or when mistake = 4.
while answer != "float" and mistake <= 3:
    if answer == "integer":
        print("Integers can't have decimals. ")
        mistake += 1
        answer = input("Try again: ")
    elif answer == "boolean":
        print("A boolean can only be true or false.")
        mistake += 1
        answer = input("Try again: ")
    elif answer == "string":
        print("This is not a string.")
        mistake += 1
        answer = input("Try again: ")
    else:
        answer = input("Try again: ")
        mistake += 1

# This is to let the user know why they are not getting more prompts.
# If the user made 4 mistakes, that means they never answered "float".
# The loop stops when mistake = 4, which means all tries are used.
if mistake == 4: 
    print("Woops! You're out of tries!")

if answer == "float":
    print("You got it!")
    # Score is incremented by 1 for each correct answer.
    score += 1 
else: 
   print("The correct answer is float. Keep practicing!")

if answer == "float" and  mistake != 0: 
     print("You stuck with it and improved your answer! Great job!")

# Second question.
print("Here's your next question: ")

# Resetting this variable back to 0 for the next question.
mistake = 0

answer = int(input("What does len(\"hi\") evaluate to? "))
if answer != 2: 
    mistake += 1

# The user already made 1 mistake, this loop allows 2 more tries (total 3).
# The loop stops when the answer is right or when mistake = 3.
while answer != 2 and mistake <= 2:
    answer = int(input("Try again: "))
    mistake += 1

# This is to let the user know why they are not getting more prompts.
# If the user made 3 mistakes, that means they never answered 2.
# The loop stops at 3 mistakes, so mistake = 3 means all tries are used.
if mistake == 3: 
    print("Woops! You're out of tries!")
    
if answer == 2:
    print("You got it!")
    score += 1 
else: 
   print("The correct answer is 2. Keep practicing!")

if answer == 2 and  mistake != 0: 
     print("You stuck with it and improved your answer! Great job!")

# Final score after both questions.
print("Your score is: " + str(score))
