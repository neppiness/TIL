answers = []

def all_combinations(total_no_of_elements, no_of_elements_to_be_picked):
    if (no_of_elements_to_be_picked == 0):
        return 0
    no_of_elements_to_be_picked -= 1
    return all_combinations(total_no_of_elements, no_of_elements_to_be_picked)