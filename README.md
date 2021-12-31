# Simple-Payroll-System
A simple payroll system that calculates gross pay given a set of employees, hours worked for the week, and hourly rate

## Background
This is my work to an assignment from my 1600 CS I class: Creating a simple payroll system in C++, which takes in employee names, number of hours worked, and their hourly rate to compute their gross pay. 

## Test case (The values after the ":" sign is the user input)
> Enter an employee name: Charlie Brown
> Enter an employee name: Lucy van Pelt
> Enter an employee name: Peppermint Patty
> Enter an employee name: quit
> Enter Charlie Brown's hourly pay rate: 25.50
> Enter Lucy van Pelt's hourly pay rate: .05
> Enter Peppermint Patty's hourly pay rate: 19.50
> Enter Charlie Brown's hours for 7 days (0 if day off): 1.5 0 0 0 0 0 3
> Enter Lucy van Pelt's hours for 7 days (0 if day off): 1 0 0 0 0 0 1
> Enter Peppermint Patty's hours for 7 days (0 if day off): 1.5 2.5 3.5 4.5 5.5 6.5 7.5
       > Employee Name Total Hours Gross Pay
       > Charlie Brown        4.50    114.75
       > Lucy van Pelt        2.00      0.10
    > Peppermint Patty       31.50    614.25
> Highest Pay: $614.25 Peppermint Patty
> Lowest Pay: $0.10 Lucy van Pelt


## My Approach
1. I first declared and initialized the two constant variables:
  - <code>SIZE = 999</code>: The maximum number of employees the user can enter into an array
  - <code>NUMDAYS = 7</code>: The number of days in a week
2. I defined the following arrays in my main program:
  - <code>employeeNames[SIZE]</code> for the employee names of each employee
  - <code>hourlyPay[SIZE]</code> for the hourly pay rate of each employee
  - <code>workHours[SIZE][NUMDAYS]</codes> for number of hours each employee works every day
  - <code>grossPay[SIZE]</codes> for the gross pay each employee receives
3. I created four functions:
  - <code>getEmployeeNames(string NameArray[],int MaxSize)</code>: Takes the user's keyboard inputs and store each string inputs into the an array designated for containing employees' name until the user enters "quit". The function also returns the number of the employees entered into the array.
  - <code>getHourlyPay(string NameArray[],double hourlyPayArray[], int NumberOfNamesFilled)</code>: Takes the user's keyboard inputs and store each double inputs into an array designated for containing employees' hourly rates until the hourly rates of all employees are entered. 
  - <code>highestPay(double PayArray[], int NumberOfNamesFilled)</code>: Takes the gross pay array and the number of employees entered to compute the index of the array at which stores the highest pay. 
  - <code>lowestPay(double PayArray[], int NumberOfNamesFilled)</code>: Takes the gross pay array and the number of employees entered to compute the index of the array at which stores the lowest pay. 
 4. In the main program, I declared the int variable <code>numberOfEmployees</code> which stores the number of employees entered by the user. I initialized this variable by calling the <code>getEmployeeNames(string NameArray[],int MaxSize)</code> function with the <code>employeeNames</code> and the <code>SIZE</code> arguments. Calling the function also allows the user to enter all the employees name into the <code>employeeNames</code> array.
 5. I then called the <code>getHourlyPay(string NameArray[],double hourlyPayArray[], int NumberOfNamesFilled)</code> function with the <code>employeeNames</code>, <code>hourlyPay</code>, and <code>numberOfEmployees</code> arguments to enter the hourly rate of all employees entered in the <code>employeeNames</code> array into the <code>hourlyPay</code> array.
 6. I then declared an array <code>totalHours</code> with the size equivalent to the number of employees entered by the user.
 7. I created a nested loop which traverses the <code>employeeName</code> array and the <code>workHours</code> array to enter the number of hours each employee works for each day of the week and add these hours together as the total hours each employee works. After the inner loop ends, I compute the gross pay of each employee by multiplying the said total of hours with the employee's hourly rate.
 8. I then used a for loop to output a table displaying the gross pay each entered employees received.
 9. Finally, i used the simple <code>cout</code> function to output the values in the <code>grossPay> array which is the highest and lowest.

## License
[Apache](https://choosealicense.com/licenses/apache-2.0/)
