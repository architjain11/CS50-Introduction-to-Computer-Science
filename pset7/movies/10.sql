SELECT name FROM people JOIN (ratings JOIN (movies JOIN directors ON movies.id = directors.movie_id) ON movies.id = ratings.movie_id) ON directors.person_id = people.id WHERE ratings.rating >= 9;