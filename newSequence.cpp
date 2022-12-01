//
//  newSequence.cpp
//  HW1 (dynamically allocated w/ a pointer
//
//  Created by Angela Kan on 1/19/21.
//

#include "newSequence.h"
#include <cstdlib>

// Create an empty sequence (i.e., one with no items)
Sequence::Sequence(int max){
    if (max < 0){
        std::exit(1);
    }
    m_max = max;
    m_size = 0;
    m_seq = new ItemType[max];
}

//Destrutor
Sequence::~Sequence(){
    delete [] m_seq;
}

//Copy constructor
Sequence::Sequence(const Sequence& other){
    m_max = other.m_max;
    m_size = other.m_size;
    m_seq = new ItemType[m_max];
    for (int i=0; i<m_size; i++){
        m_seq[i] = other.m_seq[i];
    }
}

//Assignment operator
Sequence& Sequence::operator=(const Sequence& rhs){
    if (this != &rhs){
        Sequence temp(rhs);
        swap(temp);
    }
    return *this;
}

// Return true if the sequence is empty, otherwise false.
bool Sequence::empty() const{
    if (size() == 0){
        return true;
    } else {
        return false;
    }
}

// Return the number of items in the sequence.
int Sequence::size() const{
    return m_size;
}

// Insert value into the sequence so that it becomes the item at
// position pos.  The original item at position pos and those that
// follow it end up at positions one higher than they were at before.
// Return pos if 0 <= pos <= size() and the value could be
// inserted.  (It might not be, if the sequence has a fixed capacity,
// e.g., because it's implemented using a fixed-size array.)  Otherwise,
// leave the sequence unchanged and return -1.  Notice that
// if pos is equal to size(), the value is inserted at the end.
int Sequence::insert(int pos, const ItemType& value){
    if (pos >= 0 && pos <= size() && pos < m_max){
        if (pos==size()){
            m_seq[pos] = value;
        } else {
            for (int i=size()-1; i>=pos; i--){
                m_seq[i+1] = m_seq[i];
            }
            m_seq[pos] = value;
        }
        m_size++;
        return pos;
    }
    return -1;
}

// Let p be the smallest integer such that value <= the item at
// position p in the sequence; if no such item exists (i.e.,
// value > all items in the sequence), let p be size().  Insert
// value into the sequence so that it becomes the item in position
// p.  The original item at position p and those that follow it end
// up at positions one higher than before.  Return p if the value
// was actually inserted.  Return -1 if the value was not inserted
// (perhaps because the sequence has a fixed capacity and is full).
int Sequence::insert(const ItemType& value){
    if (size() < m_max){
        int p;
        for (p=0; p<size(); p++){
            if (value<=m_seq[p]){
                for (int i=size()-1; i>=p; i--){
                    m_seq[i+1] = m_seq[i];
                }
                m_seq[p] = value;
                m_size++;
                return p;
            }
        }
        p=size();
        m_seq[p] = value;
        m_size++;
        return p;
    }
    return -1;
}

// If 0 <= pos < size(), remove the item at position pos from
// the sequence (so that all items that followed that item end up at
// positions one lower than they were at before), and return true.
// Otherwise, leave the sequence unchanged and return false.
bool Sequence::erase(int pos){
    if (pos >= 0 && pos < size()){
        for (int i=pos; i<size()-1; i++){
            m_seq[i] = m_seq[i+1];
        }
        m_size--;
        return true;
    }
    return false;
}

// Erase all items from the sequence that == value.  Return the
// number of items removed (which will be 0 if no item == value).
int Sequence::remove(const ItemType& value){
    int count = 0;
    
    for (int i=0; i<size(); i++){
        if (m_seq[i] == value){
            for (int j=i; j<size()-1; j++){
                m_seq[j] = m_seq[j+1];
            }
            m_size--;
            count++;
            i--;
        }
    }
    return count;
}

// If 0 <= pos < size(), copy into value the item at position pos
// of the sequence and return true.  Otherwise, leave value unchanged
// and return false.
bool Sequence::get(int pos, ItemType& value) const{
    if (pos >= 0 && pos < size()){
        value = m_seq[pos];
        return true;
    }
    return false;
}

// If 0 <= pos < size(), replace the item at position pos in the
// sequence with value and return true.  Otherwise, leave the sequence
// unchanged and return false.
bool Sequence::set(int pos, const ItemType& value){
    if (pos >= 0 && pos < size()){
        m_seq[pos] = value;
        return true;
    }
    return false;
}

// Let p be the smallest integer such that value == the item at
// position p in the sequence; if no such item exists, let p be -1.
// Return p.
int Sequence::find(const ItemType& value) const{
    int p;
    for (p=0; p<size(); p++){
        if (m_seq[p] == value){
            return p;
        }
    }
    p = -1;
    return p;
}

// Exchange the contents of this sequence with the other one.
void Sequence::swap(Sequence& other){
    int tempMax = m_max;
    m_max = other.m_max;
    other.m_max = tempMax;
    
    int tempSize = size();
    m_size = other.size();
    other.m_size = tempSize;
    
    ItemType* tempPtr = m_seq;
    m_seq = other.m_seq;
    other.m_seq = tempPtr;
}
