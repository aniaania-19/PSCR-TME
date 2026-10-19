#pragma once

#include <string>
#include <vector>
#include <forward_list>
#include <utility>
#include <functional>
#include <cassert>

// un mot et son nombre d'occurrences
using WordCount = std::pair<std::string, int>;

// Table de hash dédiée au comptage : associe à chaque mot son nombre d'occurrences.
class FreqMap {
public:
    // Un bucket est une liste simplement chaînée de (mot, compteur).
    using Bucket = std::forward_list<WordCount>;

    // TODO : constructeur prenant le nombre de buckets

    FreqMap(size_t nbuckets=1024):Buckets_(nbuckets),count_(0){
        assert(nbuckets);
    }

    // TODO : size_t size() const
    size_t size() const{
        return count_;

    }
    // TODO : void incrementFrequency(const std::string& word)

    void incrementFrequency(const std::string& word){
        if()
        size_t indx= std::hash<std::string>{}(word) % Buckets_.size();
        for(WordCount &a : Buckets_[indx]){
            if(a.first == word){
                a.second++;
                return;

            }
        }

        Buckets_[indx].push_front(WordCount(word,1));
        count_++;

        if(count_ *10 >= Buckets_.size()*8){
            grow();
        }
    }
    // TODO : std::vector<WordCount> toKeyValuePairs() const

    std::vector<WordCount> toKeyValuePairs()const{
        std::vector<WordCount> result;
        for(size_t i=0;i<Buckets_.size();i++){
            for(const WordCount &a: Buckets_[i]){
                result.emplace_back(a);
            }
        }
        return result;


    }

    // TODO (bonus) : void grow()

    void grow(){
            FreqMap copy=FreqMap(2*Buckets_.size());
            for(size_t i=0;i<Buckets_.size();i++){
            for (const WordCount & a:Buckets_[i]){
                size_t newIndex=std::hash<string>{}(a.first)%copy.size();
                copy[newIndex].emplace_front(a);
            }
        }

            Buckets_ = std::move(copy);

    }

private:
    // TODO : les buckets, et le nombre d'entrées
    std::vector<Bucket> Buckets_;
    size_t count_;

};
