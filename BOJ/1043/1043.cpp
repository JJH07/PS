// Copyright © 2020 진준호. All rights reserved.

#include <iostream>
#include <vector>

std::vector<int> partyMembers[51], partiesByPerson[51];
bool mustTellTruth[51];

void spreadTruth(int person)
{
    for(int party : partiesByPerson[person])
    {
        if(mustTellTruth[party])
        {
            continue;
        }
        mustTellTruth[party] = true;
        for(int attendee : partyMembers[party])
        {
            spreadTruth(attendee);
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int personCount, partyCount, truthKnowerCount;
    std::cin >> personCount >> partyCount >> truthKnowerCount;
    std::vector<int> truthKnowers(truthKnowerCount);
    for(int &person : truthKnowers)
    {
        std::cin >> person;
    }
    for(int party = 1; party <= partyCount; party++)
    {
        int attendeeCount;
        std::cin >> attendeeCount;
        for(int index = 0; index < attendeeCount; index++)
        {
            int attendee;
            std::cin >> attendee;
            partyMembers[party].push_back(attendee);
            partiesByPerson[attendee].push_back(party);
        }
    }
    for(int person : truthKnowers)
    {
        spreadTruth(person);
    }

    int possibleLieCount = 0;
    for(int party = 1; party <= partyCount; party++)
    {
        if(!mustTellTruth[party])
        {
            possibleLieCount++;
        }
    }
    std::cout << possibleLieCount << '\n';
    return 0;
}
