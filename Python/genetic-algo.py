#Andrew Broek
import math
import random
def objective_function(individual):
    x = individual["x"]
    y = individual["y"]
    return math.sin(math.sqrt(x ** 2 + y ** 2))

def sort_population_by_fitness(population):
    return sorted(population, key=objective_function)


def select_individual(sorted_population, fitness_sum):
    
    #write your code here
    R=random.random()
    for i in range(len(sorted_population)):
        
        objective_function(individual)/fitness_sum #normalization
        if(objective_function(individual)>=R):
                individual[i]=sorted_population[i]
    return individual

        
def crossover(individual_a, individual_b):

    new_x=individual_a
    new_y=individual_b
    
    ### write your code here
    R=random.randrange(0,len(individual_a))
    for i in range(len(individual_a)):
	    if i<R:
		    new_x[i]=individual_a['x']
		    new_y[i]=individual_b['y']
	    if i>=R:
		    new_x[i]=individual_b['x']
		    new_y=individual_a['y']
			

    return {"x": new_x, "y": new_y}


def mutate(individual):
    
    ### write your code here
	#point mutation 
    R1=random.randrange(0,len(individual))
    R2=random.randrange(0,len(individual))
    
    next_x=individual['x'][R1]
    next_y=individual['x'][R2]
    
    temp=0
    temp=next_x
    next_x=next_y
    next_y=temp
	
		

    return {"x": next_x, "y": next_y}

def make_next_generation(previous_population):
    next_generation = []
    sorted_by_fitness_population = sort_population_by_fitness(previous_population)
    population_size = len(previous_population)
    fitness_sum = sum(objective_function(individual) for individual in population)

    for i in range(population_size):
        first_choice = select_individual(sorted_by_fitness_population, fitness_sum)
        second_choice = select_individual(sorted_by_fitness_population, fitness_sum)

        individual = crossover(first_choice, second_choice)
        individual = mutate(individual)
        next_generation.append(individual)

    return next_generation

def generate_population(size, x_boundaries, y_boundaries):
    lower_x_boundary, upper_x_boundary = x_boundaries
    lower_y_boundary, upper_y_boundary = y_boundaries

    population = []
    for i in range(size):
        individual = {
            "x": random.uniform(lower_x_boundary, upper_x_boundary),
            "y": random.uniform(lower_y_boundary, upper_y_boundary),
        }
        population.append(individual)

    return population

generations = 100

population = generate_population(size=10, x_boundaries=(-4, 4), y_boundaries=(-4, 4))

i = 1
while True:
    print(f"🧬 GENERATION {i}")

    for individual in population:
        print(individual, objective_function(individual))

    if i == generations:
        break

    i += 1

    population = make_next_generation(population)

best_individual = sort_population_by_fitness(population)[-1]
print("\n🔬 FINAL RESULT")
print(best_individual, objective_function(best_individual))
