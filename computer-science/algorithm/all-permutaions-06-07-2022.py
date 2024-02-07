answers = []
answer = []

def permutation(cities_to_go):
    # base case
    if cities_to_go == []:
        answers.append(answer[:])

    for city in cities_to_go[:]:
        cities_to_go.remove(city)
        answer.append(city)

        permutation(cities_to_go)
        answer.remove(city)
        cities_to_go.append(city)

# Test 1
cities_to_go = ["Jeju", "Daegu"]

# Test 2
cities_to_go = ["Jeju", "Daegu", "Pusan", "Seoul"]

permutation(cities_to_go)

print(len(answers))
print(answers)