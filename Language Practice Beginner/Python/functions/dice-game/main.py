import game

round_count = 0
user_wins_count = 0
computer_wins_count = 0
target_score = game.choose_target_score()

# The game supports playing multiple rounds.
while True:
    round_count += 1

    # Printing the user's turn.
    print("--- Your turn ---")
    user_total = game.play_user_turn(target_score)
    print(">> That's a " + game.get_name(user_total, target_score) + "!")

    # Printing the computer's turn.
    print("--- Computer turn ---")
    computer_total = game.play_computer_turn(user_total, target_score)
    print(">> The computer has a " + 
          game.get_name(computer_total, target_score) + ".")

    # Printing the winner of the current round.
    winner = game.get_round_winner(user_total, computer_total, target_score)
    print(f" Round {round_count}: {winner} wins!")

    # Tallying the winner of each round.
    if winner == "user":
        user_wins_count += 1
    elif winner == "computer":
        computer_wins_count += 1
    
    # Looping the game for another round if desired.
    again = input("Do you want to play another round? Yes/No: ")
    again = again.lower().strip()
    while again not in ("yes", "no"):
        again = input("Please enter yes or no: ").lower().strip()

    if again == "no":
        break 

# Printing the grand winner of the game.
print("----------------------")
print(f"The computer's score: {computer_wins_count}")
print(f"The user's score: {user_wins_count}")
print(game.get_grand_winner(computer_wins_count, user_wins_count))
