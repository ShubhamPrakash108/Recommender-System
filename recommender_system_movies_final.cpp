#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <cmath>
#include <algorithm>

int main() {
    // User and movie configuration
    std::vector<std::pair<std::string, std::vector<int>>> user_rating;
    int numberOfUsers = 75;
    int numberOfMovies = 75;
    std::vector<std::string> users;
    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<int> dis(0.0, 5.0); 
    int i=1;

    // Generate random ratings for users and movies
    for (int m=1; m<=numberOfUsers; m++){
        std::string user = "user" + std::to_string(i);
        users.push_back(user);
        std::vector<int> randomNumbers;
        
        for (int j = 0; j < numberOfMovies; ++j) {
            randomNumbers.push_back(dis(gen));
        }

        user_rating.push_back({user,randomNumbers});
        i++;
    }

    // Print generated ratings
    for (const auto& pair : user_rating) {
        std::cout << "Name: " << pair.first << ", Ratings: ";
        for (int rating : pair.second) {
            std::cout << rating << " ";
        }
        std::cout << '\n';
    }

    // Get target user for recommendation
    int user_number;
    std::cout << "Enter the user number: ";
    std::cin >> user_number; 
    std::cout << "You entered: " << user_number << std::endl;
    
    // Calculate numerator for similarity scores
    std::vector<float> users_similarity_score_num;
    for (size_t i = 0; i < user_rating.size(); ++i) {
        int add = 0;
        for (size_t j = 0; j < user_rating[i].second.size(); ++j) {
            int mul = user_rating[user_number-1].second[j] * user_rating[i].second[j];
            add = add + mul;
        }
        users_similarity_score_num.push_back(add);
    }

    // Calculate denominator for similarity scores
    std::vector<float> users_similarity_score_dem;
    for (size_t i = 0; i < user_rating.size(); ++i) {
        int mul;
        float add = 0;
        for (size_t j = 0; j < user_rating[i].second.size(); ++j) {
            mul = user_rating[i].second[j] * user_rating[i].second[j];
            add = add + mul;
        }
        
        users_similarity_score_dem.push_back(sqrt(add));
    }

    // Calculate cosine similarity between users
    std::vector<float> user_similarity_score; 
    float target_user_magnitude = users_similarity_score_dem[user_number - 1]; 

    for (size_t i = 0; i < users_similarity_score_num.size(); ++i) {
        if (target_user_magnitude != 0 && users_similarity_score_dem[i] != 0) {
            float similarity = users_similarity_score_num[i] / (target_user_magnitude * users_similarity_score_dem[i]);
            user_similarity_score.push_back(similarity);
        } else {
            user_similarity_score.push_back(0.0); 
        }
    }

    // Sort similarity scores and track indices
    std::vector<int> indices(user_similarity_score.size());
    for (int i = 0; i < indices.size(); i++) {
        indices[i] = i;
    }

    // Bubble sort for similarity scores and indices
    for (int i = 0; i < user_similarity_score.size(); i++) {
        for (int j = 0; j < user_similarity_score.size() - i - 1; j++) {
            if (user_similarity_score[j] < user_similarity_score[j + 1]) { 
                // Swap similarity scores
                float temp = user_similarity_score[j];
                user_similarity_score[j] = user_similarity_score[j + 1];
                user_similarity_score[j + 1] = temp;

                // Swap corresponding indices
                int temp_idx = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = temp_idx;
            }
        }
    }

    // Recommend movies for unrated entries
    std::cout << "_________________________________________________________________"  << '\n';    
    for (size_t j = 0; j < user_rating[user_number - 1].second.size(); ++j) {
        if (user_rating[user_number - 1].second[j] == 0) { 
            bool recommended = false;
            for (size_t i = 1; i < indices.size(); ++i) { 
                if (user_rating[indices[i]].second[j] >= 4) { 
                    std::cout << "Recommended Movie: Movie" << j + 1
                              << " (Rated " << user_rating[indices[i]].second[j]
                              << " by " << user_rating[indices[i]].first << ")\n";
                    recommended = true;
                    break; 
                }
            }
            if (!recommended) {
                std::cout << "No recommendation for Movie" << j + 1 << '\n';
            }
        }
    }

    return 0;
}