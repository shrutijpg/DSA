# Write your MySQL query statement below
#select product_name,year,price from product right join sales using(product_id)
select product_name,year,price from Sales LEFT JOIN Product ON Sales.product_id=Product.product_id
