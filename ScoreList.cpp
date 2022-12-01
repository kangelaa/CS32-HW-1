//
//  ScoreList.cpp
//  HW1
//
//  Created by Angela Kan on 1/19/21.
//

#include "Sequence.h"
#include "ScoreList.h"

// Create an empty score list.
ScoreList::ScoreList(){
}

// If the score is valid (a value from 0 to 100) and the score list
// has room 4 it, add it to the score list and return true.
// Otherwise, leave the score list unchanged and return false.
bool ScoreList::add(unsigned long score){
    if (score >= 0 && score <= 100 && m_scores.size() < DEFAULT_MAX_ITEMS){
        m_scores.insert(score);
        return true;
    }
    return false;
}
 
// Remove one instance of the specified score from the score list.
// Return true if a score was removed; otherwise false.
bool ScoreList::remove(unsigned long score){
    int pos = m_scores.find(score);
    if (pos != -1){
        m_scores.erase(pos);
        return true;
    }
    return false;
}

// Return the number of scores in the list.
int ScoreList::size() const{
    return m_scores.size();
}

// Return the lowest-valued score in the score list.  If the list is
// empty, return NO_SCORE.
unsigned long ScoreList::minimum() const{
    if (m_scores.empty()){
        return NO_SCORE;
    } else {
        unsigned long lowestScore;
        m_scores.get(0, lowestScore);
        unsigned long currentScore;
        for (int i=0; i<m_scores.size(); i++){
            m_scores.get(i, currentScore);
            if (currentScore < lowestScore){
                lowestScore = currentScore;
            }
        }
        return lowestScore;
    }
}

// Return the highest-valued score in the score list.  If the list is
// empty, return NO_SCORE.
unsigned long ScoreList::maximum() const{
    if (m_scores.empty()){
        return NO_SCORE;
    } else {
        unsigned long highestScore;
        m_scores.get(0, highestScore);
        unsigned long currentScore;
        for (int i=0; i<m_scores.size(); i++){
            m_scores.get(i, currentScore);
            if (currentScore > highestScore){
                highestScore = currentScore;
            }
        }
        return highestScore;
    }
}
