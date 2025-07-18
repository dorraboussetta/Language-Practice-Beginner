import dna
import random

bases = ["Gua", "Cyt", "Thy", "Gua", "Ade", "Cyt", "Gua", "Thy"]
print(bases)
num_mutations = random.randint(1, 3)

# Randomly mutate some number of bases in the DNA sequence.
# The first and last 2 bases are more likely to mutate than the middle ones.
weights = [2, 2, 1, 1, 1, 1, 2, 2]
positions = [0, 1, 2, 3, 4, 5, 6, 7]
for mutation in range(num_mutations):
    base_position = random.choices(positions, weights=weights, k=1)[0]
    old_base = bases[base_position]
    new_base = dna.get_weighted_random_base(old_base)

    # Making sure that a base is replaced with a different base.
    while old_base == new_base:
        new_base = dna.get_weighted_random_base(old_base)

    bases[base_position] = new_base

print(bases)
