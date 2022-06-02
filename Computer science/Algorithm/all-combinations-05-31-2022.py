answers = []; answer = []

total_no_of_elements = 2
no_of_elements_to_be_picked = 1
current_index = 0;

def all_combinations(total_no_of_elements, no_of_elements_to_be_picked, current_index):
    # Base case
    if (no_of_elements_to_be_picked == 0):
        answers.append(answer)
        answer.pop()
        return all_combinations(total_no_of_elements, no_of_elements_to_be_picked + 1, current_index)

    answer.append(current_index)
    no_of_elements_to_be_picked -= 1

    current_index += 1

    if current_index != total_no_of_elements - 1:
        return all_combinations(total_no_of_elements, no_of_elements_to_be_picked, current_index)
    else:
        answer.pop()
        
        print(answer[-1])
        current_index = answer[-1]
        return all_combinations(total_no_of_elements, no_of_elements_to_be_picked + 1, current_index)

answers= all_combinations(total_no_of_elements, no_of_elements_to_be_picked, current_index)
print(answers)
