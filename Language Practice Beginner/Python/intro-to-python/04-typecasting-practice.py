# This program calculates the final price of a cart, applying the best coupon, tax, and shipping costs.
# The purpose of this program was to practice typecasting and handling user input.
# 50% of the original code was provided by the Khan Academy exercise, which included calculating the best discount based on user input.
# My contributions: Added typecasting to convert user input to a float, applied tax, added shipping costs, and formatted the final result.

base_price = float(input("Enter cart total: "))
shipping_costs = float(input("Enter the shipping cost: "))
tax_rate = (float(input(
    "Enter the tax rate (in a decimal form(such as 0.2) : "))  ) 

# Available coupon codes include 15% off and $12.
percent_discount = base_price * 1.15
fixed_discount = base_price - 12

# Pick the coupon that offers the best discount.
final_price = min(fixed_discount, percent_discount) 

# Apply tax and add shipping costs.
final_price = (final_price * (tax_rate +1)) + shipping_costs

final_price = round(final_price, 2) 
print("Your best price is $" + str(final_price)) 

