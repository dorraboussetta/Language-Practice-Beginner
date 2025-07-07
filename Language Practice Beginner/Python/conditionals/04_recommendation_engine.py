# This program simulates a questionnaire to recommend a pet for users.
# Purpose: 
# - Practicing using "if", "elif", "else", and "while".
# - Practicing using nested, and compound conditionals.
# What I learned:
# - Practiced if, elif, else, and while loops.
# - Practiced nested and compound conditionals.
# - Practiced input validation and using clear variable names.
# - Learned how to repeat the quiz using a loop.
# - Learned to give variables initial values to prevent crashes.
# Open to feedback.
# Up next: The Loops unit on Khan Academy.

# Printing messages to explain the purpose of the program
print("Welcome to Fluffy Friends shelter!")
print ("This program will help you pick a new pet." )
print("We have cats, dogs, and hamsters.")
print("We just have a few questions to help you pick your pet companion!")
print("Here we go!")
print("------------------------------")

# This loop surrounds the entire quiz.
# The user is given the option to try the quiz again at the end.
while True:
    # Three options are available: cats, dogs, and hamsters.
    # The user is first asked whether they know what pet they want.
    # If the user already knows what they want, we take the input directly.
    print("Do you know what pet you want?")
    knows_what_pet = input("Please enter yes or no: ")
    knows_what_pet = knows_what_pet.lower().strip()
    # Validating the input to ensure it is accurate.
    while knows_what_pet not in ("yes", "no"):
        knows_what_pet = input("Please enter yes or no:").lower().strip()

    # If the user does not know what pet they want, they are asked 3 questions.
    pet_category = ""
    if knows_what_pet == "no":
        # This question is about how much care the pet needs.
        # Dogs are high-maintenance. Cats and hamsters are low-maintenance.
        print("Do you want a high or low maintenance pet?")
        maintenance_level = input("Please enter high or low: ").lower().strip()
        # Validating the input to ensure it is accurate.
        while maintenance_level not in ("high", "low"):
            maintenance_level = input("Please enter high or low: ")
            maintenance_level =  maintenance_level.lower().strip()
            
        # This question asks if the user wants a pet that is cage_confined.
        # Cats and dogs are not confined at home.
        # Hamsters are confined pets.
        print("Do you want a pet that is confined at home?")
        is_confined = input("Please enter yes or no: ")
        # Validating the input to ensure it is accurate.
        while is_confined not in ("yes", "no"):
            is_confined = input("Please enter yes or no: ")
            is_confined = is_confined.lower().strip()
    
        # This question asks if the pet should stay indoors only.
        # Cats and hamsters are considered indoor only pets.
        # Dogs must go outside regularly and can't be indoor-only.
        if is_confined != "yes": 
            print("Do you want an indoor only pet? ")
            indoor_only = input("Please enter yes or no: ")
            # Validating the input to ensure it is accurate.
            while indoor_only not in ("yes", "no"):
                indoor_only = input("Please enter indoor or outdoor:")
                indoor_only = indoor_only.lower().strip()
    else: 
        print("Let us know which pet you want: ")
        pet_category = input("Please enter cat, dog, or hamster: ")
        pet_category = pet_category.lower().strip()
        # Validating the input to ensure it is accurate.
        while pet_category not in ("cat", "dog", "hamster"):
            pet_category = input("Please enter cat, dog, or hamster: ")
            pet_category = pet_category.lower().strip()
             
    # Choosing the pet based on the answers to the three questions.
    if knows_what_pet == "no":
        if maintenance_level == "low" and is_confined == "yes":
            pet_category = "hamster"
            print("A hamster would be perfect for you!")
        elif maintenance_level == "high" and indoor_only == "no":
            pet_category = "dog"
            print("A dog would be perfect for you!")
        elif maintenance_level == "low" and indoor_only == "yes":
            pet_category = "cat"
            print ("A cat would be perfect for you!")
        else: 
            print("We don't have the right pet for you for now!")
    
    print("------------------------------")
    
    # Providing a detailed recommendation based on the pet category.
    # There are two dog subcategories: Large dogs and small dogs.
    # Large dogs are a better fit for homes in rural areas.
    # Small dogs are a better fit for homes in urban areas.
    # There are puppies, adults, and seniors in the dog category.
    if pet_category == "dog":
        living_area = input("Do you live in an urban or a rural area? ")
        living_area = living_area.lower().strip()
        # Validating the input to ensure it is accurate.
        while living_area not in ("urban", "rural"):
            living_area = input("Please enter urban or rural: ")
            living_area = living_area.lower().strip()
        if living_area == "urban":
            dog_size = "small"
        elif living_area == "rural":
            dog_size = "large"
        # There are puppies, adults, and seniors in the dog category.
        dog_age = input("Do you want a puppy, a adult, or a senior dog? ")
        dog_age = dog_age.lower().strip()
        # Validating the input to ensure it is accurate.
        while dog_age not in ("puppy", "adult", "senior"):
            dog_age = input("Please enter puppy, adult, or senior: ")
            dog_age = dog_age.lower().strip()
            
        # The user will now select the breed.
        if dog_size == "large":
            print("Do you want: A husky mix, shepherd mix, or lab mix?")
            dog_breed = input("Enter your choice right here: ").lower().strip()
            # Validating the input to ensure it is accurate.
            while dog_breed not in ("husky mix", "shepherd mix", "lab mix"):
                dog_breed = input("Please enter one of the three choices: ")
                dog_breed = dog_breed.lower().strip()
    
            # Final recommendation based on all user inputs.
            if dog_age == "puppy":
                print ("The right pet for you is a " + dog_breed + " puppy!")
            elif dog_age == "senior":
                print("The right pet for you is a senior " + dog_breed)
            elif dog_age == "adult":
                print("The right pet for you is an adult " + dog_breed)
                
    # Providing a detailed recommendation based on the pet category.
    # There are two cat categories: Domestic longhairs and domestic shorthairs.
    # Longhaired cats need regular grooming; shorthaired cats do not.
    if pet_category == "cat":
        print("Domestic longhairs need regular grooming.")
        print("Domestic shorthairs don't need regular grooming.")
        print("With that in mind, choose a cat category:")
        print("Domestic longhaired or shorthaired.")
        cat_category = input("Please enter longhaired or shorthaired: ")
        cat_category = cat_category.lower().strip()
        # Validating the input to ensure it is accurate.
        while cat_category not in ("longhaired", "shorthaired"):
            cat_category = input("Please enter longhaired or shorthaired: ")
            cat_category = cat_category.lower().strip() 
            
        # Asking about the user's preferred cat's age.
        print("Do you want a senior cat an adult cat, or a kitten? ")
        cat_age = input("Please input your choice here: ").lower().strip()
        # Validating the input to ensure it is accurate.
        while cat_age not in ("senior", "adult", "kitten"):
            cat_age = input("Please enter senior, adult, or kitten: ")
            
        # Final recommendation based on all user inputs.
        if cat_age == "kitten": 
            print("Great! The right pet for you is: ")
            print("A " + cat_category + " kitten!")
        elif cat_age == "senior":
            print("Great! The right pet for you is: ")
            print("A senior " + cat_category + " cat!")
        else:
            print("Great! The right pet for you is: ")
            print("An adult " + cat_category + " cat")
    
    # Providing a detailed recommendation based on the pet category.
    # There are 3 hamster breeds: Syrian, Roborovski, and White Winter Dwarfs.
    # Syrian hamsters are beginner-friendly and companion pets.
    # Roborovskis are observation pets and not beginner-friendly.
    # White Winter Dwarfs are companion pets and not beginner-friendly.
    if pet_category == "hamster":
        # Asking about the user's experience level with hamsters.
        print("Have you owned hamsters before?")
        experienced_owner = input("Please enter yes or no: ").lower().strip()
        # Validating the input to ensure it is accurate.
        while experienced_owner not in ("yes", "no"):
             experienced_owner = input("Please enter yes or no: ")
             experienced_owner = experienced_owner.lower().strip()

        # Asking if the user wants a hamster they can play with (companion)
        # or just watch (observation type).

        print("Do you want an observation or a companion hamster?")
        print("Observation hamsters like Roborovski are just shy and fast. " +
              "Not aggressive at all.")
        interaction_type = input("Please enter companion or observation: ")
        interaction_type = interaction_type.lower().strip()
        # Validating the input to ensure it is accurate.
        while interaction_type not in ("observation", "companion"):
           interaction_type = input("Please enter companion or observation: ")
           interaction_type = interaction_type.lower().strip()
    
        # Choosing the hamster breed for the user.
        hamster_breed = ""
        if experienced_owner == "yes" and interaction_type == "observation":
            hamster_breed = "Roborosvki"
        elif experienced_owner == "no" and interaction_type == "companion":
            hamster_breed = "Syrian"
        elif experienced_owner == "no" and interaction_type == "observation":
            hamster_breed = " White Winter Dwarf"
        elif experienced_owner == "yes" and interaction_type == "companion":
             hamster_breed = "Syrian"
        else: 
            print("We don't have the right hamster for you yet!")

        # Asking about the desired hamster's age.
        hamster_age = ""
        if hamster_breed != "" :
            print("Would you like a pup, an adult, or a senior hamster? ")
            hamster_age = input("Please enter your choice here: ")
            hamster_age = hamster_age.lower().strip()
            # Validating the input to ensure it is accurate.
            while hamster_age not in ("senior", "adult", "pup"):
                hamster_age = input("Please enter senior, adult, or pup: ")
                hamster_age = hamster_age.lower().strip()

        # Final recommendation based on all user inputs.
        if hamster_age == "pup":
            print("Great! The right pet for you is: ")
            print("A " + hamster_breed + " hamster pup!")
        elif hamster_age == "senior":
            print("Great! The right pet for you is: ")
            print ("A senior " + hamster_breed + " hamster!")
        elif hamster_age =="adult": 
            print("Great! The right pet for you is: ")
            print ("An adult " + hamster_breed + " hamster!")
            

    # Ask if the user wants to take the quiz again.
    again = input("Would you like to take the quiz again? yes or no: ")
    again = again.lower().strip()
    if again == "no":
        print("Thanks for visiting Fluffy Friends shelter!")
        break

    
