"""
Manipulates nucleotide bases in a DNA sequence, abbreviated as three letters.

The bases are Adenine (Ade), Cytosine (Cyt), Guanine (Gua), and Thymine (Thy).
"""

import random

def get_random_base(old_base):
    """Returns a random nucleotide base: Ade, Cyt, Gua, or Thy.
    
    The function is more likely to return a protein of the same 
    type as the old protein."""
    choices = ["Ade", "Gua", "Cyt", "Thy"]
    if old_base in ("Ade", "Gua"):
        weights = [3, 3, 1, 1]
    else: 
        weights = [1, 1, 3, 3]

    return random.choices(choices, weights=weights, k=1)[0]
        
    
    return random.choice(["Ade", "Cyt", "Gua", "Thy"])
