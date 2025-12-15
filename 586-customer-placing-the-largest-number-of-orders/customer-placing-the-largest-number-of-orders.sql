/* Write your T-SQL query statement below */
SELECT customer_number
FROM Orders
GROUP BY customer_number
ORDER BY COUNT(*) DESC
limit 1;