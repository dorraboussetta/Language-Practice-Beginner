# This program asks the user about a waste item (material type, size, and condition)
# and classifies it as trash, recycling, or compost based on simple sorting rules.
# Special rules are applied for yogurt cups and pizza boxes.

# Setting the standard value of waste_type to trash
waste_type = "trash"

# Getting all the inputs needed from the user 
# I'm asking about the material type and length if applicable.
# We don't need to know the dimensions of the compost.
material = input("What material is it (paper, plastic, or compost)? ")
material = material.lower()
if material != "compost":
    length = float(input("What is its length in cm? "))
    width = float(input("What is its width in cm? "))


# If the material is plastic, then it is recycled.
if material == "plastic":  
    # The min length of the plastic object is 7.5, its min width is 5.
    if length >= 7.5 and width >= 5: 
        waste_type = "recycling"
        # If the object is a rinsed yogurt cup, then it gets recylcled.
        is_yogurtcup = input("Is it a yogurt cup? Answer yes or no: ")
        is_yogurtcup = is_yogurtcup.lower()
        if is_yogurtcup == "yes":
            # If the object is an unrinsed yogurt cup, then it goes to trash.
            is_rinsed = input("Is it rinsed? Answer with yes or no: ")
            is_rinsed = is_rinsed.lower()
            if is_rinsed == "no": 
                waste_type = "trash"
            
# Papers are recycled if their lengths and widths are 5cm or more.
if material == "paper":
    if length >= 5 and width >= 5: 
        waste_type = "recycling"
        is_pizzabox = input("is it a pizza box? Answer with yes or no: ")
        is_pizzabox = is_pizzabox.lower() 
        if is_pizzabox == "yes": 
            # Only non-greasy pizzza boxes are recycled. 
            greasy_box = input("Is it greasy? Answer with yes or no: ")
            greasy_box = greasy_box.lower()
            if greasy_box == "yes": 
                waste_type = "trash"

# Compost goes to the compost bin.
if material == "compost":
    waste_type = "compost"

print("Please deposit your item in the " + waste_type + " bin.")
