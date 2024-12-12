# Recommender System Using C++
This C++ program implements a simple movie recommendation system using cosine similarity to measure user-user relationships based on their movie ratings.
## How It Works
### Generate Random Ratings:
- Initializes random ratings for 75 users and 75 movies (both values can be modified as needed).
- Each user is assigned a set of random ratings on a scale of 0–5.
### Cosine Similarity Calculation:
- Calculates similarity scores between a target user and all other users.
- Uses cosine similarity to measure the closeness of their ratings.
### Recommendation Generation:
- Identifies movies not rated by the target user.
- Recommends movies highly rated by similar users (ratings ≥ 4).
## Features
- **Randomized User Ratings**: Simulates a real-world scenario where users have rated movies on a scale of 0–5.
- **Cosine Similarity**: Measures similarity between users based on their ratings.
- **Top Recommendations**: Suggests highly-rated movies from users with similar preferences.
- **Customizability**:
  - Easily modify the number of users and movies.
  - Adjust the threshold for recommending movies (default: rating ≥ 4).
## Limitations
- **Synthetic Data**: Ratings are randomly generated, not based on real-world datasets.
- **Scalability**: Designed for small datasets and may not perform efficiently with large-scale data.
- **Limited Recommendation Criteria**: Considers only ratings without other factors like genres, release years, or directors.
## Potential Improvements
- Replace random ratings with real-world data for more meaningful recommendations.
- Add advanced features, such as:
  - Movie genres, release year, or directors as additional inputs.
  - Collaborative filtering techniques for enhanced accuracy.
- Optimize sorting algorithms for scalability with larger datasets.
## Notes
The final version of the program has been refined for improved clarity and maintainability. Redundant code and unnecessary comments from the earlier development stages have been removed, resulting in a more concise and streamlined implementation.
