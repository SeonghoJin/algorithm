SELECT
  b.author
FROM books b
WHERE
  b.genre = 'Fiction'
GROUP BY
  b.author
HAVING
  COUNT(*) >= 2
  AND AVG(b.user_rating) >= 4.5
  AND AVG(b.reviews) >= (
    SELECT AVG(b1.reviews)
    FROM books b1
    WHERE b1.genre = 'Fiction'
  )
ORDER BY
  b.author;