"""Draws facial features to construct a unique game avatar."""

def draw_bow():
    """Draws a bow, which can be worn as a bowtie or a hair accessory."""
    print("!>o<!")

def draw_eyes(size):
    """Draws eyes of the size "small", "medium", or "large"."""
    if size == "small":
        print(".   .")
    elif size == "medium":
        print("o   o")
    elif size == "large":
        print("O   O")
    else:
        raise ValueError("invalid eye size")

def draw_nose(shape):
    """Draws a nose with the shape "button" or "triangle"."""
    if shape == "button":
        print("  @  ")
    elif shape == "triangle":
        print("  >  ")
    else:
        raise ValueError("invalid nose shape")

def draw_mouth(expression):
    """Draws a mouth with the expression "smile", "neutral", or "teeth"."""
    if expression == "smile":
        print("\\___/")
    elif expression == "neutral":
        print("-----")
    elif expression == "teeth":
        print("(|||)")
    else:
        raise ValueError("invalid mouth expression")
