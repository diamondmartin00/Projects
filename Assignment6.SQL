// Question 1
SELECT customerFN AS "Customer First Name", customerEmail AS "Customer E-mail Address", productName AS "Product Name", unitsInStock + unitsOnOrder AS "Total Units"
FROM customer a, order b, orderLine c, product d
WHERE a.customerID = b.customerID
AND b.orderID = c.orderID
AND c.productCode = d.productCode
WHERE discoutinued= 'N'
ORDER BY "Total Units";

// Question 2
SELECT deptName AS "Department Name", MIN(empHourlyWage) AS "Minimum Hourly Wage", MAX(empHourlyWage) AS "Maximum Hourly Wage"
FROM department a, employee b
WHERE a.deptID = b.deptID
GROUP BY deptName
ORDER BY deptName;

// Question 3
SELECT universityName, ROUND(AVG(univFinalScore),2)
FROM university, univ2meet
WHERE university.universityID = univ2meet.universityID
GROUP BY universityName
HAVING AVG(univFinalScore) > 
    (SELECT AVG(univFinalScore) FROM uni2meet)
ORDER BY AVG(univFinalScore) DESC;