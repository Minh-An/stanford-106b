#include <cstdio>
#include <iostream>
#include "random.h"


enum trialStateT {INVALID, VALID};

int SimulateVoterSpread(int a_voters, int b_voters, double voting_error)
{
    int voter_spread = b_voters - a_voters;
    for(int i = 0; i < a_voters; i++)
    {
        if(randomChance(voting_error))
        {
            voter_spread += 2;
        }
    }
    for(int i = 0; i < b_voters; i++)
    {
        if(randomChance(voting_error))
        {
            voter_spread -= 2;
        }
    }
    return voter_spread;
}

trialStateT SimulateElectionTrial(int num_voters, double candidate_spread, double voting_error)
{
    int a_voters = num_voters   (.5+candidate_spread/2);
    int b_voters = num_voters   (.5-candidate_spread/2);

    int voter_spread = SimulateVoterSpread(a_voters, b_voters, voting_error);

    return (voter_spread > 0) ? trialStateT::INVALID : trialStateT::VALID;
}

int main()
{
    int num_voters; double candidate_spread; double voting_error;

    printf("Enter number of voters: ");
    std::cin >> num_voters;
    printf("Enter percentage spread between candidates: ");
    std::cin >> candidate_spread;
    printf("Enter voting error percentage: ");
    std::cin >> voting_error;

    int num_trials = 100000;
    int invalid_trials = 0; 
    for(int i = 1; i <= num_trials; i++)
    {
        if(SimulateElectionTrial(num_voters, candidate_spread, voting_error) == trialStateT::INVALID)
            invalid_trials++;
    }

    double invalid_percentage = (double)invalid_trials/num_trials   100;
    printf("Chance of an invalid election result after %d trials = %.1f% \n", num_trials, invalid_percentage);
}