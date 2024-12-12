#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <cmath>
#include <algorithm>

int main() {

    //Defination
    std::vector<std::pair<std::string, std::vector<int>>> user_rating;
    int numberOfUsers = 7;
    int numberOfMovies = 7;
    std::vector<std::string> users;
    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<int> dis(0.0, 5.0); 
    int i=1;
    //Defination ends

    // Data Generation and printing them
    for (int m=1; m<=numberOfUsers;m++){
        
        std::string user = "user" + std::to_string(i);
        users.push_back(user);
        std::vector<int> randomNumbers;
        
        for (int j = 0; j < numberOfMovies; ++j) {randomNumbers.push_back(dis(gen));}

        user_rating.push_back({user,randomNumbers});
        i++;
    }

    // printing the reviews and rating
    for (const auto& pair : user_rating) {
        std::cout << "Name: " << pair.first << ", Ratings: ";
        for (int rating : pair.second) {
            std::cout << rating << " ";
        }
        std::cout << '\n';
    }

    // for (const std::string& str : users) {
    //     std::cout << str << std::endl;
    // }
    // Data Generation and printing end
    
    // User input
    int user_number;
    std::cout << "Enter the user number: ";
    std::cin >> user_number; 
    std::cout << "You entered: " << user_number << std::endl;
    
    // cosine scores
    std::vector<float> users_similarity_score_num;

    //std::vector<std::pair<std::string, std::vector<int>>> user_rating;
    // if(user_rating[0].first == user_name){
    //     std::cout << "Yolo" ;
    // }
    // std::cout<< user_rating[0].first << std::endl;
    // std::cout << "Ratings: ";
    // for (int rating : user_rating[0].second) {
    // std::cout << rating << " ";
    // }
    // std::cout << std::endl;

    // numerator part
    for (size_t i = 0; i < user_rating.size(); ++i) {
    //std::cout << "Name: " << user_rating[i].first << ", Ratings: ";
    int mul;
    int add = 0;
    for (size_t j = 0; j < user_rating[i].second.size(); ++j) {
        mul = user_rating[user_number-1].second[j]*user_rating[i].second[j];
        add = add + mul;
    }
    users_similarity_score_num.push_back(add);
}
    
    //     for (float score : users_similarity_score_num) {
    // std::cout << score << " ";
    // }
    // std::cout << std::endl;

    //denominator part
    std::vector<float> users_similarity_score_dem;
    for (size_t i = 0; i < user_rating.size(); ++i) {
    //std::cout << "Name: " << user_rating[i].first << ", Ratings: ";
    int mul;
    float add = 0;
    for (size_t j = 0; j < user_rating[i].second.size(); ++j) {
        mul = user_rating[i].second[j]*user_rating[i].second[j];
        add = add + mul;
    }
    
    users_similarity_score_dem.push_back(sqrt(add));
}

    // std::cout << "Hello, World Ends here" << std::endl;
    //     for (float score : users_similarity_score_dem) {
    // std::cout << score << " ";
    // }

    std::vector<float> user_similarity_score; // To store similarity scores for the selected user

    float target_user_magnitude = users_similarity_score_dem[user_number - 1]; // Magnitude of the selected user

    for (size_t i = 0; i < users_similarity_score_num.size(); ++i) {
        // Avoid division by zero
        if (target_user_magnitude != 0 && users_similarity_score_dem[i] != 0) {
            float similarity = users_similarity_score_num[i] / (target_user_magnitude * users_similarity_score_dem[i]);
            user_similarity_score.push_back(similarity);
        } else {
            user_similarity_score.push_back(0.0); // If magnitude is zero, similarity is zero
        }
    }

    // Print the similarity scores
    // std::cout << "\nSimilarity Scores:" << std::endl;
    // for (size_t i = 0; i < user_similarity_score.size(); ++i) {
    //     std::cout << "Similarity with " << user_rating[i].first << ": " << user_similarity_score[i] << std::endl;
    // }


    // std::cout << " After decending  "<< std::endl;

    std::vector<int> indices(user_similarity_score.size());
    
    // Initialize indices
    for (int i = 0; i < indices.size(); i++) {
        indices[i] = i;
    }

    // Bubble sort
    for (int i = 0; i < user_similarity_score.size(); i++) {
        for (int j = 0; j < user_similarity_score.size() - i - 1; j++) {
            if (user_similarity_score[j] < user_similarity_score[j + 1]) { // Descending order
                // Swap scores
                float temp = user_similarity_score[j];
                user_similarity_score[j] = user_similarity_score[j + 1];
                user_similarity_score[j + 1] = temp;

                // Swap indices
                int temp_idx = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = temp_idx;
            }
        }
    }

    // Print sorted scores and their original indices
    // std::cout << "Sorted Scores with Original Indices:\n";
    // for (int i = 0; i < user_similarity_score.size(); i++) {
    //     std::cout << "Score: " << user_similarity_score[i] << ", Original Index: " << indices[i] << "\n";
    // }

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
