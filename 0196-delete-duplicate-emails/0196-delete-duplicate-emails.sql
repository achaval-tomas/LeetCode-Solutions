# Write your MySQL query statement below
DELETE c1 FROM Person c1   # Grab person
INNER JOIN Person c2       # Delete all duplicates
WHERE
    c1.id > c2.id AND 
    c1.email = c2.email;