from math import pow
import random

# Calculate probability of teams win, tie, and lose,
# and simulate a game based on these probabilities

# Parameters:
# team1 - Team 1 stats (from dictionary)
# team2 - Team 2 stats (from dictionary)
# canTie - Boolean to define if the game can end in tie or not


# Returns:
# Result of the game
# {1        , 0     , -1       }
# {Team1 Win, Tie   , Team2 Win}
def simulateGame(team1, team2, canTie = True):
    
    # TODO use the ratings to Calculate this probability
    rating1 = team1[4]
    rating2 = team2[4]
    prob_win1  = predict_who_wins(rating1, rating2)
    
    # Fixed tie probability based on results so far for this season
    # 55 / 124
    # This probability only applies if teams have the same rating
    prob_tie  = 0.44
    prob_tie  -= prob_tie*0.5*abs(prob_win1 - 0.5)**(1/3)

    # Rescale P1 win probability
    prob_win1 *= (1-prob_tie)
    

    
    random_value = random.random()
    
    # Tie outcome allowed
    if canTie:
        if random_value < prob_win1:
            return 1
        elif random_value < prob_tie + prob_win1:
            return 0
        else:
            return -1
    
    # Tie not allowed (redistribute winning probabilities proportionally)
    else:
        prob_win1 = prob_win1 /(1- prob_tie)
        if random_value < prob_win1:
            return 1
        else:
            return -1


# Function to return probability of team1 winning based on the ratings
def predict_who_wins(rating1, rating2):
    r = (rating2-rating1)/400
    probability = 1 /(1+pow(10,r))
    return probability
