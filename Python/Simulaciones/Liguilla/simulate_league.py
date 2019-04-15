from teams import teams_dictionary
from simulateGame import simulateGame
from future_games import *
import copy
import operator
import numpy as np

# Parameters:
# jornada - 2D array of teams playing agains each other this week

# function to simulate a week of games
# Updates teams dictionary

def simulate_jornada(jornada, teams_dictionary2):
    count = 0
    for i in range(9):
        team1 = jornada[count][0]
        team2 = jornada[count][1]
        game_result = simulateGame(teams_dictionary2[team1], teams_dictionary2[team2], True)
        count+=1
        if(game_result == 1):
            teams_dictionary2[team1][0]+=1
            teams_dictionary2[team1][3] += 3
            teams_dictionary2[team2][2]+=1
        elif (game_result == 0):
            teams_dictionary2[team1][1] +=1
            teams_dictionary2[team1][3] += 1
            teams_dictionary2[team2][1] +=1
            teams_dictionary2[team2][3] += 1
        else:
            teams_dictionary2[team2][0] +=1
            teams_dictionary2[team2][3] += 3
            teams_dictionary2[team1][2] +=1


def sort_teams(teams_dictionary2):
    
    # Dictionary for storing points only
    points_dict = {
    "Monterrey": 0,
    "Tigres":    0,
    "Leon":      0,
    "Chivas":    0,
    "Necaxa":    0,
    "Santos":    0,
    "Pachuca":   0,
    "Xolos":     0,
    "Atlas":     0,
    "Lobos":     0,
    "America":   0,
    "Pumas":     0,
    "Puebla":    0,
    "Cruz Azul": 0,
    "Toluca":    0,
    "Monarcas":  0,
    "Tiburones": 0,
    "Queretaro": 0
    }
    
    # Set value of points in this new dictionary
    for key in teams_dictionary2:
        points_dict[key] = teams_dictionary2[key][3]
    sorted_dict = sorted(points_dict.items(), key=operator.itemgetter(1), reverse=True)
    
    # Return top 8 teams 
    return sorted_dict[0:8]


def simulate_playoffs(qualified_teams, teams_dictionary2):

    # booleans for remaining teams
    remaining_teams = [True]*len(qualified_teams)

    # Iterate quarters, semis, and finals
    for i in range(3):
        
        # Keep track of lowest remaining index for this round
        lowest_rem_index = len(qualified_teams)-1
        
        # Iterate best remaining teams (4, 2, 1)
        for j in range(len(qualified_teams)):
            
            
            # Top remaining team
            if remaining_teams[j]:
                
                # Iterate worst teams (4, 2, 1)
                for k in range(lowest_rem_index, j, -1):
                    
                    if remaining_teams[k]:
                        lowest_rem_index = k-1          # Update lowest remaining index
                        team1 = qualified_teams[j][0]
                        team2 = qualified_teams[k][0]
                        
                        game_result = simulateGame(teams_dictionary2[team1], teams_dictionary2[team2], False)
                        
                        # Team 1 won
                        if game_result == 1:
                            remaining_teams[k] = False
                        
                        # Team 2 won
                        else:
                            remaining_teams[j] = False
                        
                        break
        
    # return champion
    for i in range(len(remaining_teams)):
        if remaining_teams[i]:
            return qualified_teams[i][0]
    
def simulate_league(simulation_amount = 1):
    
    # Dictionary for storing wins for each team
    victory_dict = {
        "Monterrey": 0,
        "Tigres":    0,
        "Leon":      0,
        "Chivas":    0,
        "Necaxa":    0,
        "Santos":    0,
        "Pachuca":   0,
        "Xolos":     0,
        "Atlas":     0,
        "Lobos":     0,
        "America":   0,
        "Pumas":     0,
        "Puebla":    0,
        "Cruz Azul": 0,
        "Toluca":    0,
        "Monarcas":  0,
        "Tiburones": 0,
        "Queretaro": 0
        }

    for i in range(simulation_amount):
        teams_dictionary2 = copy.deepcopy(teams_dictionary)
        simulate_jornada(jornada8, teams_dictionary2)
        simulate_jornada(jornada9, teams_dictionary2)
        simulate_jornada(jornada10, teams_dictionary2)
        simulate_jornada(jornada11, teams_dictionary2)
        simulate_jornada(jornada12, teams_dictionary2)
        simulate_jornada(jornada13, teams_dictionary2)
        simulate_jornada(jornada14, teams_dictionary2)
        simulate_jornada(jornada15, teams_dictionary2)
        simulate_jornada(jornada16, teams_dictionary2)
        simulate_jornada(jornada17, teams_dictionary2)
        
        qualified_teams = sort_teams(teams_dictionary2)
        team = simulate_playoffs(qualified_teams, teams_dictionary2)
        victory_dict[team] += 1
    
    # Divide by number of simulations to get probabilities
    for team in victory_dict:
        victory_dict[team] *= 1/simulation_amount
    return victory_dict
