# Recommender System Using C++
This C++ program implements a simple movie recommendation system using cosine similarity to measure user-user relationships based on their movie ratings.

## How It Works
Generate Random Ratings:

The program initializes random ratings for 75 users and 75 movies(both values can be changed).
Each user is assigned a set of random ratings (0-5).
Cosine Similarity Calculation:

Calculates similarity scores between a target user and all other users.
Uses cosine similarity to measure the closeness of their ratings.
Recommendation Generation:

Identifies movies not rated by the target user.
Recommends movies highly rated by similar users (ratings ≥ 4).

# Features

Randomized User Ratings: Simulates a real-world scenario where users have rated movies on a scale of 0-5.
Cosine Similarity: Measures similarity between users based on their ratings.
Top Recommendations: Suggests highly-rated movies from users with similar preferences.
Customizability:
Easily modify the number of users and movies.
Adjust the threshold for recommending movies (default: rating ≥ 4).

# Limitations

Synthetic Data: Ratings are randomly generated, not from real-world datasets.
Scalability: Designed for small datasets and may not perform well with large-scale data.
Limited Recommendation Criteria: Only considers ratings without additional factors like genres or metadata.

# Potential Improvements

Replace random ratings with real-world data.
Incorporate additional features, such as:
Movie genres, release year, or directors.
Collaborative filtering methods.
Optimize sorting for larger datasets.
