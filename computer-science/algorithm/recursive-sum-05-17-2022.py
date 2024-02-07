def recursive_sum(number):
    if (number == 1): # base case
        return 1
    return recursive_sum(number - 1) + number

num_string = input()
num = int(num_string)

print(recursive_sum(num))