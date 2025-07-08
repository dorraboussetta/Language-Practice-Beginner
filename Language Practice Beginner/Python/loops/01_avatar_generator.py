# This program is a challenge in Khan Academy.
# I was given 5 lines and asked to complete the program.
# This program used a module called avatar created by Khan Academy.
# For copyright reasons, I won't post it here, but I will add its link.
"""https://www.khanacademy.org/computing/intro-to-python-fundamentals/x5279a44ae0ab15d6:simulating-phenomena-with-loops/x5279a44ae0ab15d6:module-imports/pc/avatar-generator"""
# Purpose: 
# - Learning how to use two functions from the random module.
# - Learning how to use modules created by someone else.
# What I learned: 
# - How to use random.randint and random.choice.
# - How to use modules created by someone else.
# What's next:
# - More about loops.
# - How to create functions.
#   Then I'll add functions to this program to remove some repetitions.

import avatar
import random

# Asks how many players are joining.
# Used to determine whether to generate a second avatar. 
num_players = input("How many players are joining(1, 2)? ").lower().strip()
while num_players not in ("1", "2"):
    num_players = input("Please enter 1 or 2: ").lower().strip()
num_players = int(num_players)

# Asking if player 1 wants a custom avatar.
custom_avatar_p1 = input("Do you want a custom avatar (yes, no)? ")
custom_avatar_p1 = custom_avatar_p1.lower().strip()
while custom_avatar_p1 not in ("yes", "no"): 
    custom_avatar_p1 = input("Please enter yes, or no: ").lower().strip()

# Getting the user's custom choices if they want a custom avatar.
if custom_avatar_p1 == "yes":
    # Getting the user's nose shape choice.
    nose_shape_p1 = input("Select the nose shape(button, triangle): ")
    nose_shape_p1 = nose_shape_p1.lower().strip()
    while nose_shape_p1 not in ("button", "triangle"):
        nose_shape_p1 = input("Please enter button or triangle: ")
        nose_shape_p1 = nose_shape_p1.lower().strip()

    # Getting the user's mouth shape choice.
    print("Please select the mouth shape(smile, teeth, neutral): ")
    mouth_shape_p1 = input()
    mouth_shape_p1 = mouth_shape_p1.lower().strip()
    while mouth_shape_p1 not in ("smile", "teeth", "neutral"):
        mouth_shape_p1 = input("Please select smile, teeth, or neutral: ")

    # Asking for the bow location. 
    bow_location_p1 = ""
    print("Please select one bow location option(in lowercase): ")
    print("1. forehead")
    print("2. neck")
    print("3. No bow")
    bow_location_p1 = input("Enter your selection here: ").lower().strip()
    while bow_location_p1 not in ("forehead", "neck", "no bow"):
        bow_location_p1 = input("Please enter one of the three options: ")
        bow_location_p1 = bow_location_p1.lower().strip()

print("-----------------------------")
if num_players == 2:
    print("Player 1's avatar: ")
    
# Randomly setting the nose shape if the user does not want a custom choice.
if custom_avatar_p1 == "no": 
    nose_shape_number = random.randint(1, 2)
    if nose_shape_number == 1:
        nose_shape_p1 = "triangle"
    else:
        nose_shape_p1 = "button"

    # Randomly determining the mouth shape. 
    mouth_shape_p1_number = random.randint(1, 4)
    if mouth_shape_p1_number == 1:
        mouth_shape_p1 = "teeth"
    elif mouth_shape_p1_number == 3:
        mouth_shape_p1 = "neutral"
    else:
        mouth_shape_p1 = "smile"

    # Randomly determining the location of the bow, then displaying the avatar.
    bow_location_p1_number = random.randint(1, 3)
    if bow_location_p1_number == 1:
        bow_location_p1 = "forehead"
        avatar.draw_bow()
        avatar.draw_eyes("medium")
        avatar.draw_nose(nose_shape_p1)
        avatar.draw_mouth(mouth_shape_p1)
    elif bow_location_p1_number == 2:
        bow_location_p1 = "neck"
        avatar.draw_eyes("medium")
        avatar.draw_nose(nose_shape_p1)
        avatar.draw_mouth(mouth_shape_p1)
        avatar.draw_bow()
    else:
        bow_location_p1 = "no bow"
        avatar.draw_eyes("medium")
        avatar.draw_nose(nose_shape_p1)
        avatar.draw_mouth(mouth_shape_p1)

# Drawing the avatar using the user's custom inputs.
if custom_avatar_p1 == "yes":
    if bow_location_p1 == "forehead":
        avatar.draw_bow()
        avatar.draw_eyes("medium")
        avatar.draw_nose(nose_shape_p1)
        avatar.draw_mouth(mouth_shape_p1)
    elif bow_location_p1 == "neck":
        avatar.draw_eyes("medium")
        avatar.draw_nose(nose_shape_p1)
        avatar.draw_mouth(mouth_shape_p1)
        avatar.draw_bow()
    else:
        avatar.draw_eyes("medium")
        avatar.draw_nose(nose_shape_p1)
        avatar.draw_mouth(mouth_shape_p1)

print("-----------------------------")


# Asking if player 2 wants to choose their avatar. 
custom_avatar_p2 = input("Do you want a custom avatar (yes, no)? ")
custom_avatar_p2 = custom_avatar_p2.lower().strip()
while custom_avatar_p2 not in ("yes", "no"): 
    custom_avatar_p2 = input("Please enter yes, or no: ").lower().strip()

# Choosing Player 2's avatar's traits randomly.
if num_players == 2:
    if custom_avatar_p2 == "no":
        print("Player 2's avatar: ")
        # Player 2's avatar gets the ramaining nose shape.
        if nose_shape_p1 == "button":
            nose_shape_p2 = "triangle"
        else:
            nose_shape_p2 = "button"
    
        # Player 2's randomly avatar gets one of the remaining mouth shapes.
        if mouth_shape_p1 == "smile":
            mouth_shape_p2 = random.choice(("teeth", "neutral"))
        elif mouth_shape_p1 == "neutral":
            mouth_shape_p2 = random.choice(("smile", "teeth"))
        else:
            mouth_shape_p2 = random.choice(("smile", "neutral"))
    
        # Player 2's avatar randomly gets one of the remaining bow locations.
        if bow_location_p1 == "forehead":
            bow_location_p2 = random.choice(("neck", "no bow"))
        elif bow_location_p1 == "neck":
            bow_location_p2 = random.choice(("forehead", "no bow"))
        elif bow_location_p1 == "no bow":
            bow_location_p2 = random.choice(("neck", "forehead"))
    else:
        # There is only one nose shape choice left.
        if nose_shape_p1 == "button":
            nose_shape_p2 = "triangle"
        else:
            nose_shape_p2 = "button"
        print("There is only one nose shape choice left: " + nose_shape_p2)

        # Asking player 2 to choose one of the remaining mouth shape choices.
        if mouth_shape_p1 == "smile":
            mouth_shape_p2 = input("Choose a mouth shape(teeth, neutral): ")
            mouth_shape_p2 = mouth_shape_p2.lower().strip()
            while mouth_shape_p2 not in ("teeth", "neutral"):
                mouth_shape_p2 = input("Please choose teeth or neutral: ")
        elif mouth_shape_p1 == "neutral":
            mouth_shape_p2 = input("Choose a mouth shape(teeth, smile): ")
            mouth_shape_p2 = mouth_shape_p2.lower().strip()
            while mouth_shape_p2 not in ("teeth", "smile"):
                mouth_shape_p2 = input("Please choose teeth or smile: ")
        else:
            mouth_shape_p2 = input("Choose a mouth shape(smile, neutral): ")
            mouth_shape_p2 = mouth_shape_p2.lower().strip()
            while mouth_shape_p2 not in ("smile", "neutral"):
                mouth_shape_p2 = input("Please choose smile or neutral: ")
                
        # Asking player 2 to choose one of the remaining bow locations.
        if bow_location_p1 == "forehead":
            print("Choose a bow location: neck or no bow ")
            bow_location_p2 = input("Here: ").lower().strip()
            while bow_location_p2 not in ("neck", "no bow"):
                bow_location_p2 = input("Please enter neck or no bow: ")
                bow_location_p2 = bow_location_p2.lower().strip()
        elif bow_location_p1 == "neck":
            print("Choose a bow location: forehead or no bow ")
            bow_location_p2 = input("Here: ").lower().strip()
            while bow_location_p2 not in ("forehead", "no bow"):
                bow_location_p2 = input("Please enter forehead or no bow: ")
                bow_location_p2 = bow_location_p2.lower().strip()
        elif bow_location_p1 == "no bow":
            print("Choose a bow location: neck or forehead ")
            bow_location_p2 = input("Here: ").lower().strip()
            while bow_location_p2 not in ("neck", "forehead"):
                bow_location_p2 = input("Please enter neck or forehead: ")
                bow_location_p2 = bow_location_p2.lower().strip()


# Printing out Player 2's avatar if needed.
if num_players == 2:
     if bow_location_p2 == "forehead":
        avatar.draw_bow()
        avatar.draw_eyes("medium")
        avatar.draw_nose(nose_shape_p2)
        avatar.draw_mouth(mouth_shape_p2)
     elif bow_location_p2 == "neck":
        avatar.draw_eyes("medium")
        avatar.draw_nose(nose_shape_p2)
        avatar.draw_mouth(mouth_shape_p2)
        avatar.draw_bow()
     elif bow_location_p2 == "no bow": 
        avatar.draw_eyes("medium")
        avatar.draw_nose(nose_shape_p2)
        avatar.draw_mouth(mouth_shape_p2)
    
    
