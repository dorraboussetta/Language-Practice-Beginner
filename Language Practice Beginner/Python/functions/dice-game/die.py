"""Simulates a standard 6-sided die roll."""

import random

def roll():
    """Draws and returns a random roll of a six-sided die."""
    die_num = random.randint(1, 6)
    draw(die_num)

    return die_num

def draw(die_num):
    """Prints out an ASCII art representation of a die."""
    print(" ------- ")

    if die_num == 2:
        print("| *     |")
        print("|       |")
        print("|     * |")

    elif die_num == 3:
        print("| *     |")
        print("|   *   |")
        print("|     * |")

    elif die_num == 4:
        print("| *   * |")
        print("|       |")
        print("| *   * |")

    elif die_num == 5:
        print("| *   * |")
        print("|   *   |")
        print("| *   * |")

    elif die_num == 6:
        print("| *   * |")
        print("| *   * |")
        print("| *   * |")

    else:
        print("|       |")
        print("|   *   |")
        print("|       |")

    print(" ------- ")
