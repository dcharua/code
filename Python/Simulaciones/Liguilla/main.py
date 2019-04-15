import operator
from teams import teams_dictionary
from simulate_league import simulate_league
from update_ratings import update_all_ratings

update_all_ratings()
results        = simulate_league(simulation_amount = 50000)
sorted_results = sorted(results.items(), key=operator.itemgetter(1), reverse=True)

for row in sorted_results:
    print(row)
