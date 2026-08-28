class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize)
    {
        map<int, int> cards;
        for(auto card : hand)
        {
            cards[card] += 1;
        }

        while (!cards.empty()) {
            // get first val
            auto it = cards.begin();
            int val = it->first;
            // make the group size
            for (int i = 0; i < groupSize; i++) {
                
                if (cards.count(val + i)) { // check if val exist and if so, decrement/remove
                    cards[val + i]--;
                    if (cards[val + i] == 0) 
                        cards.erase(val + i);
                }
                else {
                    return false;
                }
            }
        }

        return true;
        // map<int, int> cards;
        // for(auto card : hand)
        // {
        //     cards[card] += 1;
        // }
 
        // for(int i = 0; i < hand.size() / groupSize; i++)
        // {
        //     // iterating thru map
        //     int card_count = 0;
        //     auto it = cards.begin();
 
        //     int val = it->first;
        //     cards[val] -= 1;
        //     if(cards[val] == 0)
        //     {
        //         cards.erase(val);
        //     }

        //     for(card_count = 1; card_count < groupSize; card_count++)
        //     {
        //         val += 1;
        //         if(!cards.count(val))
        //         {
        //             return false;
        //         }
 
        //         cards[val] -= 1;
        //         if(cards[val] == 0)
        //         {
        //             cards.erase(val);
        //         }
        //     }
        // }
        // return true;
    }
};