def all_combinations(total_no_of_elements, no_of_elements_to_be_picked, initial_index):
    # Base case
    if (no_of_elements_to_be_picked == 0):
        answers.append(answer[:])
        return 0

    no_of_elements_to_be_picked -= 1

    for current_index in range(initial_index, total_no_of_elements):
        answer.append(current_index)
        next_index = find_smallest_value(answer)
        all_combinations(total_no_of_elements, no_of_elements_to_be_picked, next_index)
        answer.pop()

def find_smallest_value(answer):
    if answer == []:
        smallest = 0
    else:
        smallest = answer[-1] + 1
    return smallest

answers = []
answer = []
initial_index = 0

print('Enter the total number of elements in integer')
total_no_of_elements = input()
total_no_of_elements = int(total_no_of_elements)

print('Enter the number of elements to be picked integer')
no_of_elements_to_be_picked = input()
no_of_elements_to_be_picked = int(no_of_elements_to_be_picked)

if total_no_of_elements >= no_of_elements_to_be_picked:
    all_combinations(total_no_of_elements, no_of_elements_to_be_picked, initial_index)
    print(answers)
else:
    print('An error occurred')

# TODO: make another abstraction level for this code