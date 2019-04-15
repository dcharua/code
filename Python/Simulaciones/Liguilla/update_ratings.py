from teams import teams_dictionary
from past_games import *

# Function for updating teams rating based on previous games
def update_ratings(jornada, K):
    for match in jornada:
        team1  = match[0]
        team2  = match[1]
        result = match[2] 
        
        rating1 = teams_dictionary[team1][4]
        rating2 = teams_dictionary[team2][4]

        expected_score_team1 = 1/(1+10**((rating1 - rating2)/400))
        score_update_team1   = K*(result - expected_score_team1)

        # Update ratings for both teams
        teams_dictionary[team1][4] += score_update_team1
        teams_dictionary[team2][4] -= score_update_team1


# Update ratings for all teams based on previous results
def update_all_ratings():
    update_ratings(jornada11_2018,32)
    update_ratings(jornada12_2018,32)
    update_ratings(jornada13_2018,32)
    update_ratings(jornada14_2018,32)
    update_ratings(jornada15_2018,32)
    update_ratings(jornada16_2018,32)
    update_ratings(jornada17_2018,32)
    update_ratings(jornada1, 32)
    update_ratings(jornada2, 32)
    update_ratings(jornada3, 32)
    update_ratings(jornada4, 32)
    update_ratings(jornada5, 32)
    update_ratings(jornada6, 32)
    update_ratings(jornada7, 32)
