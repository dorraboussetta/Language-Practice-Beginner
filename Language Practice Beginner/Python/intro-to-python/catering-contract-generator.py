# Catering Contract Generator
# Purpose: Practice using variables, user input, and string concatenation
# This Python program prompts the user to input client and event details 
# and generates a formatted catering contract that outlines the agreement 
# between the client and caterer for the event. 
# The contract includes sections for event details and services provided.


client = input("Enter client name: ")
caterer = input("Enter Caterer name: ")
event_date = input("Enter event date: ")
event_start_time = input("Enter event start time: ")
event_end_time = input("Enter event end time: ")
estimated_number_of_guests = input("Enter estimated number of guests: ")

contract = (
    "This Catering Contract is entered into between"
    + " " + caterer + " ('Caterer') and " + client
    + " ('Client') (together, 'Parties') and sets"
    + " forth the agreement between"
    + " the Parties related to catering services to be"
    + " provided by the Caterer for Client for the event"
    + " identified in this Contract." 
)

print("----------") 

print("Catering Contract (" + caterer + ")")
print("----------")
print(contract)

print(" ")

contract = ("1. Event Details. Client is hiring caterer to provide food "
    + "and beverages, and related services for the following event ('Event'):"
           )
print(contract)
print("-Event date: " + event_date)
print("-Estimated start time (for guests): " + event_start_time )
print("-Estimated end time (for guests): "+ event_end_time)
print("-Estimated number of guests: " + estimated_number_of_guests)

print(" ")
contract= ("2. Menu and services provided. The parties have agreed to the "
    + "menu and services to be provided attached to this Catering Agreement "
    + "as 'Exhibit A'. Caterer reserves the right to make small changes "
    + "to the menu and personnel if key ingredients and duties become " 
    + "unavailable.")
print(contract)
