SELECT results
FROM (
    -- Subquery 1: Select the user name with the fewest ratings
    (SELECT u.name AS results
    FROM MovieRating c 
    LEFT JOIN Users u ON c.user_id = u.user_id
    GROUP BY c.user_id
    ORDER BY COUNT(*) desc,u.name
    LIMIT 1)

    UNION ALL

    -- Subquery 2: Select the highest-rated movie within the specified date range
    (SELECT b.title AS results
    FROM MovieRating a
    LEFT JOIN Movies b ON a.movie_id = b.movie_id
    WHERE a.created_at BETWEEN '2020-02-01' AND '2020-02-28'
    GROUP BY a.movie_id
    ORDER BY AVG(a.rating) DESC, b.title ASC
    LIMIT 1)
) AS t;
